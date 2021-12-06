#include "Application/Commands/Commands.hpp"
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
    Menu* file_menu = new Menu(240, "File");
    file_menu->InsertItem("Open editor", new OpenEditorCommand());

    Menu* tool_menu = new Menu(240, "Tool");
    std::list<ITool*>* tools = ToolManager::GetInstance()->GetTools();
    for (auto iter = tools->begin(); iter != tools->end(); ++iter) {
        tool_menu->InsertItem((*iter)->GetName(), new SetToolCommand(*iter));
    }

    Menu* filter_menu = new Menu(240, "Filter");
    std::list<IFilter*>* filters = ToolManager::GetInstance()->GetFilters();
    for (auto iter = filters->begin(); iter != filters->end(); ++iter) {
        tool_menu->InsertItem((*iter)->GetName(), new SetFilterCommand(*iter));
    }

    menu_bar_ = new MenuBar(this);
    menu_bar_->InsertMenu(file_menu);
    menu_bar_->InsertMenu(tool_menu);
    menu_bar_->InsertMenu(filter_menu);

    AttachInTop(menu_bar_);
}

void MainPanel::InitializeEditorPanel(const Rect2& rect) {    
    editor_panel_ = new EditorPanel(rect);

    editor_panel_->InsertEditor("Editor");

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