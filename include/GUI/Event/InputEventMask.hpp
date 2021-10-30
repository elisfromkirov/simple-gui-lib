#ifndef __INPUT_EVENT_HPP__
#define __INPUT_EVENT_HPP__

#include "IEvent.hpp"

enum InputEventMask : uint64_t {
    kNoneEvent          = kInputEventCategory | 0x00000000,

    kMouseButtonPress   = kInputEventCategory | 0x00000001,
    kMouseButtonRelease = kInputEventCategory | 0x00000002,
    kMouseMove          = kInputEventCategory | 0x00000004,

    kKeyPress           = kInputEventCategory | 0x00000008,
    kKeyRelease         = kInputEventCategory | 0x00000010
};

#endif // __INPUT_EVENT_HPP__
