#ifndef __FONT_HPP__
#define __FONT_HPP__

#include <cassert>
#include <cstdint>

#include "Platform/Platform.hpp"

class Font {
public:
    Font(const char* filename);
    ~Font();

    const NativeFont& GetNativeFont() const;

private:
    sf::Font native_font_;
};

#endif // __FONT_HPP__
