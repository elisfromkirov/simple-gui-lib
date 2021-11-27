#ifndef __STYLE_HPP__
#define __STYLE_HPP__

class Widget;
class RenderTexture;

class Style {
public:
    virtual ~Style() {}

    virtual void Apply(Widget* widget, RenderTexture* texture) = 0;
};

#endif // __STYLE_HPP__