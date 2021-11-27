#include "Core/EventManager/EventDispatcher.hpp"
#include "Core/EventManager/EventManager.hpp"

EventDispatcher::EventDispatcher() {}

EventDispatcher::~EventDispatcher() {
    for (auto iter = event_callbacks_.begin(); iter != event_callbacks_.end(); ++iter) {
        delete iter->event_callback;
    }
}

bool EventDispatcher::OnEvent(const Event* event) {
    assert(event != nullptr);

    return CallEventCallback(event);
}

bool EventDispatcher::CallEventCallback(const Event* event) {
    assert(event != nullptr);

    for (auto iter = event_callbacks_.begin(); iter != event_callbacks_.end(); ++iter) {
        if (event->GetType() == iter->event_type) {
            bool handled = iter->event_callback->OnEvent(event);
            if (handled) {
                return true;
            }
        }
    }

    return false;
}