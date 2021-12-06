#ifndef __EVENT_DISPATCHER_HPP__
#define __EVENT_DISPATCHER_HPP__

#include <cassert>
#include <cstdint>
#include <unordered_map>

#include "Core/EventManager/Event.hpp"
#include "Core/EventManager/EventCallback.hpp"
#include "Core/EventManager/IEventListener.hpp"

class EventDispatcher : public IEventListener {
public:
    EventDispatcher();
    virtual ~EventDispatcher() override;

    virtual bool OnEvent(const Event* event) override;

    template <class T, class EventT>
    void SetEventFilter(typename EventCallback<T, EventT>::ObjectPointer object,
                        typename EventCallback<T, EventT>::MethodPointer method);

    template <class T, class EventT>
    void SetEventHandler(typename EventCallback<T, EventT>::ObjectPointer object,
                         typename EventCallback<T, EventT>::MethodPointer method);

protected:
    bool FilterEvent(const Event* event);

    bool HandleEvent(const Event* event);

protected:
    std::unordered_map<uint64_t, IEventListener*> event_filters_;
    std::unordered_map<uint64_t, IEventListener*> event_handlers_;
};

template <class T, class EventT>
void EventDispatcher::SetEventFilter(typename EventCallback<T, EventT>::ObjectPointer object,
                                     typename EventCallback<T, EventT>::MethodPointer method) {
    if (event_filters_.count(EventT::GetStaticType()) != 0) {
        delete event_filters_[EventT::GetStaticType()];
    }

    event_filters_[EventT::GetStaticType()] = new EventCallback<T, EventT>(object, method);
}

template <class T, class EventT>
void EventDispatcher::SetEventHandler(typename EventCallback<T, EventT>::ObjectPointer object,
                                      typename EventCallback<T, EventT>::MethodPointer method) {
    if (event_filters_.count(EventT::GetStaticType()) != 0) {
        delete event_handlers_[EventT::GetStaticType()];
    }

    event_handlers_[EventT::GetStaticType()] = new EventCallback<T, EventT>(object, method);
}

#endif // __EVENT_DISPATCHER_HPP__