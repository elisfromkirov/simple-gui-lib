#ifndef __COMPOSITE_WIDGET_HPP__
#define __COMPOSITE_WIDGET_HPP__

#include <cassert>
#include <cstdint>
#include <list>

#include "Core/Platform/RenderTexture.hpp"
#include "GUI/Widgets/Widget.hpp"

class CompositeWidget : public Widget {
public:
    CompositeWidget(const Vector2u& size, const Vector2i& position = Vector2i());
    virtual ~CompositeWidget();

    virtual void OnRender(Renderer* renderer) override;

    virtual Rect2 GetFillArea() const override;

    virtual bool OnMouseButtonPressEvent(const MouseButtonPressEvent* event) override;

    virtual bool OnMouseButtonReleaseEvent(const MouseButtonReleaseEvent* event) override;

    virtual bool OnMouseMoveEvent(const MouseMoveEvent* event) override;

    bool Attach(Widget* widget);
    bool Detach(Widget* widget);

protected:
    virtual void RenderChildren(Renderer* renderer);

    bool DispatchMouseButtonPressEventToChildren(const MouseButtonPressEvent* event);

    bool DispatchMouseButtonReleaseEventToChildren(const MouseButtonReleaseEvent* event);

    bool DispatchMouseMoveEventToChildren(const MouseMoveEvent* event);

protected:
    RenderTexture      surface_;

    std::list<Widget*> children_;
};

#endif // __COMPOSITE_WIDGET_HPP__