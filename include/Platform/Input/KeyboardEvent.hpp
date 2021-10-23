#ifndef __KEYBOARD_EVENT_HPP__
#define __KEYBOARD_EVENT_HPP__

#include <cassert>
#include <cstdint>

#include "IEvent.hpp"

class KeyboardEvent : public IEvent {
public:
    KeyboardEvent(uint32_t key, bool pressed);
    virtual ~KeyboardEvent() override;

    virtual uint64_t GetMask() const override;
    
    uint32_t GetKey() const;

    bool IsPressed() const;

private:
    uint32_t key_;
    bool     pressed_;
};

#endif // __KEYBOARD_EVENT_HPP__
