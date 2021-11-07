#ifndef __WIDGET_HPP__
#define __WIDGET_HPP__

#include <cassert>
#include <cstdint>
#include <list>

#include "Core/Math/Vector2.hpp"
#include "GUI/Event/InputEvent.hpp"
#include "Platform/Renderer.hpp"

class Widget {
public:
    Widget(const Vector2u& size = Vector2u(), const Vector2i& postion = Vector2i());

    virtual ~Widget();

    virtual void OnRender(Renderer* renderer) const;

    virtual void OnResize(const Vector2u& size);

    virtual void OnMove(const Vector2i& displacement);

    virtual Widget* OnHitTest(const Vector2u& point);

    bool Attach(Widget* widget);

    bool Detach(Widget* widget);

    const Vector2u& GetSize() const;

    const Vector2i& GetPosition() const;

    Widget* GetParent() const;

    bool IsVisible();
    void SetVisible(bool visible);

    virtual bool OnMouseButtonPress(const MouseButtonPressEvent* event);

    virtual bool OnMouseButtonRelease(const MouseButtonReleaseEvent* event);

    virtual bool OnMouseMove(const MouseMoveEvent* event);

    virtual bool OnMouseHover(const MouseHoverEvent* event);

    virtual bool OnMouseLeave(const MouseLeaveEvent* event);

protected:
    virtual bool Contains(const Vector2u& point) const;

    virtual void Render(Renderer* renderer) const;

    virtual void Resize(const Vector2u& size);

    virtual void Move(const Vector2i& displacement);

protected:
    Vector2u           size_;
    Vector2i           position_;

    Widget*            parent_;
    std::list<Widget*> children_;

    bool               visible_;
};

#endif // __WIDGET_HPP__
