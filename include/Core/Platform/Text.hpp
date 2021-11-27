#ifndef __TEXT_HPP__
#define __TEXT_HPP__

#include <cassert>
#include <cstdint>
#include <string>

#include "Core/Math/Vector2.hpp"
#include "Core/Platform/NativePlatform.hpp"
#include "Core/Platform/Font.hpp"

struct Color;

class Text {
public:
    Text(const std::string& string, const Font& font, uint32_t char_size = 24);
    ~Text();

    void SetString(const std::string& string);
    void SetFont(const Font& font);
    void SetCharSize(uint32_t char_size);
    void SetFillColor(const Color& color);
    void SetPosition(const Vector2i& position);

    Vector2u GetSize() const;
    const NativeText& GetNativeText() const;

private:
    sf::Text text_;

    Vector2u size_;
};

#endif // __TEXT_HPP__