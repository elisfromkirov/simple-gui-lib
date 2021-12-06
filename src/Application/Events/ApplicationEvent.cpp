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

ChangeFilterEvent::ChangeFilterEvent(IFilter* filter)
    : Event{kChangeFilterEvent},
      filter_{filter} {}

ChangeFilterEvent::~ChangeFilterEvent() {}

uint64_t ChangeFilterEvent::GetStaticType() {
    return kChangeFilterEvent;
}

IFilter* ChangeFilterEvent::GetFilter() const {
    return filter_;
}