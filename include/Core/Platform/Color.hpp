#ifndef __COLOR_HPP__
#define __COLOR_HPP__

#include <cstdint>

struct Color {
    Color(float red = 0.f, float green = 0.f, float blue = 0.f, float alpha = 1.f);
    ~Color();

    Color(const Color& other) = default;
    Color& operator=(const Color& other) = default;

    float red;
    float green;
    float blue;
    float alpha;
};

Color ColorFromRGB888(uint32_t color);
Color ColorFromRGB888(uint8_t red, uint8_t green, uint8_t blue);

#endif // __COLOR_HPP__