#include "EventDispatcher.hpp"

EventDispatcher* EventDispatcher::singleton{nullptr};

EventDispatcher* EventDispatcher::GetEventDispatcher() {
    if (singleton == nullptr) {
        singleton = new EventDispatcher();
    }

    return singleton;
}

EventDispatcher::EventDispatcher() {}

EventDispatcher::~EventDispatcher() {}

void EventDispatcher::DispatchEvents() {
    while (!queue_.empty()) {
        IEvent* event = queue_.front();
        queue_.pop_front();

        for (auto iterator = listeners_.begin(); iterator != listeners_.end(); ++iterator) {
            IEventListener* listener = *iterator;
            listener->OnEvent(event);
        }

        delete event;
    }
}

void EventDispatcher::RegisterListener(IEventListener* listener) {
    assert(listener != nullptr);

    listeners_.push_back(listener);
}

void EventDispatcher::UnregisterListener(IEventListener* listener) {
    assert(listener != nullptr);

    for (auto iterator = listeners_.begin(); iterator != listeners_.end(); ++iterator) {
        if (*iterator == listener) {
            listeners_.erase(iterator);
        }
    }
}
