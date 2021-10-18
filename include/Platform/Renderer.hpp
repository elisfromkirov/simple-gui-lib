#ifndef __RENDERER_HPP__
#define __RENDERER_HPP__

#include <cassert>
#include <cstdint>
#include <SDL.h>

#include "Color.hpp"
#include "Rect.hpp"
#include "IRenderTarget.hpp"
#include "Texture.hpp"
#include "Window.hpp"

class Renderer {
public:
    Renderer(Window* window);

    ~Renderer();

    void* GetNativeRenderer();

    void SetRenderTarget(IRenderTarget* target);

    void SetRenderColor(const Color& color);
    Color GetRenderColor() const;

    void Clear();

    void Present();

    void RenderPoint(Vector2<uint32_t> point);

    void RenderTextureCopy(Texture* texture, const Rect& src_rect, const Rect& dst_rect);

private:
    SDL_Renderer*  renderer_;
};

#endif // __RENDERER_HPP__
