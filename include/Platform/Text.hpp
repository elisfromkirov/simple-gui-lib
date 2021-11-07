#ifndef __TEXT_HPP__
#define __TEXT_HPP__

#include <cassert>
#include <cstdint>
#include <string>

#include "Core/Math/Vector2.hpp"
#include "Platform/Color.hpp"
#include "Platform/Font.hpp"
#include "Platform/Platform.hpp"

class Text {
private:
    static const Font     kDefaultFont;

    static const uint32_t kDefaultSize;
    
    static const Color    kDefaultColor;

public:
    Text(const std::string& string);

    Text(const std::string& string, const Font* font);

    Text(const std::string& string, const Font* font, uint32_t char_size, const Color& fill_color);

    ~Text();

    void SetString(const std::string& string);

    void SetFont(const Font& font);

    void SetCharacterSize(uint32_t size);

    void SetFillColor(const Color& color);

    void SetPosition(const Vector2i& position);

    Vector2u GetSize() const;

    const NativeText& GetNativeText() const;

private:
    sf::Font native_font_;
    sf::Text native_text_;

    Vector2u size_;
};

#endif // __TEXT_HPP__
