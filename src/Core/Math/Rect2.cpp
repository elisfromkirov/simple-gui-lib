#include "Core/Math/Rect2.hpp"

Rect2::Rect2() 
    : size{},
      position{} {} 

Rect2::~Rect2() {}

Rect2::Rect2(uint32_t width, uint32_t height, int32_t x, int32_t y)
    : size{width, height},
      position{x, y} {}

Rect2::Rect2(const Vector2u& size, const Vector2i& position) 
    : size{size}, 
      position{position} {}