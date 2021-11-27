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

Color ColorFromARGB(uint32_t color);
Color ColorFromRGBA(uint32_t color);

NativeColor NativeColorFromColor(const Color& color);
Color       ColorFromNativeColor(const NativeColor& color);

#endif // __COLOR_HPP__