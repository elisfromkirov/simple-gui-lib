#include "Application/Commands/Commands.hpp"
#include "Application/Events/ApplicationEvent.hpp"
#include "Application/Tools/ToolManager.hpp"
#include "Core/EventManager/EventManager.hpp"

SetToolCommand::SetToolCommand(ITool* tool)
    : tool_{tool} {}

SetToolCommand::~SetToolCommand() {}

void SetToolCommand::operator()() {
    EventManager::GetInstance()->PostEvent<ChangeToolEvent>(tool_);

    ToolManager::GetInstance()->SetActiveTool(tool_);
}