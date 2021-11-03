#ifndef __EVENT_MANAGER_HPP__
#define __EVENT_MANAGER_HPP__

#include <cassert>
#include <cstdint>
#include <list>

#include "Core/EventManager/Event.hpp"
#include "Core/EventManager/IEventListener.hpp"

class EventManager {
private:
    static EventManager* singleton;

private:
    EventManager();

public:
    ~EventManager();

    void DispatchEvents();

    template <class EventT, class... Args>
    void SendEvent(Args&&... args);

    void RegisterListener(IEventListener* listener);

    void UnregisterListener(IEventListener* listener);

    static EventManager* GetEventManager();

private:
    std::list<Event*>          queue_;

    std::list<IEventListener*> listeners_;
};

template <class EventT, class... Args>
void EventManager::SendEvent(Args&&... args) {
    EventT* event = new(std::nothrow) EventT(std::forward<Args>(args)...);
    assert(event != nullptr);

    queue_.push_back(event);
}

#endif // __EVENT_MANAGER_HPP__
