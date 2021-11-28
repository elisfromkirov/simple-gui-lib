#include "Core/EventManager/EventManager.hpp"

EventManager* EventManager::singleton{nullptr};

EventManager::EventManager() {}

EventManager::~EventManager() {}

EventManager* EventManager::GetInstance() {
    if (singleton == nullptr) {
        singleton = new EventManager();
    }

    return singleton;
}

void EventManager::Release() {
    delete this;
}

void EventManager::DispatchEvents() {
    while (!queue_.empty()) {
        Event* event = queue_.front();
        queue_.pop_front();

        for (auto iter = event_listeners_.begin(); iter != event_listeners_.end(); ++iter) {
            (*iter)->OnEvent(event);
        }

        delete event;
    }
}

void EventManager::RegisterListener(IEventListener* event_listener) {
    assert(event_listener != nullptr);

    event_listeners_.push_back(event_listener);
}

void EventManager::UnregisterListener(IEventListener* event_listener) {
    assert(event_listener != nullptr);

    event_listeners_.remove(event_listener);
}