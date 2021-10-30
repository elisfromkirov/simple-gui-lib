#ifndef __I_EVENT_HPP__
#define __I_EVENT_HPP__

#include <cstdint>

enum EventCategory : uint64_t {
    kNoneEventCategory   = 0x00000000,
    kInputEventCategory  = 0x00010000,
    kGUIEventCategory    = 0x00020000,
    kCustomEventCategory = 0x00040000
};

class IEvent {
public:
    virtual ~IEvent() {}

    virtual uint64_t GetCategory() const = 0;

    virtual uint64_t GetMask() const = 0;
};

#endif // __I_EVENT_HPP__
