#include "Core/Platform/Font.hpp"

Font::Font(const std::string& path) 
    : font_{} {
    font_.loadFromFile(path);
}

Font::~Font() {}

const NativeFont& Font::GetNativeFont() const {
    return font_;
}