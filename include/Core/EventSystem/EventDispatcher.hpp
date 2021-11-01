#ifndef __EVENT_DISPATCHER_HPP__
#define __EVENT_DISPATCHER_HPP__

#include <cassert>
#include <cstdint>
#include <list>

#include "IEvent.hpp"
#include "IEventListener.hpp"

class EventDispatcher {
public:
    static EventDispatcher* GetEventDispatcher();
    
private:
    static EventDispatcher* singleton;

public:
    ~EventDispatcher();

    void DispatchEvents();

    template <typename EventT, typename... Args>
    void SendEvent(Args&&... args);

    void AddListener(IEventListener* listener);
    void RemoveListener(IEventListener* listener);

private:
    EventDispatcher();

    std::list<IEvent*> queue_; 

    std::list<IEventListener*> listeners_;
};

#include <stdio.h>

template <class EventT, class... Args>
void EventDispatcher::SendEvent(Args&&... args) {
    EventT* event = new EventT(std::forward<Args>(args)...);

    queue_.push_back(event);
}

#endif // __EVENT_DISPATCHER_HPP__
