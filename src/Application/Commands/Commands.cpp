#include "Application/Commands/Commands.hpp"
#include "Application/Events/ApplicationEvent.hpp"
#include "Application/Tools/ToolManager.hpp"
#include "Core/EventManager/EventManager.hpp"

OpenEditorCommand::OpenEditorCommand() {}

OpenEditorCommand::~OpenEditorCommand() {}

void OpenEditorCommand::operator()() {
    EventManager::GetInstance()->PostEvent<OpenEditorEvent>();
}

SetToolCommand::SetToolCommand(ITool* tool)
    : tool_{tool} {}

SetToolCommand::~SetToolCommand() {}

void SetToolCommand::operator()() {
    EventManager::GetInstance()->PostEvent<ChangeToolEvent>(tool_);

    ToolManager::GetInstance()->SetActiveTool(tool_);
}

ApplyFilterCommand::ApplyFilterCommand(IFilter* filter)
    : filter_{filter} {}   

ApplyFilterCommand::~ApplyFilterCommand() {}

void ApplyFilterCommand::operator()() {
    EventManager::GetInstance()->PostEvent<ApplyFilterEvent>(filter_);
}