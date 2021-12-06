#include "Application/Events/ApplicationEvent.hpp"

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