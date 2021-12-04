#ifndef __TOOL_MANAGER_HPP__
#define __TOOL_MANAGER_HPP__

#include <cassert>
#include <cstdint>

#include "Application/Tools/IFilter.hpp"
#include "Application/Tools/ITool.hpp"

class ToolManager {
public:
    static EventManager* GetInstance();

    void Release();

    ITool* GetActiveTool();
    SetActiveTool(ITool* tool);

    void AddTool(ITool* tool);
    void RemoveTool(ITool* tool);

    IFilter* GetActiveFilter();
    SetActiveFilter(IFilter* tool);

    void AddFilter(ITool* tool);
    void RemoveFilter(ITool* tool);

private:
    ToolManager();
    ~ToolManager();

    ToolManager(const ToolManager& other) = delete;
    ToolManager& operator=(const ToolManager& other) = delete;

    static ToolManager* singleton;

private:
    std::list<ITool*>   tools_;
    ITool*              active_tool_;

    std::list<IFilter*> filters_;
    Filter*             active_filter_;
};

#endif // __TOOL_MANAGER_HPP__