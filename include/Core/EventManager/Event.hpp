#ifndef __EVENT_HPP__
#define __EVENT_HPP__

#include <cassert>
#include <cstdint>

enum EventCategory : uint64_t {
    kNoneEventCategory   = 0x00000000,
    kInputEventCategory  = 0x10000000,
    kWidgetEventCategory = 0x20000000,
    kCustomEventCategory = 0x40000000
};

class Event {
public:
    Event(uint64_t type);

    virtual ~Event();

    uint64_t GetType() const;

    static uint64_t GetStaticType();

protected:
    uint64_t type_;
};

#endif // __EVENT_HPP__