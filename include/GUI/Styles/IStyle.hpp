#ifndef __I_STYLE_HPP__
#define __I_STYLE_HPP__

class Widget;
class RenderTexture;

class IStyle {
public:
    virtual ~IStyle() {}

    virtual void Apply(Widget* widget, RenderTexture* texture) = 0;
};

#endif // __I_STYLE_HPP__