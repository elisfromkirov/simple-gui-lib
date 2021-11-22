#ifndef __BORDERD_STYLE_HPP__
#define __BORDERD_STYLE_HPP__

#include "Core/Platform/Color.hpp"
#include "GUI/Styles/IStyle.hpp"

class BorderedStyle : public {
public:
    Bordered();

    virtual ~BorderedStyle() override;

    virtual void Apply(Widget* widget, Renderer* renderer) override;

protected:

};

#endif // __BORDERD_STYLE_HPP__