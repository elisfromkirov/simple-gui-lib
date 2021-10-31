#ifndef __CONTAINER_WIDGET_HPP__
#define __CONTAINER_WIDGET_HPP__

#include <cassert>
#include <cstdint>
#include <list>

#include "Handler.hpp"
#include "MouseEvent.hpp"
#include "Renderer.hpp"
#include "Vector2.hpp"
#include "Widget.hpp"

class ContainerWidget : public Widget {
public:
    ContainerWidget(const Vector2u& size, const Vector2u& postion = Vector2u());

    virtual ~ContainerWidget() override;

    virtual void OnRender(Renderer* renderer) override;

    virtual bool OnMouseButtonPress(const MouseButtonPressEvent* event) override;
    virtual bool OnMouseButtonRelease(const MouseButtonReleaseEvent* event) override;
    virtual bool OnMouseMove(const MouseMoveEvent* event) override;

    bool Attach(Widget* widget, const Vector2u& relative_position);
    bool Detach(Widget* widget);

protected:
    std::list<Widget*> children_;
};

#endif // __CONTAINER_WIDGET_HPP__
