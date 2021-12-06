#include "Application/Panels/MainPanel.hpp"
#include "Application/Panels/PreferencesPanels.hpp"
#include "Application/Tools/ToolManager.hpp"
#include "GUI/Styles/FilledStyle.hpp"

MainPanel::MainPanel(const Vector2u& size)
    : ContainerWidget{Rect2(size)},
      menu_bar_{nullptr},
      editor_panel_{nullptr},
      tool_panel_{nullptr} {
    Rect2 rect{};

    InitializeMenuBar();

    rect.size.x     = size.x - kToolPanelWidth - 3 * kIndent;
    rect.size.y     = size.y - menu_bar_->GetSize().y - 2 * kIndent;
    rect.position.x = kIndent;
    rect.position.y = menu_bar_->GetSize().y + kIndent;

    InitializeEditorPanel(rect);

    rect.size.x     = kToolPanelWidth;
    rect.size.y     = size.y - menu_bar_->GetSize().y - 2 * kIndent;
    rect.position.x = size.x - kToolPanelWidth - kIndent;
    rect.position.y = menu_bar_->GetSize().y + kIndent;

    InitializeToolPanel(rect);

    ApplyStyle(new FilledStyle(FilledStyle::kMainPanel));
}

MainPanel::~MainPanel() {}

void MainPanel::InitializeMenuBar() {
    menu_bar_ = new MenuBar(this);

    Menu* menu1 = new Menu(300, "menu1");
    menu1->InsertItem("menu1: item1");
    menu1->InsertItem("menu1: item2");
    menu1->InsertItem("menu1: item3");
    menu1->InsertItem("menu1: item4");
    menu1->InsertItem("menu1: item5");
    menu1->InsertItem("menu1: item6");
    menu1->InsertItem("menu1: item7");
    menu1->InsertItem("menu1: item8");
    menu_bar_->InsertMenu(menu1);

    Menu* menu2 = new Menu(300, "menu2");
    menu2->InsertItem("menu2: item1");
    menu2->InsertItem("menu2: item2");
    menu2->InsertItem("menu2: item3");
    menu2->InsertItem("menu2: item4");
    menu2->InsertItem("menu2: item5");
    menu2->InsertItem("menu2: item6");
    menu2->InsertItem("menu2: item7");
    menu2->InsertItem("menu2: item8");
    menu_bar_->InsertMenu(menu2);

    AttachInTop(menu_bar_);
}

void MainPanel::InitializeEditorPanel(const Rect2& rect) {    
    editor_panel_ = new EditorPanel(rect);

    editor_panel_->InsertEditor("Editor 1");

    Attach(editor_panel_);
}

void MainPanel::InitializeToolPanel(const Rect2& rect) {
    tool_panel_ = new ToolPanel(rect);

    std::list<ITool*>* tools = ToolManager::GetInstance()->GetTools();
    for (auto iter = tools->begin(); iter != tools->end(); ++iter) {
        tool_panel_->InsertTool(*iter);
    }

    Attach(tool_panel_);
}