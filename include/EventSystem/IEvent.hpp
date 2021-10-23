#ifndef __I_EVENT_HPP__
#define __I_EVENT_HPP__

#include <cstdint>

enum EventMask : uint64_t {
    kNoneEventMask                = 0x0000,

    kMouseButtonPressedEventMask  = 0x0001,
    kMouseButtonReleasedEventMask = 0x0002,
    kMouseMoveEventMask           = 0x0004,

    kMouseWheelEventMask          = 0x0008,

    kKeyReleasedEventMask         = 0x0010,
    kKeyPressedEventMask          = 0x0020,

    kQuitEventMask                = 0x0040
};

class IEvent {
public:
    virtual ~IEvent() {}

    virtual uint64_t GetMask() const = 0;
};

#endif // __I_EVENT_HPP__
