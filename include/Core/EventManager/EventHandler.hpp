#ifndef __EVENT_HANDLER_HPP__
#define __EVENT_HANDLER_HPP__

#include "Core/EventManager/Event.hpp"
#include "Core/EventManager/IEventListener.hpp"

template <class EventT, class Functor>
class EventHandler : public IEventListener {
public:
    template <class ...Args>
    EventHandler(Args&&... args);

    virtual ~EventHandler() override;

    virtual void OnEvent(const Event* event) override;

protected:
    Functor functor_;
};

template <class EventT, class Functor>
template <class ...Args>
EventHandler<EventT, Functor>::EventHandler(Args&&... args)
    : functor_(std::forward<Args>(args)...) {}

template <class EventT, class Functor>
EventHandler<EventT, Functor>::~EventHandler() {}

template <class EventT, class Functor>
void EventHandler<EventT, Functor>::OnEvent(const Event* event) {
    assert(event != nullptr);

    if (event->GetType() == EventT::GetStaticType()) {
        functor_(static_cast<const EventT*>(event));
    }
}

#endif // __EVENT_HANDLER_HPP__