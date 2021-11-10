#ifndef __EDITOR_HPP__
#define __EDITOR_HPP__

#include "Core/Application/Application.hpp"
#include "Editor/MainPanel.hpp"
#include "GUI/WidgetManager/WidgetManager.hpp"

class Editor : public Application {
public:
    Editor();
    ~Editor();

    virtual void Run() override;

protected:
    MainPanel     main_panel_;
    WidgetManager widget_manager_;
};

#endif // __EDITOR_HPP__
