#ifndef __I_RENDER_TARGET_HPP__
#define __I_RENDER_TARGET_HPP__

#include <cassert>
#include <cstdint>

#include <SFML/Graphics.hpp>

typedef sf::RenderTarget NativeRenderTarget;

#include "Core/Platform/Color.hpp"

class IRenderTarget {
public:
    virtual ~IRenderTarget() {}

    virtual void Clear(const Color& color) = 0;

    virtual void Display() = 0;

    virtual NativeRenderTarget* GetNativeRenderTarget() = 0;
};

#endif // __I_RENDER_TARGET_HPP__