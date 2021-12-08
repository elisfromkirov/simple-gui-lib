#include "Application/Tools/ToolManager.hpp"
#include "Application/Tools/Tools.hpp"

ToolManager* ToolManager::singleton{nullptr};

ToolManager::ToolManager()
    : active_tool_{nullptr}, 
      tools_{},
      filters_{} {
    Pencil* pencil = new Pencil();
    AddTool(pencil);

    Eraser* eraser = new Eraser();
    AddTool(eraser);

    Brush* brush = new Brush();
    AddTool(brush);
}

ToolManager::~ToolManager() {
    for (auto iter = tools_.begin(); iter != tools_.end(); ++iter) {
        delete (*iter);
    }

    for (auto iter = filters_.begin(); iter != filters_.end(); ++iter) {
        delete (*iter);
    }
}

ToolManager* ToolManager::GetInstance() {
    if (singleton == nullptr) {
        singleton = new ToolManager();
    }
    return singleton;
}

void ToolManager::Release() {
    delete this;
}

ITool* ToolManager::GetActiveTool() {
    return active_tool_;
}

void ToolManager::SetActiveTool(ITool* tool) {
    active_tool_ = tool;
}

void ToolManager::AddTool(ITool* tool) {
    assert(tool != nullptr);

    tools_.push_back(tool);
}

void ToolManager::RemoveTool(ITool* tool) {
    assert(tool != nullptr);

    tools_.push_back(tool);
}

std::list<ITool*>* ToolManager::GetTools() {
    return &tools_;
}

// IFilter* ToolManager::GetActiveFilter() {
//     return active_filter_;
// }

// void ToolManager::SetActiveFilter(IFilter* filter) {
//     active_filter_ = filter;
// }

void ToolManager::AddFilter(IFilter* filter) {
    assert(filter != nullptr);

    filters_.push_back(filter);
}

void ToolManager::RemoveFilter(IFilter* filter) {
    assert(filter != nullptr);

    filters_.remove(filter);
}

std::list<IFilter*>* ToolManager::GetFilters() {
    return &filters_;
}