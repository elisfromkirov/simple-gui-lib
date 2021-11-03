#ifndef __WIDGET_HPP__
#define __WIDGET_HPP__

#include <cassert>
#include <cstdint>
#include <list>

#include "Core/EventManager/IEventListener.hpp"
#include "Core/Math/Vector2.hpp"
#include "GUI/Event/InputEvent.hpp"
#include "Platform/Renderer.hpp"

class Widget : public IEventListener {
public:
    Widget(const Vector2u& size, const Vector2u& postion = Vector2u());

    virtual ~Widget();

    virtual bool OnEvent(const Event* event) override;

    virtual bool HitTest(const Vector2u& point) const;

    virtual void OnRender(Renderer* renderer) const;

    bool Attach(Widget* widget);

    bool Detach(Widget* widget);

    const Vector2u& GetSize() const;

    const Vector2u& GetPosition() const;

    Widget* GetParent() const;

protected:
    virtual bool OnMouseButtonPress(const MouseButtonPressEvent* event);

    virtual bool OnMouseButtonRelease(const MouseButtonReleaseEvent* event);

    virtual bool OnMouseMove(const MouseMoveEvent* event);

protected:
    Vector2u           size_;
    Vector2u           position_;

    Widget*            parent_;
    std::list<Widget*> children_;
};

#endif // __WIDGET_HPP__
