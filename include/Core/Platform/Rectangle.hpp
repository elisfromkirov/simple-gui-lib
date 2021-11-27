#ifndef __RECTANGLE_HPP__
#define __RECTANGLE_HPP__

#include <cassert>
#include <cstdint>

#include "Core/Math/Rect2.hpp"
#include "Core/Platform/NativePlatform.hpp"

class Rectangle {
public:
    Rectangle(const Rect2& rect);
    ~Rectangle();

    void SetFillColor(const Color& color);

    void SetPosition(const Vector2i& position);

    void SetRotation(int32_t degrees);

    void SetSize(const Vector2u& size);

    Vector2u GetSize() const;

    const NativeRectangle& GetNativeRectangle() const;

private:
    sf::RectangleShape rectangle_;
};

#endif // __RECTANGLE_HPP__ 