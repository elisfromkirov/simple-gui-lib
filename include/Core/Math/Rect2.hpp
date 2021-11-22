#ifndef __RECT_HPP__
#define __RECT_HPP__

#include "Vector2.hpp"

struct Rect2 {
    Vector2u size;
    Vector2i position;
};

struct Rect2f {
    Vector2f size;
    Vector2f position;
};

#endif // __RECT_HPP__