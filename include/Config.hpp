#ifndef __CONFIG_HPP__
#define __CONFIG_HPP__

#define IMAGE(name) "../assets/Images/" name ".bmp"

static const char* kCloseButtonFileName{IMAGE("Close")};

#undef IMAGE

#define FONT(name) "../assets/Fonts/SourceCodePro/SourceCodePro" name ".ttf"

static const char* kBlackFontFileName       {FONT("Black"         )};
static const char* kBlackItalicFontFileName {FONT("BlackItalic"   )};
static const char* kBoldFontFileName        {FONT("Bold"          )};
static const char* kBoldItalicFontFileName  {FONT("BoldItalic"    )};
static const char* kLightFontFileName       {FONT("Light"         )};
static const char* kLightItalicFontFileName {FONT("LightItalic"   )};
static const char* kMediumFontFileName      {FONT("Medium"        )};
static const char* kMediumItalicFontFileName{FONT("MediumItalic"  )};
static const char* kRegularFontFileName     {FONT("Regular"       )};
static const char* kSemiBoldFontFileName    {FONT("SemiBold"      )};
static const char* kBoldItalocFontFileName  {FONT("SemiBoldItalic")};

#undef FONT

#endif // __CONFIG_HPP__
