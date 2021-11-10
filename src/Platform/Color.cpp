#include "Platform/Color.hpp"

Color::Color()
    : red  {0.f},
      green{0.f},
      blue {0.f},
      alpha{1.f} {}

Color::Color(uint32_t color)
     : red  {static_cast<float>((color >> 16) & 255) / 255.f},
       green{static_cast<float>((color >>  8) & 255) / 255.f},
       blue {static_cast<float>((color      ) & 255) / 255.f},
       alpha{1.f} {}

Color::Color(float red, float green, float blue, float alpha)
    : red  {red  },
      green{green},
      blue {blue },
      alpha{alpha} {}

Color::~Color() {}

Color::Color(const Color& other)
    : red  {other.red},
      green{other.green},
      blue {other.blue},
      alpha{other.alpha} {}

Color& Color::operator=(const Color& other) {
    if (this == &other) {
        return *this;
    }

    red   = other.red;
    green = other.green;
    blue  = other.blue;
    alpha = other.alpha;

    return *this;
}
