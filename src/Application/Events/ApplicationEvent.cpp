#include "Application/Events/ApplicationEvent.hpp"

OpenEditorEvent::OpenEditorEvent() 
    : Event{kOpenEditorEvent} {}

OpenEditorEvent::~OpenEditorEvent() {}

uint64_t OpenEditorEvent::GetStaticType() {
    return kOpenEditorEvent;
}

ChangeToolEvent::ChangeToolEvent(ITool* tool)
    : Event{kChangeToolEvent},
      tool_{tool} {}

ChangeToolEvent::~ChangeToolEvent() {}

uint64_t ChangeToolEvent::GetStaticType() {
    return kChangeToolEvent;
}

ITool* ChangeToolEvent::GetTool() const {
    return tool_;
}

ApplyFilterEvent::ApplyFilterEvent(IFilter* filter)
    : Event{kApplyFilterEvent},
      filter_{filter} {}

ApplyFilterEvent::~ApplyFilterEvent() {}

uint64_t ApplyFilterEvent::GetStaticType() {
    return kApplyFilterEvent;
}

IFilter* ApplyFilterEvent::GetFilter() const {
    return filter_;
}