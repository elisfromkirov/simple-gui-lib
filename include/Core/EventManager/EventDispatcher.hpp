#ifndef __EVENT_DISPATCHER_HPP__
#define __EVENT_DISPATCHER_HPP__

#include "Core/EventManager/Event.hpp"
#include "Core/EventManager/EventCallback.hpp"
#include "Core/EventManager/IEventListener.hpp"

class EventDispatcher : public IEventListener {
public:
    EventDispatcher();
    virtual ~EventDispatcher() override;

    virtual bool OnEvent(const Event* event) override;

    template <class T, class EventT>
    void SetEventCallback(typename EventCallback<T, EventT>::ObjectPointer object,
                          typename EventCallback<T, EventT>::MethodPointer method);

protected:
    bool CallEventCallback(const Event* event);

protected:
    struct EventCallbackData {
        IEventListener* event_callback;
        uint64_t        event_type;
    };
    std::list<EventCallbackData> event_callbacks_;
};

template <class T, class EventT>
void EventDispatcher::SetEventCallback(typename EventCallback<T, EventT>::ObjectPointer object,
                                       typename EventCallback<T, EventT>::MethodPointer method) {
    event_callbacks_.push_back(EventCallbackData{new EventCallback<T, EventT>(object, method),
                                                 EventT::GetStaticType()});
}

#endif // __EVENT_DISPATCHER_HPP__