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

    void AddFilter(IFilter* filter);
    void RemoveFilter(IFilter* filter);

    std::list<IFilter*>* GetFilters();

private:
    ToolManager();
    ~ToolManager();

    ToolManager(const ToolManager& other) = delete;
    ToolManager& operator=(const ToolManager& other) = delete;

    static ToolManager* singleton;

private:
    ITool*              active_tool_;
    std::list<ITool*>   tools_;

    std::list<IFilter*> filters_;
};

#endif // __TOOL_MANAGER_HPP__