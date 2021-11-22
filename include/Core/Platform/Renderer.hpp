#ifndef __RENDERER_HPP__
#define __RENDERER_HPP__

#include <cassert>
#include <cstdint>

#include <SFML/Graphics.hpp>

#include "Core/Math/Rect2.hpp"
#include "Core/Math/Vector2.hpp"
#include "Core/Platform/Color.hpp"

class Image;
class IRenderTarget;
class Text;
class RenderTexture;
class RenderWindow;

class Renderer {
public:
    Renderer(RenderWindow* window);
    ~Renderer();

    void Clear(const Color& color = Color());
    void Display();

    void CopyTexture(RenderTexture* render_texture, const Vector2i& position);

    void RenderText     (const Text& text);
    void RenderImage    (const Image& image);
    void RenderRectangle(const Rect2& rect, const Color& color);

    IRenderTarget* GetRenderTarget();
    void SetRenderTarget(IRenderTarget* render_target);

private:
    IRenderTarget*    render_target_;
};

#endif // __RENDERER_HPP__