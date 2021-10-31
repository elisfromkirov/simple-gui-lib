#ifndef __WIDGET_HPP__
#define __WIDGET_HPP__

#include <cassert>
#include <cstdint>
#include <map>

#include "Handler.hpp"
#include "MouseEvent.hpp"
#include "Renderer.hpp"
#include "Vector2.hpp"

class Widget {
public:
    Widget(const Vector2u& size, const Vector2u& postion = Vector2u());

    virtual ~Widget();

    virtual bool HitTest(const Vector2u& point) const;

    virtual void OnRender(Renderer* renderer);
    
    virtual bool OnMouseButtonPress(const MouseButtonPressEvent* event);
    virtual bool OnMouseButtonRelease(const MouseButtonReleaseEvent* event);
    virtual bool OnMouseMove(const MouseMoveEvent* event);

    Vector2u GetSize() const;
    void SetSize(const Vector2u& size);

    Vector2u GetPosition() const;
    void SetPosition(const Vector2u& position);

    Widget* GetParent() const;
    void SetParent(Widget* parent);

    template <uint64_t EventMask>
    void SetHandler(Handler* handler);

protected:
    template <class EventT, uint64_t EventMask>
    bool OnMouseEvent(const EventT* event);

protected:
    typedef std::map<uint64_t, Handler*> HandlerMap;

    Vector2u   size_;
    Vector2u   position_;

    Widget*    parent_;

    HandlerMap handlers_;
};

template <uint64_t EventMask>
void Widget::SetHandler(Handler* handler) {
    assert(handler != nullptr);

    handlers_[EventMask] = handler;
}

template <class EventT, uint64_t EventMask>
bool Widget::OnMouseEvent(const EventT* event) {
    assert(event != nullptr);

    if (!HitTest(event->GetPosition())) {
        return false;
    }

    if (handlers_.count(EventMask) == 0) {
        return false;
    }

    return handlers_[EventMask]->HandleEvent(event);
}

#endif // __WIDGET_HPP__
