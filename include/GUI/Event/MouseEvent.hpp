#ifndef __MOUSE_EVENT_HPP__
#define __MOUSE_EVENT_HPP__

#include "IEvent.hpp"
#include "InputEventMask.hpp"
#include "Vector2.hpp"

enum MouseButton : uint32_t {
    kNoneButton,
    kLeftButton,
    kRightButton,
    kMiddleButton,
    kX1Button,
    kX2Button
};

class IMouseEvent : public IEvent {
public:
    IMouseEvent(const Vector2i& position, MouseButton button, bool pressed);

    const Vector2i& GetPosition() const;

    MouseButton GetButton() const;

    bool IsButtonPressed() const;

protected:
    Vector2i    position_;
    MouseButton button_;
    bool        pressed_;
};

class MouseButtonPressEvent : public IMouseEvent {
public:
    MouseButtonPressEvent(const Vector2i& position, MouseButton button, bool pressed);
    virtual ~MouseButtonPressEvent() override;

    virtual uint64_t GetCategory() const override;

    virtual uint64_t GetMask() const override;
};

class MouseButtonReleaseEvent : public IMouseEvent {
public:
    MouseButtonReleaseEvent(const Vector2i& position, MouseButton button, bool pressed);
    virtual ~MouseButtonReleaseEvent() override;

    virtual uint64_t GetCategory() const override;

    virtual uint64_t GetMask() const override;
};

class MouseMoveEvent : public IMouseEvent {
public:
    MouseMoveEvent(const Vector2i& position, MouseButton button, bool Press);
    virtual ~MouseMoveEvent() override;

    virtual uint64_t GetCategory() const override;

    virtual uint64_t GetMask() const override;
};

#endif // __MOUSE_EVENT_HPP__
