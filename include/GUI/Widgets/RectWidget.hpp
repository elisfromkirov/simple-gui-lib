#ifndef __RECT_WIDGET_HPP__
#define __RECT_WIDGET_HPP__

#include <cassert>
#include <cstdint>

#include "Handler.hpp"
#include "Renderer.hpp"
#include "Vector2.hpp"
#include "Widget.hpp"

class RectWidget : public Widget {
public:
    RectWidget(const Color& color, const Vector2u& size, const Vector2u& postion = Vector2u());

    virtual ~RectWidget() override;

    virtual void OnRender(Renderer* renderer) override;

protected:
    Color color_;
};

#endif // __RECT_WIDGET_HPP__
