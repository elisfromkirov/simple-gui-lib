#ifndef __I_EVENT_HPP__
#define __I_EVENT_HPP__

const uint64_t kNoneEventMask = 0;

class IEvent {
public:
    virtual ~IEvent() {}

    virtual uint64_t GetMask() const = 0;
};

#endif // __I_EVENT_HPP__
