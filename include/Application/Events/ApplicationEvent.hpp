#ifndef __APPLICATION_EVENT_HPP__
#define __APPLICATION_EVENT_HPP__

#include <cassert>
#include <cstdint>

#include "Application/Tools/ITool.hpp"
#include "Core/EventManager/Event.hpp"

enum WidgetEventType : uint64_t {
    kNoneCustomEvent       = kCustomEventCategory | 0x00000000,

    kChangeToolEvent       = kCustomEventCategory | 0x00000001,
};

class ChangeToolEvent : public Event {
public:
    ChangeToolEvent(ITool* tool);
    virtual ~ChangeToolEvent() override;

    static uint64_t GetStaticType();

    ITool* GetTool() const;

protected:
    ITool* tool_;
};

#endif // __APPLICATION_EVENT_HPP__