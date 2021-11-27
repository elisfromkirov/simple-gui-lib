#include "Core/Platform/Color.hpp"
#include "Core/Platform/Text.hpp"

Text::Text(const std::string& string, const Font& font, uint32_t char_size)
    : text_{string, font.GetNativeFont(), char_size} {
    size_.x = static_cast<uint32_t>(text_.findCharacterPos(string.size()).x);
    size_.y = char_size;
}

Text::~Text() {}

void Text::SetString(const std::string& string) {
    text_.setString(string);
    
    size_.x = static_cast<uint32_t>(text_.findCharacterPos(string.size()).x);
}

void Text::SetFont(const Font& font) {
    text_.setFont(font.GetNativeFont());
}

void Text::SetCharSize(uint32_t char_size) {
    text_.setCharacterSize(char_size);

    size_.y = char_size;
}

void Text::SetFillColor(const Color& color) {
    text_.setFillColor(NativeColorFromColor(color));
}

void Text::SetPosition(const Vector2i& position) {
    text_.setPosition(sf::Vector2f(position.x, position.y));
}

Vector2u Text::GetSize() const {
    return size_;
}

const NativeText& Text::GetNativeText() const {
    return text_;
}