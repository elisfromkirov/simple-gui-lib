#include "GUI/Event/GUIEvent.hpp"
    
WidgetCloseEvent::WidgetCloseEvent(Widget* widget)
    : Event{kWidgetClose}, 
      widget_{widget} {
    assert(widget_ != nullptr);
}

WidgetCloseEvent::~WidgetCloseEvent() {}

Widget* WidgetCloseEvent::GetWidget() const {
    assert(widget_ != nullptr);

    return widget_;
}
