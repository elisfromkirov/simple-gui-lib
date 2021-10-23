#include "Renderer.hpp"
#include "Texture.hpp"

Texture::Texture(Renderer* renderer, Vector2<uint32_t> size) : texture_{nullptr}, size_{size} {
    assert(renderer != nullptr);

    SDL_Renderer* native_renderer = reinterpret_cast<SDL_Renderer*>(renderer->GetNativeRenderer());
    assert(native_renderer != nullptr);

    texture_ = SDL_CreateTexture(native_renderer, SDL_PIXELFORMAT_RGBA8888,
                                 SDL_TEXTUREACCESS_TARGET, size.x, size.y);
    assert(texture_ != nullptr);
}

Texture::~Texture() {
    assert(texture_ != nullptr);

    SDL_DestroyTexture(texture_);
}

void* Texture::GetNativeTexture() {
    assert(texture_ != nullptr);
    
    return texture_;
}
