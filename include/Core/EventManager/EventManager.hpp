#ifndef __EVENT_MANAGER_HPP__
#define __EVENT_MANAGER_HPP__

#include <cassert>
#include <cstdint>
#include <list>

class Event;
class IEventListener;

class EventManager {
private:
    static EventManager* singleton;

private:
    EventManager();

public:
    ~EventManager();

    void DispatchEvents();

    template <class EventT, class... Args>
    void PostEvent(Args&&... args);

    void RegisterListener(IEventListener* listener);

    void UnregisterListener(IEventListener* listener);

    static EventManager* GetEventManager();

private:
    std::list<Event*>          queue_;

    std::list<IEventListener*> listeners_;
};

template <class EventT, class... Args>
void EventManager::PostEvent(Args&&... args) {
    EventT* event = new(std::nothrow) EventT(std::forward<Args>(args)...);
    assert(event != nullptr);

    queue_.push_back(event);
}

#endif // __EVENT_MANAGER_HPP__
