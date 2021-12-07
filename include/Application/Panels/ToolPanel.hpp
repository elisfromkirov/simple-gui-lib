#ifndef __TOOL_PANEL_HPP__
#define __TOOL_PANEL_HPP__

#include <cassert>
#include <cstdint>

#include "Application/Events/ApplicationEvent.hpp"
#include "Application/Tools/ITool.hpp"
#include "GUI/Widgets/TabBar.hpp"

class ToolPanel : public TabBar {
public:
    static const uint32_t kSliderWidth{240};
    static const uint32_t kSliderHeight{30};

    static const uint32_t kToolButtonWidth{56};
    static const uint32_t kToolButtonHeight{56};

    static const uint32_t kIndent{4};    

public:
    ToolPanel(const Rect2& rect);
    virtual ~ToolPanel() override;

    void InsertTool(ITool* tool);

    bool OnChangeToolEvent(const ChangeToolEvent* event);
};

#endif // __TOOL_PANEL_HPP__