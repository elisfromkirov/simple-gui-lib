#ifndef __FONT_HPP__
#define __FONT_HPP__

#include <cassert>
#include <cstdint>
#include <string>

#include "Core/Platform/NativePlatform.hpp"

class Font {
public:
    Font(const std::string& path);
    ~Font();

    const NativeFont& GetNativeFont() const;

private:
    sf::Font font_;
};

#endif // __FONT_HPP__