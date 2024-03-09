/* Registered OpenType layout tags, see
 * https://www.microsoft.com/typography/otspec/featuretags.htm
 */

typedef struct {
  unsigned int tag;
  const char *name;
} NamedTag;

#define MAKE_TAG(a,b,c,d) (unsigned int)(((a) << 24) | ((b) << 16) | ((c) <<  8) | (d))

static NamedTag open_type_layout_features[] = {
  { MAKE_TAG('a','a','l','t'), NC_("OpenType layout", "Access All Alternates") },
  { MAKE_TAG('a','b','v','f'), NC_("OpenType layout", "Above-base Forms") },
  { MAKE_TAG('a','b','v','m'), NC_("OpenType layout", "Above-base Mark Positioning") },
  { MAKE_TAG('a','b','v','s'), NC_("OpenType layout", "Above-base Substitutions") },
  { MAKE_TAG('a','f','r','c'), NC_("OpenType layout", "Alternative Fractions") },
  { MAKE_TAG('a','k','h','n'), NC_("OpenType layout", "Akhands") },
  { MAKE_TAG('b','l','w','f'), NC_("OpenType layout", "Below-base Forms") },
  { MAKE_TAG('b','l','w','m'), NC_("OpenType layout", "Below-base Mark Positioning") },
  { MAKE_TAG('b','l','w','s'), NC_("OpenType layout", "Below-base Substitutions") },
  { MAKE_TAG('c','a','l','t'), NC_("OpenType layout", "Contextual Alternates") },
  { MAKE_TAG('c','a','s','e'), NC_("OpenType layout", "Case-Sensitive Forms") },
  { MAKE_TAG('c','c','m','p'), NC_("OpenType layout", "Glyph Composition / Decomposition") },
  { MAKE_TAG('c','f','a','r'), NC_("OpenType layout", "Conjunct Form After Ro") },
  { MAKE_TAG('c','j','c','t'), NC_("OpenType layout", "Conjunct Forms") },
  { MAKE_TAG('c','l','i','g'), NC_("OpenType layout", "Contextual Ligatures") },
  { MAKE_TAG('c','p','c','t'), NC_("OpenType layout", "Centered CJK Punctuation") },
  { MAKE_TAG('c','p','s','p'), NC_("OpenType layout", "Capital Spacing") },
  { MAKE_TAG('c','s','w','h'), NC_("OpenType layout", "Contextual Swash") },
  { MAKE_TAG('c','u','r','s'), NC_("OpenType layout", "Cursive Positioning") },
  { MAKE_TAG('c','2','p','c'), NC_("OpenType layout", "Petite Capitals From Capitals") },
  { MAKE_TAG('c','2','s','c'), NC_("OpenType layout", "Small Capitals From Capitals") },
  { MAKE_TAG('c','v','0','1'), NC_("OpenType layout", "Character Variation 1") },
  { MAKE_TAG('c','v','0','2'), NC_("OpenType layout", "Character Variation 2") },
  { MAKE_TAG('c','v','0','3'), NC_("OpenType layout", "Character Variation 3") },
  { MAKE_TAG('c','v','0','4'), NC_("OpenType layout", "Character Variation 4") },
  { MAKE_TAG('c','v','0','5'), NC_("OpenType layout", "Character Variation 5") },
  { MAKE_TAG('c','v','0','6'), NC_("OpenType layout", "Character Variation 6") },
  { MAKE_TAG('c','v','0','7'), NC_("OpenType layout", "Character Variation 7") },
  { MAKE_TAG('c','v','0','8'), NC_("OpenType layout", "Character Variation 8") },
  { MAKE_TAG('c','v','0','9'), NC_("OpenType layout", "Character Variation 9") },
  { MAKE_TAG('c','v','1','0'), NC_("OpenType layout", "Character Variation 10") },
  { MAKE_TAG('c','v','1','1'), NC_("OpenType layout", "Character Variation 11") },
  { MAKE_TAG('c','v','1','2'), NC_("OpenType layout", "Character Variation 12") },
  { MAKE_TAG('c','v','1','3'), NC_("OpenType layout", "Character Variation 13") },
  { MAKE_TAG('c','v','1','4'), NC_("OpenType layout", "Character Variation 14") },
  { MAKE_TAG('c','v','1','5'), NC_("OpenType layout", "Character Variation 15") },
  { MAKE_TAG('c','v','1','6'), NC_("OpenType layout", "Character Variation 16") },
  { MAKE_TAG('c','v','1','7'), NC_("OpenType layout", "Character Variation 17") },
  { MAKE_TAG('c','v','1','8'), NC_("OpenType layout", "Character Variation 18") },
  { MAKE_TAG('c','v','1','9'), NC_("OpenType layout", "Character Variation 19") },
  { MAKE_TAG('d','i','s','t'), NC_("OpenType layout", "Distances") },
  { MAKE_TAG('d','l','i','g'), NC_("OpenType layout", "Discretionary Ligatures") },
  { MAKE_TAG('d','n','o','m'), NC_("OpenType layout", "Denominators") },
  { MAKE_TAG('d','t','l','s'), NC_("OpenType layout", "Dotless Forms") },
  { MAKE_TAG('e','x','p','t'), NC_("OpenType layout", "Expert Forms") },
  { MAKE_TAG('f','a','l','t'), NC_("OpenType layout", "Final Glyph on Line Alternates") },
  { MAKE_TAG('f','i','n','2'), NC_("OpenType layout", "Terminal Forms #2") },
  { MAKE_TAG('f','i','n','3'), NC_("OpenType layout", "Terminal Forms #3") },
  { MAKE_TAG('f','i','n','a'), NC_("OpenType layout", "Terminal Forms") },
  { MAKE_TAG('f','l','a','c'), NC_("OpenType layout", "Flattened accent forms") },
  { MAKE_TAG('f','r','a','c'), NC_("OpenType layout", "Fractions") },
  { MAKE_TAG('f','w','i','d'), NC_("OpenType layout", "Full Widths") },
  { MAKE_TAG('h','a','l','f'), NC_("OpenType layout", "Half Forms") },
  { MAKE_TAG('h','a','l','n'), NC_("OpenType layout", "Halant Forms") },
  { MAKE_TAG('h','a','l','t'), NC_("OpenType layout", "Alternate Half Widths") },
  { MAKE_TAG('h','i','s','t'), NC_("OpenType layout", "Historical Forms") },
  { MAKE_TAG('h','k','n','a'), NC_("OpenType layout", "Horizontal Kana Alternates") },
  { MAKE_TAG('h','l','i','g'), NC_("OpenType layout", "Historical Ligatures") },
  { MAKE_TAG('h','n','g','l'), NC_("OpenType layout", "Hangul") },
  { MAKE_TAG('h','o','j','o'), NC_("OpenType layout", "Hojo Kanji Forms") },
  { MAKE_TAG('h','w','i','d'), NC_("OpenType layout", "Half Widths") },
  { MAKE_TAG('i','n','i','t'), NC_("OpenType layout", "Initial Forms") },
  { MAKE_TAG('i','s','o','l'), NC_("OpenType layout", "Isolated Forms") },
  { MAKE_TAG('i','t','a','l'), NC_("OpenType layout", "Italics") },
  { MAKE_TAG('j','a','l','t'), NC_("OpenType layout", "Justification Alternates") },
  { MAKE_TAG('j','p','7','8'), NC_("OpenType layout", "JIS78 Forms") },
  { MAKE_TAG('j','p','8','3'), NC_("OpenType layout", "JIS83 Forms") },
  { MAKE_TAG('j','p','9','0'), NC_("OpenType layout", "JIS90 Forms") },
  { MAKE_TAG('j','p','0','4'), NC_("OpenType layout", "JIS2004 Forms") },
  { MAKE_TAG('k','e','r','n'), NC_("OpenType layout", "Kerning") },
  { MAKE_TAG('l','f','b','d'), NC_("OpenType layout", "Left Bounds") },
  { MAKE_TAG('l','i','g','a'), NC_("OpenType layout", "Standard Ligatures") },
  { MAKE_TAG('l','j','m','o'), NC_("OpenType layout", "Leading Jamo Forms") },
  { MAKE_TAG('l','n','u','m'), NC_("OpenType layout", "Lining Figures") },
  { MAKE_TAG('l','o','c','l'), NC_("OpenType layout", "Localized Forms") },
  { MAKE_TAG('l','t','r','a'), NC_("OpenType layout", "Left-to-right alternates") },
  { MAKE_TAG('l','t','r','m'), NC_("OpenType layout", "Left-to-right mirrored forms") },
  { MAKE_TAG('m','a','r','k'), NC_("OpenType layout", "Mark Positioning") },
  { MAKE_TAG('m','e','d','2'), NC_("OpenType layout", "Medial Forms #2") },
  { MAKE_TAG('m','e','d','i'), NC_("OpenType layout", "Medial Forms") },
  { MAKE_TAG('m','g','r','k'), NC_("OpenType layout", "Mathematical Greek") },
  { MAKE_TAG('m','k','m','k'), NC_("OpenType layout", "Mark to Mark Positioning") },
  { MAKE_TAG('m','s','e','t'), NC_("OpenType layout", "Mark Positioning via Substitution") },
  { MAKE_TAG('n','a','l','t'), NC_("OpenType layout", "Alternate Annotation Forms") },
  { MAKE_TAG('n','l','c','k'), NC_("OpenType layout", "NLC Kanji Forms") },
  { MAKE_TAG('n','u','k','t'), NC_("OpenType layout", "Nukta Forms") },
  { MAKE_TAG('n','u','m','r'), NC_("OpenType layout", "Numerators") },
  { MAKE_TAG('o','n','u','m'), NC_("OpenType layout", "Oldstyle Figures") },
  { MAKE_TAG('o','p','b','d'), NC_("OpenType layout", "Optical Bounds") },
  { MAKE_TAG('o','r','d','n'), NC_("OpenType layout", "Ordinals") },
  { MAKE_TAG('o','r','n','m'), NC_("OpenType layout", "Ornaments") },
  { MAKE_TAG('p','a','l','t'), NC_("OpenType layout", "Proportional Alternate Widths") },
  { MAKE_TAG('p','c','a','p'), NC_("OpenType layout", "Petite Capitals") },
  { MAKE_TAG('p','k','n','a'), NC_("OpenType layout", "Proportional Kana") },
  { MAKE_TAG('p','n','u','m'), NC_("OpenType layout", "Proportional Figures") },
  { MAKE_TAG('p','r','e','f'), NC_("OpenType layout", "Pre-Base Forms") },
  { MAKE_TAG('p','r','e','s'), NC_("OpenType layout", "Pre-base Substitutions") },
  { MAKE_TAG('p','s','t','f'), NC_("OpenType layout", "Post-base Forms") },
  { MAKE_TAG('p','s','t','s'), NC_("OpenType layout", "Post-base Substitutions") },
  { MAKE_TAG('p','w','i','d'), NC_("OpenType layout", "Proportional Widths") },
  { MAKE_TAG('q','w','i','d'), NC_("OpenType layout", "Quarter Widths") },
  { MAKE_TAG('r','a','n','d'), NC_("OpenType layout", "Randomize") },
  { MAKE_TAG('r','c','l','t'), NC_("OpenType layout", "Required Contextual Alternates") },
  { MAKE_TAG('r','k','r','f'), NC_("OpenType layout", "Rakar Forms") },
  { MAKE_TAG('r','l','i','g'), NC_("OpenType layout", "Required Ligatures") },
  { MAKE_TAG('r','p','h','f'), NC_("OpenType layout", "Reph Forms") },
  { MAKE_TAG('r','t','b','d'), NC_("OpenType layout", "Right Bounds") },
  { MAKE_TAG('r','t','l','a'), NC_("OpenType layout", "Right-to-left alternates") },
  { MAKE_TAG('r','t','l','m'), NC_("OpenType layout", "Right-to-left mirrored forms") },
  { MAKE_TAG('r','u','b','y'), NC_("OpenType layout", "Ruby Notation Forms") },
  { MAKE_TAG('r','v','r','n'), NC_("OpenType layout", "Required Variation Alternates") },
  { MAKE_TAG('s','a','l','t'), NC_("OpenType layout", "Stylistic Alternates") },
  { MAKE_TAG('s','i','n','f'), NC_("OpenType layout", "Scientific Inferiors") },
  { MAKE_TAG('s','i','z','e'), NC_("OpenType layout", "Optical size") },
  { MAKE_TAG('s','m','c','p'), NC_("OpenType layout", "Small Capitals") },
  { MAKE_TAG('s','m','p','l'), NC_("OpenType layout", "Simplified Forms") },
  { MAKE_TAG('s','s','0','1'), NC_("OpenType layout", "Stylistic Set 1") },
  { MAKE_TAG('s','s','0','2'), NC_("OpenType layout", "Stylistic Set 2") },
  { MAKE_TAG('s','s','0','3'), NC_("OpenType layout", "Stylistic Set 3") },
  { MAKE_TAG('s','s','0','4'), NC_("OpenType layout", "Stylistic Set 4") },
  { MAKE_TAG('s','s','0','5'), NC_("OpenType layout", "Stylistic Set 5") },
  { MAKE_TAG('s','s','0','6'), NC_("OpenType layout", "Stylistic Set 6") },
  { MAKE_TAG('s','s','0','7'), NC_("OpenType layout", "Stylistic Set 7") },
  { MAKE_TAG('s','s','0','8'), NC_("OpenType layout", "Stylistic Set 8") },
  { MAKE_TAG('s','s','0','9'), NC_("OpenType layout", "Stylistic Set 9") },
  { MAKE_TAG('s','s','1','0'), NC_("OpenType layout", "Stylistic Set 10") },
  { MAKE_TAG('s','s','1','1'), NC_("OpenType layout", "Stylistic Set 11") },
  { MAKE_TAG('s','s','1','2'), NC_("OpenType layout", "Stylistic Set 12") },
  { MAKE_TAG('s','s','1','3'), NC_("OpenType layout", "Stylistic Set 13") },
  { MAKE_TAG('s','s','1','4'), NC_("OpenType layout", "Stylistic Set 14") },
  { MAKE_TAG('s','s','1','5'), NC_("OpenType layout", "Stylistic Set 15") },
  { MAKE_TAG('s','s','1','6'), NC_("OpenType layout", "Stylistic Set 16") },
  { MAKE_TAG('s','s','1','7'), NC_("OpenType layout", "Stylistic Set 17") },
  { MAKE_TAG('s','s','1','8'), NC_("OpenType layout", "Stylistic Set 18") },
  { MAKE_TAG('s','s','1','9'), NC_("OpenType layout", "Stylistic Set 19") },
  { MAKE_TAG('s','s','2','0'), NC_("OpenType layout", "Stylistic Set 20") },
  { MAKE_TAG('s','s','t','y'), NC_("OpenType layout", "Math script style alternates") },
  { MAKE_TAG('s','t','c','h'), NC_("OpenType layout", "Stretching Glyph Decomposition") },
  { MAKE_TAG('s','u','b','s'), NC_("OpenType layout", "Subscript") },
  { MAKE_TAG('s','u','p','s'), NC_("OpenType layout", "Superscript") },
  { MAKE_TAG('s','w','s','h'), NC_("OpenType layout", "Swash") },
  { MAKE_TAG('t','i','t','l'), NC_("OpenType layout", "Titling") },
  { MAKE_TAG('t','j','m','o'), NC_("OpenType layout", "Trailing Jamo Forms") },
  { MAKE_TAG('t','n','a','m'), NC_("OpenType layout", "Traditional Name Forms") },
  { MAKE_TAG('t','n','u','m'), NC_("OpenType layout", "Tabular Figures") },
  { MAKE_TAG('t','r','a','d'), NC_("OpenType layout", "Traditional Forms") },
  { MAKE_TAG('t','w','i','d'), NC_("OpenType layout", "Third Widths") },
  { MAKE_TAG('u','n','i','c'), NC_("OpenType layout", "Unicase") },
  { MAKE_TAG('v','a','l','t'), NC_("OpenType layout", "Alternate Vertical Metrics") },
  { MAKE_TAG('v','a','t','u'), NC_("OpenType layout", "Vattu Variants") },
  { MAKE_TAG('v','e','r','t'), NC_("OpenType layout", "Vertical Writing") },
  { MAKE_TAG('v','h','a','l'), NC_("OpenType layout", "Alternate Vertical Half Metrics") },
  { MAKE_TAG('v','j','m','o'), NC_("OpenType layout", "Vowel Jamo Forms") },
  { MAKE_TAG('v','k','n','a'), NC_("OpenType layout", "Vertical Kana Alternates") },
  { MAKE_TAG('v','k','r','n'), NC_("OpenType layout", "Vertical Kerning") },
  { MAKE_TAG('v','p','a','l'), NC_("OpenType layout", "Proportional Alternate Vertical Metrics") },
  { MAKE_TAG('v','r','t','2'), NC_("OpenType layout", "Vertical Alternates and Rotation") },
  { MAKE_TAG('v','r','t','r'), NC_("OpenType layout", "Vertical Alternates for Rotation") },
  { MAKE_TAG('z','e','r','o'), NC_("OpenType layout", "Slashed Zero") },
};

#undef MAKE_TAG
