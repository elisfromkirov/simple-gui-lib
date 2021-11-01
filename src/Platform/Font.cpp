#include <cstdio>

#include "Font.hpp"

Font::Font(const std::string& filename) 
    : native_font_{} {
    bool loaded = native_font_.loadFromFile(filename);
    if (!loaded) {
        printf("Unable to load font from file \"%s\"\n", filename.c_str());
    }
}

Font::~Font() {}

const NativeFont& Font::GetNativeFont() const {
    return native_font_;
}
