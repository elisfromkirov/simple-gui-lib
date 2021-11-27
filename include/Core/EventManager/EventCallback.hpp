#ifndef __EVENT_HANDLER_HPP__
#define __EVENT_HANDLER_HPP__

#include <cassert>
#include <cstdint>
#include <list>

#include "Core/EventManager/Event.hpp"
#include "Core/EventManager/IEventListener.hpp"

template <class T, class EventT>
class EventCallback : public IEventListener {
public:
    typedef T* ObjectPointer;
    typedef bool (T::*MethodPointer)(const EventT*);

public:
    EventCallback(ObjectPointer object, MethodPointer method);

    virtual ~EventCallback() override;

    virtual bool OnEvent(const Event* event) override;

protected:
    ObjectPointer object_;
    MethodPointer method_;
};

template <class T, class EventT>
EventCallback<T, EventT>::EventCallback(typename EventCallback<T, EventT>::ObjectPointer object,
                                        typename EventCallback<T, EventT>::MethodPointer method)
    : object_{object},
      method_{method} {}

template <class T, class EventT>
EventCallback<T, EventT>::~EventCallback() {}

template <class T, class EventT>
bool EventCallback<T, EventT>::OnEvent(const Event* event) {
    assert(event != nullptr);

    if (event->GetType() == EventT::GetStaticType()) {
        return (object_->*method_)(static_cast<const EventT*>(event));
    }
    return false;
}

#endif // __EVENT_HANDLER_HPP__