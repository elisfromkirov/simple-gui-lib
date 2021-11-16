#include "Core/Platform/Color.hpp"

Color::Color(float red, float green, float blue, float alpha)
    : red  {red  },
      green{green},
      blue {blue },
      alpha{alpha} {}

Color::~Color() {}

Color ColorFromRGB888(uint32_t color) {
    return Color(static_cast<float>((color >> 16) & 255) / 255.f,
                 static_cast<float>((color >>  8) & 255) / 255.f,
                 static_cast<float>((color      ) & 255) / 255.f);
}

Color ColorFromRGB888(uint8_t red, uint8_t green, uint8_t blue) {
    return Color(static_cast<float>(red  ) / 255.f,
                 static_cast<float>(green) / 255.f,
                 static_cast<float>(blue ) / 255.f);
}