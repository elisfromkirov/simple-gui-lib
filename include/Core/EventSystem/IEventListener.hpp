#ifndef __I_EVENT_LISTENER_HPP__
#define __I_EVENT_LISTENER_HPP__

#include "IEvent.hpp"

class IEventListener {
public:
    virtual ~IEventListener() {}

    virtual bool OnEvent(const IEvent* event) = 0;
};

#endif // __I_EVENT_LISTENER_HPP__
