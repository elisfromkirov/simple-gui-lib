#ifndef __CONTAINER_WIDGET_HPP__
#define __CONTAINER_WIDGET_HPP__

#include <cassert>
#include <cstdint>
#include <list>

#include "GUI/Widgets/Widget.hpp"

class IStyle;
class IRenderTarget;

class ContainerWidget : public Widget {
public:
    ContainerWidget(const Rect2& rect);
    virtual ~ContainerWidget();

    virtual void Resize(const Vector2u& size) override;

    virtual void Move(const Vector2i& position) override;

    virtual void OnRender(IRenderTarget* render_target) override;

    bool FilterMouseMoveEvent(const MouseMoveEvent* event);

    virtual bool OnEvent(const Event* event) override;

    virtual bool OnMouseEnterEvent(const MouseEnterEvent* event) override;

    virtual bool OnMouseLeaveEvent(const MouseLeaveEvent* event) override;

    bool Attach(Widget* widget);
    bool Detach(Widget* widget);    

    bool AttachInMiddle(Widget* widget);
    bool AttachInTop   (Widget* widget);
    bool AttachInBottom(Widget* widget);
    bool AttachInLeft  (Widget* widget);
    bool AttachInRight (Widget* widget);

    void ApplyStyle(IStyle* style);

protected:
    ContainerWidget();

protected:
    RenderTexture*     texture_;

    std::list<Widget*> children_;

    std::list<IStyle*> styles_;
};

#endif // __CONTAINER_WIDGET_HPP__