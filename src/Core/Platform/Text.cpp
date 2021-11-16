#include "Core/Platform/Text.hpp"

const uint32_t Text::kDefaultSize{24};

const Color Text::kDefaultColor{0.f, 0.f, 0.f, 1.f};

Text::Text(const std::string& string, const Font& font)
    : Text{string, font, kDefaultSize, kDefaultColor} {}

Text::Text(const std::string& string, const Font& font, uint32_t char_size, const Color& fill_color)
    : text_{string, font.GetNativeFont(), char_size} {
    sf::Vector2f position = text_.findCharacterPos(string.size());
    
    size_.x = static_cast<uint32_t>(position.x);
    size_.y = char_size;

    SetFillColor(fill_color);
}

Text::~Text() {}

void Text::SetString(const std::string& string) {
    text_.setString(string);

    sf::Vector2f position = text_.findCharacterPos(string.size());
    
    size_.x = static_cast<uint32_t>(position.x);
}

void Text::SetFont(const Font& font) {
    text_.setFont(font.GetNativeFont());
}

void Text::SetCharacterSize(uint32_t size) {
    text_.setCharacterSize(size);

    size_.y = size;
}

void Text::SetFillColor(const Color& color) {
    text_.setFillColor(sf::Color{static_cast<uint8_t>(color.red   * 255.f),
                                 static_cast<uint8_t>(color.green * 255.f),
                                 static_cast<uint8_t>(color.blue  * 255.f),
                                 static_cast<uint8_t>(color.alpha * 255.f)});
}

void Text::SetPosition(const Vector2i& position) {
    text_.setPosition(sf::Vector2f(position.x, position.y));
}

const Vector2u& Text::GetSize() const {
    return size_;
}

const NativeText& Text::GetNativeText() const {
    return text_;
}