#include "Platform/Font.hpp"

Font::Font(const std::string& filename) 
    : native_font_{} {
    native_font_.loadFromFile(filename);
}

Font::~Font() {}

const NativeFont& Font::GetNativeFont() const {
    return native_font_;
}
