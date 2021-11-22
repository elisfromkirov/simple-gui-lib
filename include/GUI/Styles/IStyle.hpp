#ifndef __I_STYLE_HPP__
#define __I_STYLE_HPP__

class Widget;
class Renderer;

class IStyle {
public:
    virtual ~IStyle() {}

    virtual void Apply(Widget* widget, Renderer* renderer) = 0;
};

#endif // __I_STYLE_HPP__