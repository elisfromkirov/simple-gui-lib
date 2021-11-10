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
    Widget(const Vector2u& size = Vector2u(), const Vector2i& position = Vector2i());

    virtual ~Widget();

    virtual void OnRender(Renderer* renderer) const;

    virtual void OnResize(const Vector2u& size);

    virtual void OnMove(const Vector2i& displacement);

    virtual bool HitTest(const Vector2u& point) const;

    virtual bool OnMouseButtonPress(const MouseButtonPressEvent* event);

    virtual bool OnMouseButtonRelease(const MouseButtonReleaseEvent* event);

    virtual bool OnMouseMove(const MouseMoveEvent* event);

    virtual bool OnMouseHover(const MouseHoverEvent* event);

    virtual bool OnMouseLeave(const MouseLeaveEvent* event); 

    const Vector2u& GetSize() const;

    const Vector2i& GetPosition() const;

    Widget* GetParent() const;

    bool Attach(Widget* widget);
    bool Detach(Widget* widget);

    bool IsVisible() const;
    void SetVisible(bool visible);

    bool IsResizable() const;
    void SetResizable(bool resizable);

    bool IsMovable() const;
    void SetMovable(bool movable);

    bool IsActive() const;
    void SetActive(bool active);

    bool IsFilled() const;
    void SetFilled(bool filled);

    const Color& GetFillColor() const;
    void SetFillColor(const Color& color);

    template <class WidgetVisitor>
    void Accept(WidgetVisitor* visitor);

protected:
    virtual void RenderBackGround(Renderer* renderer) const;

    virtual void Render(Renderer* renderer) const;

    virtual void Resize(const Vector2u& size);

    virtual void Move(const Vector2i& displacement);

protected:
    Vector2u           size_;
    Vector2i           position_;

    Widget*            parent_;
    std::list<Widget*> children_;

    bool               visible_;

    bool               resizable_; 

    bool               movable_;

    bool               active_;

    bool               filled_;
    Color              fill_color_;
};

template <class WidgetVisitor>
void Widget::Accept(WidgetVisitor* visitor) {
    assert(visitor != nullptr);

    visitor->StartWidget(this);

    for (auto iter = children_.begin(); iter != children_.end(); ++iter) {
        (*iter)->Accept(visitor);
    }

    visitor->FinishWidget(this);
}

#endif // __WIDGET_HPP__
