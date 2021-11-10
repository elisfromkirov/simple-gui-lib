#ifndef __WIDGET_MANAGER_HPP__
#define __WIDGET_MANAGER_HPP__

#include <cassert>
#include <cstdint>

#include "Core/EventManager/IEventListener.hpp"
#include "GUI/Event/InputEvent.hpp"
#include "GUI/Widgets/Widget.hpp"

class WidgetManager : public IEventListener {
public:
    WidgetManager(Widget* root_widget);

    ~WidgetManager();

    virtual void OnEvent(const Event* event) override;

private:
    Widget* root_widget_;
};

#endif // __WIDGET_MANAGER_HPP__
