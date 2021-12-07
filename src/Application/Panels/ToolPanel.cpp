#include "Application/Commands/Commands.hpp"
#include "Application/Tools/ITool.hpp"
#include "Application/Panels/MainPanel.hpp"
#include "Application/Panels/ToolPanel.hpp"
#include "Core/Platform/RenderTexture.hpp"
#include "GUI/Styles/ButtonStyle.hpp"
#include "GUI/Widgets/Button.hpp"
#include "GUI/Styles/FilledStyle.hpp"

ToolPanel::ToolPanel(const Rect2& rect)
    : TabBar{Vector2u(rect.size.x - kToolButtonWidth, rect.size.y), Vector2u(kToolButtonWidth, kToolButtonHeight)} {
    Move(rect.position);
    ApplyStyle(new FilledStyle(FilledStyle::kDarkPanel));

    SetEventHandler<ToolPanel, ChangeToolEvent>(this, &ToolPanel::OnChangeToolEvent);
}

ToolPanel::~ToolPanel() {}

void ToolPanel::InsertTool(ITool* tool) {
    assert(tool != nullptr);

    Button* button = InsertTab(tool->GetPreferencesPanel(), tool->GetIconFileName());
    assert(button);

    button->Clicked.Connect(new SetToolCommand(tool));
}

bool ToolPanel::OnChangeToolEvent(const ChangeToolEvent* event) {
    assert(event != nullptr);

    

    return true;
}