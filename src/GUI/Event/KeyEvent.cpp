#include "KeyEvent.hpp"

IKeyEvent::IKeyEvent(Key key, bool alt, bool control, bool shift, bool system)
    : key_{key},
      alt_{alt},
      control_{control},
      shift_{shift},
      system_{system} {}

Key IKeyEvent::GetKey() const {
    return key_;
}

bool IKeyEvent::IsAltPressed() const {
    return alt_;
}

bool IKeyEvent::IsCtrlPressed() const {
    return control_;
}

bool IKeyEvent::IsShiftPressed() const {
    return shift_;
}

bool IKeyEvent::IsSystemPressed() const {
    return system_;
}

KeyPressEvent::KeyPressEvent(Key key, bool alt, bool control, bool shift, bool system)
    : IKeyEvent{key, alt, control, shift, system} {}

KeyPressEvent::~KeyPressEvent() {}

uint64_t KeyPressEvent::GetCategory() const {
    return kInputEventCategory;
}

uint64_t KeyPressEvent::GetMask() const {
    return kKeyPress;
}

KeyReleaseEvent::KeyReleaseEvent(Key key, bool alt, bool control, bool shift, bool system)
    : IKeyEvent{key, alt, control, shift, system} {}

KeyReleaseEvent::~KeyReleaseEvent() {}

uint64_t KeyReleaseEvent::GetCategory() const {
    return kInputEventCategory;
}

uint64_t KeyReleaseEvent::GetMask() const {
    return kKeyRelease;
}
