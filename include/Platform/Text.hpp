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
    static const uint32_t kDefaultSize;
    static const Color kDefaultColor;

public:
    Text(const std::string& string, const Font& font);

    Text(const std::string& string, const Font& font, uint32_t size, const Color& color);

    ~Text();

    void SetString(const std::string& string);

    void SetFont(const Font& font);

    void SetCharacterSize(uint32_t size);

    void SetFillColor(const Color& color);

    void SetPosition(const Vector2u& position);

    const NativeText& GetNativeText() const;

private:
    sf::Text native_text_;
};

#endif // __TEXT_HPP__
