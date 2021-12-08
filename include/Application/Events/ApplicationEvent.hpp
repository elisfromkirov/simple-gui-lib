#ifndef __APPLICATION_EVENT_HPP__
#define __APPLICATION_EVENT_HPP__

#include <cassert>
#include <cstdint>

#include "Application/Tools/IFilter.hpp"
#include "Application/Tools/ITool.hpp"
#include "Core/EventManager/Event.hpp"

enum ApplicationEventType : uint64_t {
    kNoneCustomEvent   = kCustomEventCategory | 0x00000000,

    kOpenEditorEvent   = kCustomEventCategory | 0x00000001, 

    kChangeToolEvent   = kCustomEventCategory | 0x00000002,
    kApplyFilterEvent  = kCustomEventCategory | 0x00000004
};

class OpenEditorEvent : public Event {
public:
    OpenEditorEvent();
    virtual ~OpenEditorEvent() override;

    static uint64_t GetStaticType();
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

class ApplyFilterEvent : public Event {
public:
    ApplyFilterEvent(IFilter* filter);
    virtual ~ApplyFilterEvent() override;

    static uint64_t GetStaticType();

    IFilter* GetFilter() const;

protected:
    IFilter* filter_;
};

#endif // __APPLICATION_EVENT_HPP__