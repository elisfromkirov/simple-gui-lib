#ifndef __COLOR_HPP__
#define __COLOR_HPP__

#include <cstdint>

struct Color {
    Color();

    explicit Color(uint32_t color);

    Color(float red, float green, float blue, float alpha = 1.f);

    ~Color();

    Color(const Color& other);
    Color& operator=(const Color& other);
    
    float red;
    float green;
    float blue;
    float alpha;
};

#endif // __COLOR_HPP__
