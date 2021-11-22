#ifndef __INPUT_EVENT_HPP__
#define __INPUT_EVENT_HPP__

#include <cassert>
#include <cstdint>

#include "Core/EventManager/Event.hpp"
#include "Core/Math/Vector2.hpp"

enum InputEventType : uint64_t {
    kNoneInputEvent          = kInputEventCategory | 0x00000000,

    kMouseButtonPressEvent   = kInputEventCategory | 0x00000001,
    kMouseButtonReleaseEvent = kInputEventCategory | 0x00000002,
    kMouseMoveEvent          = kInputEventCategory | 0x00000004,

    kKeyPressEvent           = kInputEventCategory | 0x00000008,
    kKeyReleaseEvent         = kInputEventCategory | 0x00000010
};

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
    MouseEvent(uint64_t type, const Vector2i& position, MouseButton button, bool pressed);
    
    virtual ~MouseEvent() override;

    void SetMousePosition(const Vector2i& position) const;
    
    const Vector2i& GetMousePosition() const;

    MouseButton GetPressedButton() const;

    bool IsButtonPressed()  const;

private:
    mutable Vector2i position_;
    MouseButton      button_;
    bool             pressed_;
};

class MouseButtonPressEvent : public MouseEvent {
public:
    MouseButtonPressEvent(const Vector2i& position, MouseButton button);

    virtual ~MouseButtonPressEvent() override;

    static uint64_t GetStaticType();
};

class MouseButtonReleaseEvent : public MouseEvent {
public:
    MouseButtonReleaseEvent(const Vector2i& position, MouseButton button);

    virtual ~MouseButtonReleaseEvent() override;

    static uint64_t GetStaticType();
};

class MouseMoveEvent : public MouseEvent {
public:
    MouseMoveEvent(const Vector2i& position, MouseButton button, bool pressed);

    virtual ~MouseMoveEvent() override;

    static uint64_t GetStaticType();
};

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

    static uint64_t GetStaticType();
};

class KeyReleaseEvent : public KeyEvent {
public:
    KeyReleaseEvent(Key key, bool alt, bool control, bool shift, bool system);

    virtual ~KeyReleaseEvent() override;

    static uint64_t GetStaticType();
};

#endif // __INPUT_EVENT_HPP__