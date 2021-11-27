#ifndef __EVENT_MANAGER_HPP__
#define __EVENT_MANAGER_HPP__

#include <cassert>
#include <cstdint>
#include <list>

#include "Core/EventManager/Event.hpp"
#include "Core/EventManager/IEventListener.hpp"

class EventManager {
public:
    static EventManager* GetInstance();

    void Release();

    void DispatchEvents();

    template <class EventT, class... Args>
    void PostEvent(Args&&... args);

    void RegisterListener  (IEventListener* event_listener);
    void UnregisterListener(IEventListener* event_listener);

private:
    EventManager();
    ~EventManager();

    EventManager(const EventManager& other) = delete;
    EventManager& operator=(const EventManager& other) = delete;

    static EventManager* singleton;

private:
    std::list<Event*>          queue_;

    std::list<IEventListener*> event_listeners_;
};

template <class EventT, class... Args>
void EventManager::PostEvent(Args&&... args) {
    EventT* event = new EventT(std::forward<Args>(args)...);
    assert(event != nullptr);

    queue_.push_back(event);
}

#endif // __EVENT_MANAGER_HPP__