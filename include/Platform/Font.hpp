#ifndef __FONT_HPP__
#define __FONT_HPP__

#include <cassert>
#include <cstdint>
#include <string>

#include "Platform/Platform.hpp"

class Font {
public:
    Font(const std::string& filename);
    ~Font();

    const NativeFont& GetNativeFont() const;

private:
    sf::Font native_font_;
};

#endif // __FONT_HPP__
