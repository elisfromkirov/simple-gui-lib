#ifndef __RENDER_TEXTURE_HPP__
#define __RENDER_TEXTURE_HPP__

#include <cassert>
#include <cstdint>

#include "Core/Math/Vector2.hpp"
#include "Core/Platform/NativePlatform.hpp"

class Color;
class Image;
class Text;
class Rectangle;

class RenderTexture {
public:
    RenderTexture(const Vector2u& size);
    ~RenderTexture();

    void Clear(const Color& color);
    void Display();

    void RenderText(const Text& text);
    void RenderImage(const Image& image);
    void RenderRectangle(const Rectangle& rectangle);

    const NativeImage& GetImage();
    const Vector2u&    GetSize();

private:
    sf::RenderTexture texture_;
    sf::Sprite        sprite_;
};

#endif // __RENDER_TEXTURE_HPP__