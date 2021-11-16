#ifndef __FILLED_STYLE_HPP__
#define __FILLED_STYLE_HPP__

#include "Core/Platform/Color.hpp"
#include "GUI/Style/IStyle.hpp"

class FilledStyle : public IStyle {
public:
    FilledStyle(const Color& color_on_release, const Color& color_on_hover, 
                const Color& color_on_press);
    virtual ~FilledStyle() override;

    virtual void Apply(Widget* widget, Renderer* renderer) override; 

protected:
    Color color_on_release_;
    Color color_on_hover_;
    Color color_on_press_;
};

#endif // __FILLED_STYLE_HPP__