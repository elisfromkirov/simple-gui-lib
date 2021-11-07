#ifndef __INPUT_EVENT_HPP__
#define __INPUT_EVENT_HPP__

#include <cassert>
#include <cstdint>

#include "Core/EventManager/Event.hpp"
#include "Core/Math/Vector2.hpp"

enum InputEventType : uint64_t {
    kNoneInputEvent     = kInputEventCategory | 0x00000000,

    kMouseButtonPress   = kInputEventCategory | 0x00000001,
    kMouseButtonRelease = kInputEventCategory | 0x00000002,
    kMouseMove          = kInputEventCategory | 0x00000004,
    kMouseHover         = kInputEventCategory | 0x00000008,
    kMouseLeave         = kInputEventCategory | 0x00000010,

    kKeyPress           = kInputEventCategory | 0x00000020,
    kKeyRelease         = kInputEventCategory | 0x00000040
};

// ------------------------------------------------------------------------- //

enum MouseButton : uint32_t {
    kNoneButton,
    kLeftButton,
    kRightButton,
    kMiddleButton,
    kX1Button,
    kX2Button
};

class MouseEvent : public Event {
public:
    MouseEvent(uint64_t type, const Vector2u& position, MouseButton button, bool pressed);
    
    virtual ~MouseEvent() override;

    const Vector2u& GetMousePosition() const;

    MouseButton GetPressedButton() const;

    bool IsButtonPressed()  const;

private:
    Vector2u    position_;
    MouseButton button_;
    bool        pressed_;
};

class MouseButtonPressEvent : public MouseEvent {
public:
    MouseButtonPressEvent(const Vector2u& position, MouseButton button);

    virtual ~MouseButtonPressEvent() override;
};

class MouseButtonReleaseEvent : public MouseEvent {
public:
    MouseButtonReleaseEvent(const Vector2u& position, MouseButton button);

    virtual ~MouseButtonReleaseEvent() override;
};

class MouseMoveEvent : public MouseEvent {
public:
    MouseMoveEvent(const Vector2u& position, MouseButton button, bool pressed);

    virtual ~MouseMoveEvent() override;
};

class MouseHoverEvent : public MouseEvent {
public:
    MouseHoverEvent(const MouseEvent* event);

    virtual ~MouseHoverEvent() override;
};

class MouseLeaveEvent : public MouseEvent {
public:
    MouseLeaveEvent(const MouseEvent* event);

    virtual ~MouseLeaveEvent() override;
};

// ------------------------------------------------------------------------- //

enum Key : uint32_t {
    kNoneKey,

    kKeyA,
    kKeyB,
    kKeyC,
    kKeyD,
    kKeyE,
    kKeyF,
    kKeyG,
    kKeyH,
    kKeyI,
    kKeyJ,
    kKeyK,
    kKeyL,
    kKeyM,
    kKeyN,
    kKeyO,
    kKeyP,
    kKeyQ,
    kKeyR,
    kKeyS,
    kKeyT,
    kKeyU,
    kKeyV,
    kKeyW,
    kKeyX,
    kKeyY,
    kKeyZ,

    kKey0,
    kKey1,
    kKey2,
    kKey3,
    kKey4,
    kKey5,
    kKey6,
    kKey7,
    kKey8,
    kKey9,

    kLeftArrow,
    kRightArrow,
    kUpArrow,
    kDownArrow
};

class KeyEvent : public Event {
public:
    KeyEvent(uint64_t type, Key key, bool alt, bool control, bool shift, bool system);

    virtual ~KeyEvent() override;

    Key GetKey() const;

    bool IsAltPressed() const;

    bool IsControlPressed() const;

    bool IsShiftPressed() const;

    bool IsSystemPressed() const;

protected:
    Key  key_;
    bool alt_;
    bool control_;
    bool shift_;
    bool system_;
};

class KeyPressEvent : public KeyEvent {
public:
    KeyPressEvent(Key key, bool alt, bool control, bool shift, bool system);

    virtual ~KeyPressEvent() override;
};

class KeyReleaseEvent : public KeyEvent {
public:
    KeyReleaseEvent(Key key, bool alt, bool control, bool shift, bool system);

    virtual ~KeyReleaseEvent() override;
};

#endif // __INPUT_EVENT_HPP__
