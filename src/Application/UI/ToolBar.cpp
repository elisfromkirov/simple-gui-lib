#include "Application/Tools/ToolManager.hpp"
#include "Application/UI/ToolBar.hpp"
#include "Core/Platform/RenderTexture.hpp"
#include "GUI/Styles/ButtonStyle.hpp"
#include "GUI/Widgets/Button.hpp"

SetToolCommand::SetToolCommand(ITool* tool)
    : tool_{tool} {}

SetToolCommand::~SetToolCommand() {}

void SetToolCommand::operator()() {
    ToolManager::GetInstance()->SetActiveTool(tool_);
}
#include <cstdio>
ToolBar::ToolBar(const Rect2& rect)
    : ContainerWidget{} {
    list_ = new ScrollingHorizontalList(Rect2(rect.size.x, kButtonSize, rect.position.x, rect.position.y));
    Attach(list_);

    rect_.size     = list_->GetSize();
    rect_.position = rect.position;
    texture_       = new RenderTexture(rect_.size);
}

ToolBar::~ToolBar() {}

bool ToolBar::InsertTool(ITool* tool) {
    assert(tool != nullptr);

    Button* button = new Button(Rect2(kButtonSize, kButtonSize));
    button->ApplyStyle(new ButtonStyle(tool->GetIconFileName()));
    button->Clicked.Connect(new SetToolCommand(tool));

    return list_->InsertItem(button);
}
