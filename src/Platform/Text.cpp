#include "GUI/Config.hpp"
#include "Platform/Text.hpp"

const Font Text::kDefaultFont{kMediumFontFileName};

const uint32_t Text::kDefaultSize{24};

const Color Text::kDefaultColor{0.f, 0.f, 0.f, 1.f};

Text::Text(const std::string& string)
    :  Text{string, &kDefaultFont, kDefaultSize, kDefaultColor} {}

Text::Text(const std::string& string, const Font* font)
    : Text{string, font, kDefaultSize, kDefaultColor} {}

Text::Text(const std::string& string, const Font* font, uint32_t size, const Color& color)
    : native_font_{font->GetNativeFont()},
      native_text_{string, native_font_, size} {    
    sf::Vector2f position = native_text_.findCharacterPos(string.size());
    
    size_.x = static_cast<uint32_t>(position.x);
    size_.y = size;

    SetFillColor(color);
}

Text::~Text() {}

void Text::SetString(const std::string& string) {
    native_text_.setString(string);

    sf::Vector2f position = native_text_.findCharacterPos(string.size());
    
    size_.x = static_cast<uint32_t>(position.x);
}

void Text::SetFont(const Font& font) {
    native_text_.setFont(font.GetNativeFont());
}

void Text::SetCharacterSize(uint32_t size) {
    native_text_.setCharacterSize(size);

    size_.y = size;
}

void Text::SetFillColor(const Color& color) {
    native_text_.setFillColor(sf::Color(static_cast<sf::Uint8>(color.red   * 255.f),
                                        static_cast<sf::Uint8>(color.green * 255.f),
                                        static_cast<sf::Uint8>(color.blue  * 255.f),
                                        static_cast<sf::Uint8>(color.alpha * 255.f)));
}

void Text::SetPosition(const Vector2i& position) {
    native_text_.setPosition(sf::Vector2f(position.x, position.y));
}

Vector2u Text::GetSize() const {
    return size_;
}

const NativeText& Text::GetNativeText() const {
    return native_text_;
}
