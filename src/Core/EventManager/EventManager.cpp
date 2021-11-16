#include "Core/EventManager/Event.hpp"
#include "Core/EventManager/EventManager.hpp"
#include "Core/EventManager/IEventListener.hpp"

EventManager* EventManager::singleton{nullptr};

EventManager::EventManager() {}

EventManager::~EventManager() {}

void EventManager::DispatchEvents() {
    while (!queue_.empty()) {
        Event* event = queue_.front();
        queue_.pop_front();

        for (auto iter = listeners_.begin(); iter != listeners_.end(); ++iter) {
            IEventListener* listener = *iter;
            listener->OnEvent(event);
        }

        delete event;
    }
}

void EventManager::RegisterListener(IEventListener* listener) {
    assert(listener != nullptr);

    listeners_.push_back(listener);
}

void EventManager::UnregisterListener(IEventListener* listener) {
    assert(listener != nullptr);

    listeners_.remove(listener);
}

EventManager* EventManager::GetEventManager() {
    if (singleton == nullptr) {
        singleton = new EventManager();
    }

    return singleton;
}
