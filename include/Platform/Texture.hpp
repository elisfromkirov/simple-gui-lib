#ifndef __TEXTURE_HPP__
#define __TEXTURE_HPP__

#include <cassert>
#include <cstdint>
#include <SDL.h>

#include "Vector2.hpp"
#include "IRenderTarget.hpp"

class Renderer;

class Texture : public IRenderTarget {
public:
    Texture(Renderer* renderer, uint32_t width, uint32_t height);

    Texture(Renderer* renderer, Vector2<uint32_t> size);

    virtual ~Texture() override;

    void* GetNativeTexture();

    virtual void* GetRenderTarget() override;

private:
    SDL_Texture*      texture_;

    Vector2<uint32_t> size_;
};

#endif // __TEXTURE_HPP__
