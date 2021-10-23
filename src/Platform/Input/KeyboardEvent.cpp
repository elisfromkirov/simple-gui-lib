#include "KeyboardEvent.hpp"

KeyboardEvent::KeyboardEvent(uint32_t key, bool pressed)
    : key_{key}, pressed_{pressed} {}

KeyboardEvent::~KeyboardEvent() {}

uint64_t KeyboardEvent::GetMask() const {
    return pressed_ ? kKeyPressedEventMask : kKeyReleasedEventMask;
}

uint32_t KeyboardEvent::GetKey() const {
    return key_;
}

bool KeyboardEvent::IsPressed() const {
    return pressed_;
}
