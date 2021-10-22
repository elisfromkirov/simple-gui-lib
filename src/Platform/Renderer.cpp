#include "Renderer.hpp"

Renderer::Renderer(Window* window) : renderer_{nullptr} {
    assert(window != nullptr);

    SDL_Window* native_window = reinterpret_cast<SDL_Window*>(window->GetNativeWindow());
    assert(native_window != nullptr);

    renderer_ = SDL_CreateRenderer(native_window, -1,
                                   SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);
    assert(renderer_ != nullptr);
}

Renderer::~Renderer() {
    assert(renderer_ != nullptr);

    SDL_DestroyRenderer(renderer_);
}

void* Renderer::GetNativeRenderer() {
    assert(renderer_ != nullptr);

    return renderer_;
}

void Renderer::SetRenderTarget(Texture* texture) {
    assert(texture != nullptr);

    SDL_Texture* native_texture = reinterpret_cast<SDL_Texture*>(texture->GetNativeTexture());
    assert(native_texture != nullptr);

    SDL_SetRenderTarget(renderer_, native_texture);
}

void Renderer::SetRenderTarget(Window* window) {
    assert(window != nullptr);

    SDL_SetRenderTarget(renderer_, nullptr);
}

void Renderer::SetRenderColor(const Color& color) {
    assert(renderer_ != nullptr);

    SDL_SetRenderDrawColor(renderer_, color.red * 0xff, color.green * 0xff, color.blue * 0xff, 0xff);
}

Color Renderer::GetRenderColor() const {
    assert(renderer_ != nullptr);
    
    uint8_t red   = 0;
    uint8_t green = 0;
    uint8_t blue  = 0;
    uint8_t alpha = 0;

    SDL_GetRenderDrawColor(renderer_, &red, &green, &blue, &alpha);

    return Color{float(red)/float(0xff), float(green)/float(0xff), float(blue)/float(0xff)};
}

void Renderer::Clear() {
    assert(renderer_ != nullptr);

    SDL_RenderClear(renderer_);
}

void Renderer::Present() {
    assert(renderer_ != nullptr);

    SDL_RenderPresent(renderer_);
}

void Renderer::RenderPoint(Vector2<uint32_t> point) {
    assert(renderer_ != nullptr);

    SDL_RenderDrawPoint(renderer_, point.x, point.y);
}

void Renderer::RenderTextureCopy(Texture* texture, const Rect& src_rect, const Rect& dst_rect) {
    assert(renderer_ != nullptr);

    SDL_Rect native_src_rect{static_cast<int>(src_rect.x_pos), static_cast<int>(src_rect.y_pos), 
                             static_cast<int>(src_rect.width), static_cast<int>(src_rect.height)};
    SDL_Rect native_dst_rect{static_cast<int>(dst_rect.x_pos), static_cast<int>(dst_rect.y_pos), 
                             static_cast<int>(dst_rect.width), static_cast<int>(dst_rect.height)};

    SDL_Texture* native_texture = reinterpret_cast<SDL_Texture*>(texture->GetNativeTexture());
    assert(native_texture != nullptr);

    SDL_RenderCopy(renderer_, native_texture, &native_src_rect, &native_dst_rect);
}
