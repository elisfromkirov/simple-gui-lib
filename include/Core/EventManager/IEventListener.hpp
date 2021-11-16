#ifndef __I_EVENT_LISTENER_HPP__
#define __I_EVENT_LISTENER_HPP__

class Event;

class IEventListener {
public:
    virtual ~IEventListener() {}

    virtual void OnEvent(const Event* event) = 0;
};

#endif // __I_EVENT_LISTENER_HPP__