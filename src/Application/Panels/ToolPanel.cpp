#include "Application/Commands/Commands.hpp"
#include "Application/Tools/ITool.hpp"
#include "Application/Panels/MainPanel.hpp"
#include "Application/Panels/ToolPanel.hpp"
#include "Core/Platform/RenderTexture.hpp"
#include "GUI/Styles/ButtonStyle.hpp"
#include "GUI/Widgets/Button.hpp"
#include "GUI/Styles/FilledStyle.hpp"

ToolPanel::ToolPanel(const Rect2& rect)
    : ContainerWidget{rect},
      tool_list_{nullptr},
      preferences_panel_{nullptr} {
    tool_list_ = new ScrollingHorizontalList(Rect2(rect.size.x, kToolButtonSize, rect.position.x, rect.position.y));

    Attach(tool_list_);

    ApplyStyle(new FilledStyle(FilledStyle::kDarkPanel));

    SetEventHandler<ToolPanel, ChangeToolEvent>(this, &ToolPanel::OnChangeToolEvent);
}

ToolPanel::~ToolPanel() {}

void ToolPanel::InsertTool(ITool* tool) {
    assert(tool != nullptr);

    Button* button = new Button(Rect2(kToolButtonSize, kToolButtonSize));
    button->ApplyStyle(new ButtonStyle(tool->GetIconFileName()));
    button->Clicked.Connect(new SetToolCommand(tool));

    tool_list_->InsertItem(button);
}

bool ToolPanel::OnChangeToolEvent(const ChangeToolEvent* event) {
    assert(event != nullptr);

    if (preferences_panel_ != nullptr) {
        Detach(preferences_panel_);
    }

    Vector2i position(rect_.position.x, rect_.position.y + tool_list_->GetSize().y + MainPanel::kIndent);

    ITool* tool = event->GetTool();
    assert(tool != nullptr);

    preferences_panel_ = tool->GetPreferencesPanel();
    assert(preferences_panel_ != nullptr);

    preferences_panel_->Move(position);

    Attach(preferences_panel_);

    return true;
}