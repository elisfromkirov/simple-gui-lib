#ifndef __COLOR_HPP__
#define __COLOR_HPP__

#include <cstdint>

#include "Core/Platform/NativePlatform.hpp"

struct Color {
    Color();
    ~Color();

    Color(float red, float green, float blue, float alpha);

    Color(const Color& other) = default;
    Color& operator=(const Color& other) = default;

    float red;
    float green;
    float blue;
    float alpha;
};

Color ColorFromRGBA(uint32_t color);
Color ColorFromRGBA(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);

NativeColor NativeColorFromColor(const Color& color);
Color       ColorFromNativeColor(const NativeColor& color);

#endif // __COLOR_HPP__