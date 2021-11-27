#include "Core/Platform/Color.hpp"

Color::Color()
    : red  {0.f},
      green{0.f},
      blue {0.f},
      alpha{0.f} {}

Color::~Color() {}

Color::Color(float red, float green, float blue, float alpha)
    : red  {red  },
      green{green},
      blue {blue },
      alpha{alpha} {}

Color ColorFromRGBA(uint32_t color) {
    return Color(static_cast<float>((color >> 24) & 255) / 255.f,
                 static_cast<float>((color >> 16) & 255) / 255.f,
                 static_cast<float>((color >>  8) & 255) / 255.f,
                 static_cast<float>((color      ) & 255) / 255.f);
}

Color ColorFromRGBA(uint8_t red, uint8_t green, uint8_t blue) {
    return Color(static_cast<float>(red  ) / 255.f,
                 static_cast<float>(green) / 255.f,
                 static_cast<float>(blue ) / 255.f,
                 static_cast<float>(alpha) / 255.f);
}

NativeColor NativeColorFromColor(const Color& color) {
    return sf::Color(static_cast<uint8_t>(color.red   * 255.f),
                     static_cast<uint8_t>(color.green * 255.f),
                     static_cast<uint8_t>(color.blue  * 255.f),
                     static_cast<uint8_t>(color.alpha * 255.f));
}

Color ColorFromNativeColor(const NativeColor& color) {
    return Color(static_cast<float>(color.r) / 255.f,
                 static_cast<float>(color.g) / 255.f,
                 static_cast<float>(color.b) / 255.f,
                 static_cast<float>(color.a) / 255.f);
}