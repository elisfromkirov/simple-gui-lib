#ifndef __I_RENDER_TARGET_HPP__
#define __I_RENDER_TARGET_HPP__

struct Color;
class Image;
class Text;
class Rectangle;

class IRenderTarget {
public:
    virtual ~IRenderTarget() {}

    virtual void Clear(const Color& color) = 0;
    virtual void Display() = 0;

    virtual void RenderText(const Text& text) = 0;
    virtual void RenderImage(const Image& image) = 0;
    virtual void RenderRectangle(const Rectangle& rectangle) = 0;
};

#endif // __I_RENDER_TARGET_HPP__