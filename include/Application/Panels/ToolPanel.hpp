#ifndef __TOOL_PANEL_HPP__
#define __TOOL_PANEL_HPP__

#include <cassert>
#include <cstdint>

#include "Application/Events/ApplicationEvent.hpp"
#include "Application/Tools/ITool.hpp"
#include "GUI/Widgets/ContainerWidget.hpp"
#include "GUI/Widgets/List.hpp"

class ToolPanel : public ContainerWidget {
private:
    static const uint32_t kToolButtonSize{56};

public:
    ToolPanel(const Rect2& rect);
    virtual ~ToolPanel() override;

    void InsertTool(ITool* tool);

    bool OnChangeToolEvent(const ChangeToolEvent* event);

protected:
    ScrollingHorizontalList* tool_list_;
    ContainerWidget*         preferences_panel_;
};

#endif // __TOOL_PANEL_HPP__