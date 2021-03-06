#ifndef __I_STYLE_HPP__
#define __I_STYLE_HPP__

class Widget;
class IRenderTarget;

class IStyle {
public:
    virtual ~IStyle() {}

    virtual void Apply(Widget* widget, IRenderTarget* render_target) = 0;
};

#endif // __I_STYLE_HPP__