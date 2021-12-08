#include "Application/Tools/ITool.hpp"
#include "Application/Tools/ToolManager.hpp"
#include "Application/Panels/MainPanel.hpp"
#include "Application/Panels/ToolPanel.hpp"
#include "Core/Platform/RenderTexture.hpp"
#include "GUI/Styles/ButtonStyle.hpp"
#include "GUI/Widgets/Button.hpp"
#include "GUI/Styles/FilledStyle.hpp"

SetToolFunctor::SetToolFunctor(ITool* tool)
    : tool_{tool} {}

SetToolFunctor::~SetToolFunctor() {}

void SetToolFunctor::operator()() {
    ToolManager::GetInstance()->SetActiveTool(tool_);
}

ToolPanel::ToolPanel(const Rect2& rect)
    : TabBar{Vector2u(rect.size.x - kToolButtonWidth, rect.size.y), Vector2u(kToolButtonWidth, kToolButtonHeight)},
      tools_{} {
    Move(rect.position);
    ApplyStyle(new FilledStyle(FilledStyle::kDarkPanel));

    SetEventHandler<ToolPanel, ChangeToolEvent>(this, &ToolPanel::OnChangeToolEvent);
}

ToolPanel::~ToolPanel() {}

void ToolPanel::InsertTool(ITool* tool) {
    assert(tool != nullptr);

    Button* button = InsertTab(tool->GetPreferencesPanel(), tool->GetIconFileName());
    assert(button != nullptr);

    button->Clicked.Connect(new SetToolFunctor(tool));

    tools_.emplace_back(tool, button);
}

bool ToolPanel::OnChangeToolEvent(const ChangeToolEvent* event) {
    assert(event != nullptr);

    for (auto iter = tools_.begin(); iter != tools_.end(); ++iter) {
        if (iter->first == event->GetTool()) {
            iter->second->Clicked();
        }
    }

    return true;
}