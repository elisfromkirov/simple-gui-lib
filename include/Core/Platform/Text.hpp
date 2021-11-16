#ifndef __TEXT_HPP__
#define __TEXT_HPP__

#include <cassert>
#include <cstdint>
#include <string>

#include <SFML/Graphics.hpp>

typedef sf::Text NativeText;

#include "Core/Math/Vector2.hpp"
#include "Core/Platform/Color.hpp"
#include "Core/Platform/Font.hpp"

class Text {
private:
    static const uint32_t kDefaultSize;

    static const Color    kDefaultColor;

public:
    Text(const std::string& string, const Font& font);
    Text(const std::string& string, const Font& font, uint32_t char_size, const Color& fill_color);
    ~Text();

    void SetString(const std::string& string);

    void SetFont(const Font& font);

    void SetCharacterSize(uint32_t char_size);

    void SetFillColor(const Color& color);

    void SetPosition(const Vector2i& position);

    const Vector2u& GetSize() const;

    const NativeText& GetNativeText() const;

private:
    sf::Text text_;

    Vector2u size_;
};

#endif // __TEXT_HPP__