#ifndef __TOOL_BAR_HPP__
#define __TOOL_BAR_HPP__

#include <cassert>
#include <cstdint>

#include "Application/Tools/ITool.hpp"
#include "GUI/Widgets/ContainerWidget.hpp"
#include "GUI/Widgets/List.hpp"

class SetToolCommand : public IFunctor<void ()> {
public:
    SetToolCommand(ITool* tool);
    virtual ~SetToolCommand() override;

    virtual void operator()() override; 

protected:
    ITool* tool_;
};

class ToolBar : public ContainerWidget {
public:
    ToolBar(const Rect2& rect);
    virtual ~ToolBar() override;

    bool InsertTool(ITool* tool);

protected:
    ScrollingHorizontalList* list_;
};

#endif // __TOOL_BAR_HPP__