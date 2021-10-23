#ifndef __MOUSE_EVENT_HPP__
#define __MOUSE_EVENT_HPP__

#include <cassert>
#include <cstdint>

#include "IEvent.hpp"
#include "Vector2.hpp"

enum MouseButton : uint32_t {
    kNoneButon    = 0,
    kButtonLeft   = 1,
    kButtonRight  = 2,
    kButtonMiddle = 3,
    kButtonX1     = 4,
    kButtonX2     = 5
};

class IMouseEvent : public IEvent {
public:
    IMouseEvent(Vector2<int32_t> position, uint32_t button, bool pressed);

    Vector2<int32_t> GetPosition() const;

    uint32_t GetPressedButton() const;

    bool IsPressed() const;

protected:
    Vector2<int32_t> position_;
    uint32_t        button_;
    bool            pressed_;
};

class MouseButtonEvent : public IMouseEvent {
public:
    MouseButtonEvent(Vector2<int32_t> position, uint32_t button, bool pressed);
    virtual ~MouseButtonEvent() override;

    virtual uint64_t GetMask() const override;
};

class MouseMoveEvent : public IMouseEvent {
public:
    MouseMoveEvent(Vector2<int32_t> position, uint32_t button, bool pressed);
    virtual ~MouseMoveEvent() override;

    virtual uint64_t GetMask() const override;
};

#endif // __MOUSE_EVENT_HPP__
