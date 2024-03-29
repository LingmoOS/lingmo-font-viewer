/* -*- mode: C; c-basic-offset: 4 -*- */
/*
 * font-thumbnailer: a thumbnailer for font files, using FreeType
 *
 * Copyright (C) 2002-2003  James Henstridge <james@daa.com.au>
 * Copyright (C) 2012 Cosimo Cecchi <cosimoc@lingmo.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include <config.h>

#include <stdio.h>
#include <locale.h>
#include <ft2build.h>
#include <math.h>
#include FT_FREETYPE_H

#include <gdk/gdk.h>
#include <gdk-pixbuf/gdk-pixbuf.h>
#include <gio/gio.h>
#include <glib/gi18n.h>

#include <cairo/cairo-ft.h>

#include "sushi-font-loader.h"
#include "totem-resources.h"

static const gchar *
get_ft_error (FT_Error error)
{
#undef __FTERRORS_H__
#define FT_ERRORDEF(e,v,s) case e: return s;
#define FT_ERROR_START_LIST
#define FT_ERROR_END_LIST
    switch (error) {
#include FT_ERRORS_H
    default:
        return "unknown";
    }
}

#define THUMB_SIZE 128
#define PADDING_VERTICAL 2
#define PADDING_HORIZONTAL 4

static gboolean
check_font_contain_text (FT_Face face,
                         const gchar *text)
{
    g_autofree gunichar *string = NULL;
    glong len, map;

    string = g_utf8_to_ucs4_fast (text, -1, &len);

    for (map = 0; map < face->num_charmaps; map++) {
        gboolean res = TRUE;
        FT_CharMap charmap = face->charmaps[map];
        gint idx;

        FT_Set_Charmap (face, charmap);

        for (idx = 0; idx < len; idx++) {
            gunichar c = string[idx];

            if (!FT_Get_Char_Index (face, c)) {
                res = FALSE;
                break;
            }
        }

        if (res)
            return TRUE;
    }

    return FALSE;
}

static gchar *
check_for_ascii_glyph_numbers (FT_Face face,
                               gboolean *found_ascii)
{
    g_autoptr(GString) ascii_string = NULL, string = NULL;
    gulong c;
    guint glyph, found = 0;

    string = g_string_new (NULL);
    ascii_string = g_string_new (NULL);
    *found_ascii = FALSE;

    c = FT_Get_First_Char (face, &glyph);

    do {
        if (glyph == 65 || glyph == 97) {
            g_string_append_unichar (ascii_string, (gunichar) c);
            found++;
        }

        if (found == 2)
            break;

        g_string_append_unichar (string, (gunichar) c);
        c = FT_Get_Next_Char (face, c, &glyph);
    } while (glyph != 0);

    if (found == 2) {
        *found_ascii = TRUE;
        return g_strdup (ascii_string->str);
    } else {
        return g_strdup (string->str);
    }
}

static gchar *
build_fallback_thumbstr (FT_Face face)
{
    g_autoptr(GString) retval = NULL;
    g_autofree gchar *chars = NULL;
    gint idx, total_chars;
    gchar *ptr, *end;
    gboolean found_ascii;

    chars = check_for_ascii_glyph_numbers (face, &found_ascii);
    if (found_ascii)
        return g_steal_pointer (&chars);

    idx = 0;
    retval = g_string_new (NULL);
    total_chars = g_utf8_strlen (chars, -1);

    while (idx < 2) {
        total_chars = (gint) floor (total_chars / 2.0);
        ptr = g_utf8_offset_to_pointer (chars, total_chars);
        end = g_utf8_find_next_char (ptr, NULL);

        g_string_append_len (retval, ptr, end - ptr);
        idx++;
    }

    return g_strdup (retval->str);
}

int
main (int argc,
      char **argv)
{
    g_autoptr(GError) gerror = NULL;
    g_autoptr(GFile) file = NULL;
    g_autoptr(GOptionContext) context = NULL;
    g_autofree gchar *contents = NULL, *help = NULL, *str = NULL, *uri = NULL;
    g_auto(GStrv) arguments = NULL;
    FT_Error error;
    FT_Library library;
    FT_Face face;
    gint font_size, thumb_size = THUMB_SIZE;
    gchar *thumbstr_utf8 = NULL;
    gboolean retval, default_thumbstr = TRUE;
    GdkRGBA black = { 0.0, 0.0, 0.0, 1.0 };
    cairo_surface_t *surface;
    cairo_t *cr;
    cairo_text_extents_t text_extents;
    cairo_font_face_t *font;
    gdouble scale, scale_x, scale_y;
    gint face_index = 0;
    gchar *fragment;

    const GOptionEntry options[] = {
            { "text", 't', 0, G_OPTION_ARG_STRING, &thumbstr_utf8,
              N_("Text to thumbnail (default: Aa)"), N_("TEXT") },
            { "size", 's', 0, G_OPTION_ARG_INT, &thumb_size,
              N_("Thumbnail size (default: 128)"), N_("SIZE") },
            { G_OPTION_REMAINING, 0, 0, G_OPTION_ARG_FILENAME_ARRAY, &arguments,
              NULL, N_("FONT-FILE OUTPUT-FILE") },
            { NULL }
    };

    bindtextdomain (GETTEXT_PACKAGE, LingmoLOCALEDIR);
    bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
    textdomain (GETTEXT_PACKAGE);

    setlocale (LC_ALL, "");

    context = g_option_context_new (NULL);
    g_option_context_add_main_entries (context, options, GETTEXT_PACKAGE);

    retval = g_option_context_parse (context, &argc, &argv, &gerror);
    if (!retval) {
        g_printerr ("Error parsing arguments: %s\n", gerror->message);
        return 1;
    }

    if (!arguments || g_strv_length (arguments) != 2) {
        help = g_option_context_get_help (context, TRUE, NULL);
        g_printerr ("%s", help);
        return 1;
    }

    if (thumbstr_utf8 != NULL)
        default_thumbstr = FALSE;

    error = FT_Init_FreeType (&library);
    if (error) {
        g_printerr ("Could not initialise freetype: %s\n", get_ft_error (error));
        return 1;
    }

    totem_resources_monitor_start (arguments[0], 30 * G_USEC_PER_SEC);

    fragment = strrchr (arguments[0], '#');
    if (fragment)
        face_index = strtol (fragment + 1, NULL, 0);

    file = g_file_new_for_commandline_arg (arguments[0]);
    uri = g_file_get_uri (file);

    face = sushi_new_ft_face_from_uri (library, uri, face_index, &contents, &gerror);
    if (gerror) {
        g_printerr ("Could not load face '%s': %s\n", uri, gerror->message);
        return 1;
    }

    if (default_thumbstr) {
        if (check_font_contain_text (face, "Aa"))
            str = g_strdup ("Aa");
        else
            str = build_fallback_thumbstr (face);
    } else {
        str = thumbstr_utf8;
    }

    surface = cairo_image_surface_create (CAIRO_FORMAT_ARGB32,
                                          thumb_size, thumb_size);
    cr = cairo_create (surface);

    font = cairo_ft_font_face_create_for_ft_face (face, 0);
    cairo_set_font_face (cr, font);
    cairo_font_face_destroy (font);

    font_size = thumb_size - 2 * PADDING_VERTICAL;
    cairo_set_font_size (cr, font_size);
    cairo_text_extents (cr, str, &text_extents);

    if ((text_extents.width) > (thumb_size - 2 * PADDING_HORIZONTAL)) {
        scale_x = (gdouble) (thumb_size - 2 * PADDING_HORIZONTAL) / (text_extents.width);
    } else {
        scale_x = 1.0;
    }

    if ((text_extents.height) > (thumb_size - 2 * PADDING_VERTICAL)) {
        scale_y = (gdouble) (thumb_size - 2 * PADDING_VERTICAL) / (text_extents.height);
    } else {
        scale_y = 1.0;
    }

    scale = MIN (scale_x, scale_y);
    cairo_scale (cr, scale, scale);
    cairo_translate (cr, 
                     PADDING_HORIZONTAL - text_extents.x_bearing + (thumb_size - scale * text_extents.width) / 2.0,
                     PADDING_VERTICAL - text_extents.y_bearing + (thumb_size - scale * text_extents.height) / 2.0);

    gdk_cairo_set_source_rgba (cr, &black);
    cairo_show_text (cr, str);
    cairo_destroy (cr);

    cairo_surface_write_to_png (surface, arguments[1]);
    cairo_surface_destroy (surface);

    totem_resources_monitor_stop ();

    error = FT_Done_Face (face);
    if (error) {
        g_printerr ("Could not unload face: %s\n", get_ft_error (error));
        return 1;
    }

    error = FT_Done_FreeType (library);
    if (error) {
        g_printerr ("Could not finalize freetype library: %s\n", get_ft_error (error));
        return 1;
    }

    /* success */
    return 0;
}
