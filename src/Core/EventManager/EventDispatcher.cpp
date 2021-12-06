#include "Core/EventManager/EventDispatcher.hpp"
#include "Core/EventManager/EventManager.hpp"

EventDispatcher::EventDispatcher() {}

EventDispatcher::~EventDispatcher() {
    for (auto iter = event_filters_.begin(); iter != event_filters_.end(); ++iter) {
        delete iter->second;
    }

    for (auto iter = event_handlers_.begin(); iter != event_handlers_.end(); ++iter) {
        delete iter->second;
    }
}

bool EventDispatcher::OnEvent(const Event* event) {
    assert(event != nullptr);

    return HandleEvent(event);
}

bool EventDispatcher::FilterEvent(const Event* event) {
    assert(event != nullptr);

    if (event_filters_.count(event->GetType()) == 0) {
        return false;
    }
    return event_filters_[event->GetType()]->OnEvent(event);
}

bool EventDispatcher::HandleEvent(const Event* event) {
    assert(event != nullptr);

    if (event_handlers_.count(event->GetType()) == 0) {
        return false;
    }
    return event_handlers_[event->GetType()]->OnEvent(event);
}