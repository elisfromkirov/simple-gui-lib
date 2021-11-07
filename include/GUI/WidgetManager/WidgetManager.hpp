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

    virtual bool OnEvent(const Event* event) override;

private:
    void UpdateHitWidget(const MouseEvent* event);

private:
    Widget* root_widget_;

    Widget* hit_widget_;
};

#endif // __WIDGET_MANAGER_HPP__
