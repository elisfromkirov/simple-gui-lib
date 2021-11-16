#ifndef __WIDGET_MANAGER_HPP__
#define __WIDGET_MANAGER_HPP__

#include <cassert>
#include <cstdint>

#include "Core/EventManager/IEventListener.hpp"
#include "GUI/Widgets/Widget.hpp"

class WidgetManager : public IEventListener {
    static WidgetManager* singleton;

private:
    WidgetManager();

public:
    virtual ~ WidgetManager() override;

    virtual void OnEvent(const Event* event) override;

    Widget* GetRootWidget();
    void SetRootWidget(Widget* widget);

    static  WidgetManager* GetWidgetManager();

protected:
    Widget* root_widget_;

    Widget* grabbing_widget_;

    Widget* focused_widget_;
};

#endif // __WIDGET_MANAGER_HPP__