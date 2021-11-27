#ifndef __RECT_HPP__
#define __RECT_HPP__

#include "Vector2.hpp"

struct Rect2 {
    Rect2();
    ~Rect2();

    Rect2(uint32_t width, uint32_t height, int32_t x = 0, int32_t y = 0);
    Rect2(const Vector2u& size, const Vector2i& position = Vector2i());

    Rect2(const Rect2& other) = default;
    Rect2& operator=(const Rect2& other) = default;

    Vector2u size;
    Vector2i position;
};

#endif // __RECT_HPP__