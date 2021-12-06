#ifndef __MAIN_PANEL_HPP__
#define __MAIN_PANEL_HPP__

#include <cassert>
#include <cstdint>

#include "Application/Panels/EditorPanel.hpp"
#include "Application/Panels/ToolPanel.hpp"
#include "GUI/Widgets/MenuBar.hpp"

class MainPanel : public ContainerWidget {
public:
    static const uint32_t kIndent{4};
    static const uint32_t kToolPanelWidth{240};

public:
    MainPanel(const Vector2u& size);
    virtual ~MainPanel() override;

protected:
    void InitializeMenuBar();

    void InitializeEditorPanel(const Rect2& rect);

    void InitializeToolPanel(const Rect2& rect);

protected:
    MenuBar*     menu_bar_;
    EditorPanel* editor_panel_;
    ToolPanel*   tool_panel_;
};

#endif // __MAIN_PANEL_HPP__