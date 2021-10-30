#include "Text.hpp"

const uint32_t Text::kDefaultSize{32};

const Color Text::kDefaultColor{0.f, 0.f, 0.f, 0.f};

Text::Text(const std::string& string, const Font& font)
    : Text{string, font, kDefaultSize, kDefaultColor} {}

Text::Text(const std::string& string, const Font& font, uint32_t size, const Color& color)
    : native_text_{string, font.GetNativeFont()} {
    SetCharacterSize(size);
    SetFillColor(color);
}

Text::~Text() {}

void Text::SetString(const std::string& string) {
    native_text_.setString(string);
}

void Text::SetFont(const Font& font) {
    native_text_.setFont(font.GetNativeFont());
}

void Text::SetCharacterSize(uint32_t size) {
    native_text_.setCharacterSize(size);
}

void Text::SetFillColor(const Color& color) {
    sf::Color native_color_{static_cast<sf::Uint8>(color.red   * 255.f),
                            static_cast<sf::Uint8>(color.green * 255.f),
                            static_cast<sf::Uint8>(color.blue  * 255.f),
                            static_cast<sf::Uint8>(color.alpha * 255.f)};

    native_text_.setFillColor(native_color_);
}

void Text::SetPosition(const Vector2u& position) {
    native_text_.setPosition(sf::Vector2f{static_cast<float>(position.x),
                                          static_cast<float>(position.y)});
}

const NativeText& Text::GetNativeText() const {
    return native_text_;
}
