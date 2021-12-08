#ifndef __TOOL_PANEL_HPP__
#define __TOOL_PANEL_HPP__

#include <cassert>
#include <cstdint>

#include "Application/Events/ApplicationEvent.hpp"
#include "Application/Tools/ITool.hpp"
#include "GUI/Widgets/TabBar.hpp"

class SetToolFunctor : public IFunctor<void ()> {
public:
    SetToolFunctor(ITool* tool);
    virtual ~SetToolFunctor() override;

    virtual void operator()() override;

protected:
    ITool* tool_;
};

class ToolPanel : public TabBar {
public:
    static const uint32_t kSliderWidth{240};
    static const uint32_t kSliderHeight{30};

    static const uint32_t kToolButtonWidth{56};
    static const uint32_t kToolButtonHeight{56};

    static const uint32_t kIndent{4};    

    static const uint32_t kWidth{kToolButtonHeight + kSliderWidth};

    static const uint32_t kPreferencesPanelWidth{240};
    static const uint32_t kPreferencesPanelHeight{600};

public:
    ToolPanel(const Rect2& rect);
    virtual ~ToolPanel() override;

    void InsertTool(ITool* tool);

    bool OnChangeToolEvent(const ChangeToolEvent* event);

protected:
    std::list<std::pair<ITool*, Button*>> tools_;
};

#endif // __TOOL_PANEL_HPP__