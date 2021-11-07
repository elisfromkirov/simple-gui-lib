#include "GUI/Event/InputEvent.hpp"

MouseEvent::MouseEvent(uint64_t type, const Vector2u& position, MouseButton button, bool pressed)
    : Event{type},
      position_{position},
      button_{button},
      pressed_{pressed} {}

MouseEvent::~MouseEvent() {}

const Vector2u& MouseEvent::GetMousePosition() const {
    return position_;
}

MouseButton MouseEvent::GetPressedButton() const {
    return button_;
}

bool MouseEvent::IsButtonPressed() const {
    return pressed_;    
}

MouseButtonPressEvent::MouseButtonPressEvent(const Vector2u& position, MouseButton button)
    : MouseEvent{kMouseButtonPress, position, button, true} {}

MouseButtonPressEvent::~MouseButtonPressEvent() {}

MouseButtonReleaseEvent::MouseButtonReleaseEvent(const Vector2u& position, MouseButton button)
    : MouseEvent{kMouseButtonRelease, position, button, false} {}

MouseButtonReleaseEvent::~MouseButtonReleaseEvent() {}

MouseMoveEvent::MouseMoveEvent(const Vector2u& position, MouseButton button, bool pressed)
    : MouseEvent{kMouseMove, position, button, pressed} {}

MouseMoveEvent::~MouseMoveEvent() {}

MouseHoverEvent::MouseHoverEvent(const MouseEvent* event)
    : MouseEvent{kMouseHover, event->GetMousePosition(), event->GetPressedButton(), 
                 event->IsButtonPressed()} {}

MouseHoverEvent::~MouseHoverEvent() {}

MouseLeaveEvent::MouseLeaveEvent(const MouseEvent* event)
    : MouseEvent{kMouseLeave, event->GetMousePosition(), event->GetPressedButton(), 
                 event->IsButtonPressed()} {}

MouseLeaveEvent::~MouseLeaveEvent() {}

// ------------------------------------------------------------------------- //

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
    : KeyEvent{kKeyPress, key, alt, control, shift, system} {}

KeyPressEvent::~KeyPressEvent() {}

KeyReleaseEvent::KeyReleaseEvent(Key key, bool alt, bool control, bool shift, bool system)
    : KeyEvent{kKeyRelease, key, alt, control, shift, system} {}

KeyReleaseEvent::~KeyReleaseEvent() {}
