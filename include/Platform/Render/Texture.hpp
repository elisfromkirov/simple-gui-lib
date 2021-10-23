#ifndef __TEXTURE_HPP__
#define __TEXTURE_HPP__

#include <cassert>
#include <cstdint>
#include <SDL.h>

#include "Vector2.hpp"

class Renderer;

class Texture {
public:
    Texture(Renderer* renderer, Vector2<uint32_t> size);

    ~Texture();

    void* GetNativeTexture();

private:
    SDL_Texture*      texture_;

    Vector2<uint32_t> size_;
};

#endif // __TEXTURE_HPP__
