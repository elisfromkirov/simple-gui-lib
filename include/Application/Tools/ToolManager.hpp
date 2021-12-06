#ifndef __TOOL_MANAGER_HPP__
#define __TOOL_MANAGER_HPP__

#include <cassert>
#include <cstdint>
#include <list>

#include "Application/Tools/IFilter.hpp"
#include "Application/Tools/ITool.hpp"

class ToolManager {
public:
    static ToolManager* GetInstance();

    void Release();

    ITool* GetActiveTool();
    void SetActiveTool(ITool* tool);

    void AddTool(ITool* tool);
    void RemoveTool(ITool* tool);

    std::list<ITool*>* GetTools();

    IFilter* GetActiveFilter();
    void SetActiveFilter(IFilter* filter);

    void AddFilter(IFilter* filter);
    void RemoveFilter(IFilter* filter);

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
    IFilter*            active_filter_;
};

#endif // __TOOL_MANAGER_HPP__