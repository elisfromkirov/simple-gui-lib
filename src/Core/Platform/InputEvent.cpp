#include "Core/Platform/InputEvent.hpp"

MouseEvent::MouseEvent(uint64_t type, const Vector2i& position, MouseButton button, bool pressed)
    : Event{type},
      position_{position},
      button_{button},
      pressed_{pressed} {}

MouseEvent::~MouseEvent() {}

void MouseEvent::SetMousePosition(const Vector2i& position) const {
    position_ = position;
}

const Vector2i& MouseEvent::GetMousePosition() const {
    return position_;
}

MouseButton MouseEvent::GetPressedButton() const {
    return button_;
}

bool MouseEvent::IsButtonPressed() const {
    return pressed_;    
}

MouseButtonPressEvent::MouseButtonPressEvent(const Vector2i& position, MouseButton button)
    : MouseEvent{kMouseButtonPressEvent, position, button, true} {}

MouseButtonPressEvent::~MouseButtonPressEvent() {}

uint64_t MouseButtonPressEvent::GetStaticType() {
    return kMouseButtonPressEvent;
}

MouseButtonReleaseEvent::MouseButtonReleaseEvent(const Vector2i& position, MouseButton button)
    : MouseEvent{kMouseButtonReleaseEvent, position, button, false} {}

MouseButtonReleaseEvent::~MouseButtonReleaseEvent() {}

uint64_t MouseButtonReleaseEvent::GetStaticType() {
    return kMouseButtonReleaseEvent;
}

MouseMoveEvent::MouseMoveEvent(const Vector2i& position, MouseButton button, bool pressed)
    : MouseEvent{kMouseMoveEvent, position, button, pressed} {}

MouseMoveEvent::~MouseMoveEvent() {}

uint64_t MouseMoveEvent::GetStaticType() {
    return kMouseMoveEvent;
}

KeyEvent::KeyEvent(uint64_t type, Key key, bool alt, bool control, bool shift, bool system)
    : Event{type},
      key_{key},
      alt_{alt},
      control_{control},
      shift_{shift},
      system_{system} {}

KeyEvent::~KeyEvent() {}

Key KeyEvent::GetKey() const {
    return key_;
}

bool KeyEvent::IsAltPressed() const {
    return alt_;
}

bool KeyEvent::IsControlPressed() const {
    return control_;
}

bool KeyEvent::IsShiftPressed() const {
    return shift_;
}

bool KeyEvent::IsSystemPressed() const {
    return system_;
}

KeyPressEvent::KeyPressEvent(Key key, bool alt, bool control, bool shift, bool system)
    : KeyEvent{kKeyPressEvent, key, alt, control, shift, system} {}

KeyPressEvent::~KeyPressEvent() {}

uint64_t KeyPressEvent::GetStaticType() {
    return kKeyPressEvent;
}

KeyReleaseEvent::KeyReleaseEvent(Key key, bool alt, bool control, bool shift, bool system)
    : KeyEvent{kKeyReleaseEvent, key, alt, control, shift, system} {}

KeyReleaseEvent::~KeyReleaseEvent() {}

uint64_t KeyReleaseEvent::GetStaticType() {
    return kKeyReleaseEvent;
}
