#include "MouseEvent.hpp"

IMouseEvent::IMouseEvent(Vector2<int32_t> position, uint32_t button, bool pressed)
    : position_{position}, button_{button}, pressed_{pressed} {}

Vector2<int32_t> IMouseEvent::GetPosition() const {
    return position_;
}

uint32_t IMouseEvent::GetPressedButton() const {
    return button_;
}

bool IMouseEvent::IsPressed() const {
    return pressed_;
}

MouseButtonEvent::MouseButtonEvent(Vector2<int32_t> position, uint32_t button, bool pressed)
    : IMouseEvent{position, button, pressed} {}

MouseButtonEvent::~MouseButtonEvent() {}

uint64_t MouseButtonEvent::GetMask() const {
    return pressed_ ? kMouseButtonPressedEventMask : kMouseButtonReleasedEventMask;
}

MouseMoveEvent::MouseMoveEvent(Vector2<int32_t> position, uint32_t button, bool pressed)
    : IMouseEvent{position, button, pressed} {}

MouseMoveEvent::~MouseMoveEvent() {}

uint64_t MouseMoveEvent::GetMask() const {
    return kMouseMoveEventMask;
}
