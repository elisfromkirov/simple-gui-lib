#ifndef __EVENT_DISPATCHER_HPP__
#define __EVENT_DISPATCHER_HPP__

#include "Core/EventManager/IEventListener.hpp"
#include "Core/EventManager/EventHandler.hpp"
#include "Core/EventManager/EventManager.hpp"
#include "Core/Functor/MethodWrap.hpp"

template <class TargetT>
class EventDispatcher : IEventListener {
public:
    EventDispatcher(TargetT* target);
    virtual ~EventDispatcher() override;

    virtual void OnEvent(const Event* event) override;

    template <class EventT>
    void SetEventHandler(typename MethodWrap<TargetT, void(const EventT*)>::MethodPointer method_pointer);

protected:
    TargetT*                   target_;

    std::list<IEventListener*> handlers_;
};

template <class TargetT>
EventDispatcher<TargetT>::EventDispatcher(TargetT* target) 
    : target_{target} {
    EventManager* event_manager = EventManager::GetInstance();
    assert(event_manager != nullptr);

    event_manager->RegisterListener(this);
}

template <class TargetT>
EventDispatcher<TargetT>::~EventDispatcher() {
    EventManager* event_manager = EventManager::GetInstance();
    assert(event_manager != nullptr);

    for (auto iter = handlers_.begin(); iter != handlers_.end(); ++iter) {
        IEventListener* handler = *iter;

        event_manager->UnregisterListener(handler);       

        delete handler;
    }
}

template <class TargetT>
void EventDispatcher<TargetT>::OnEvent(const Event* event) {
    assert(event != nullptr);

    for (auto iter = handlers_.begin(); iter != handlers_.end(); ++iter) {
        IEventListener* handler = *iter;

        handler->OnEvent(event);
    }
}

template <class TargetT>
template <class EventT>
void EventDispatcher<TargetT>::SetEventHandler(
    typename MethodWrap<TargetT, void(const EventT*)>::MethodPointer method_pointer) { 
    handlers_.push_back(new EventHandler<EventT, MethodWrap<TargetT, void(const EventT*)>>(target_, method_pointer));

    EventManager* event_manager = EventManager::GetInstance();
    assert(event_manager != nullptr);

    event_manager->RegisterListener(handlers_.back());
}

#endif // __EVENT_DISPATCHER_HPP__