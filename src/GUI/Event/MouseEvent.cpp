#include "MouseEvent.hpp"

IMouseEvent::IMouseEvent(const Vector2u& position, MouseButton button, bool pressed)
    : position_{position},
      button_{button},
      pressed_{pressed} {}

const Vector2u& IMouseEvent::GetPosition() const {
    return position_;
}

MouseButton IMouseEvent::GetButton() const {
    return button_;
}

bool IMouseEvent::IsButtonPressed() const {
    return pressed_;    
}

MouseButtonPressEvent::MouseButtonPressEvent(const Vector2u& position, MouseButton button,
                                             bool pressed)
    : IMouseEvent{position, button, pressed} {}

MouseButtonPressEvent::~MouseButtonPressEvent() {}

uint64_t MouseButtonPressEvent::GetCategory() const {
    return kInputEventCategory;
}

uint64_t MouseButtonPressEvent::GetMask() const {
    return kMouseButtonPress;
}

MouseButtonReleaseEvent::MouseButtonReleaseEvent(const Vector2u& position, MouseButton button, 
                                                 bool pressed)
    : IMouseEvent{position, button, pressed} {}

MouseButtonReleaseEvent::~MouseButtonReleaseEvent() {}

uint64_t MouseButtonReleaseEvent::GetCategory() const {
    return kInputEventCategory;
}

uint64_t MouseButtonReleaseEvent::GetMask() const {
    return kMouseButtonRelease;
}

MouseMoveEvent::MouseMoveEvent(const Vector2u& position, MouseButton button, bool pressed)
    : IMouseEvent{position, button, pressed} {}

MouseMoveEvent::~MouseMoveEvent() {}

uint64_t MouseMoveEvent::GetCategory() const {
    return kInputEventCategory;    
}

uint64_t MouseMoveEvent::GetMask() const {
    return kMouseMove;
}
