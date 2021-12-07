#ifndef __RECTANGLE_HPP__
#define __RECTANGLE_HPP__

#include <cassert>
#include <cstdint>

#include "Core/Math/Rect2.hpp"
#include "Core/Platform/Color.hpp"
#include "Core/Platform/NativePlatform.hpp"

struct Color;

class Rectangle {
public:
    Rectangle(const Rect2& rect, const Color& color = Color());
    ~Rectangle();

    void SetFillColor(const Color& color);
    Color GetFillColor() const;

    void SetPosition(const Vector2i& position);

    void SetRotation(int32_t degrees);

    void SetSize(const Vector2u& size);
    Vector2u GetSize() const;

    const NativeRectangle& GetNativeRectangle() const;

private:
    sf::RectangleShape rectangle_;
};

#endif // __RECTANGLE_HPP__ 