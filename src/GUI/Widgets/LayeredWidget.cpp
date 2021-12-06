#include "Core/Platform/InputEvent.hpp"
#include "GUI/Widgets/LayeredWidget.hpp"

LayeredWidget::LayeredWidget(const Rect2& rect) 
    : ContainerWidget{rect} {
    SetEventFilter<LayeredWidget, MouseButtonPressEvent>(this, &LayeredWidget::FilterMouseButtonPressEvent);
}

LayeredWidget::~LayeredWidget() {}

bool LayeredWidget::FilterMouseButtonPressEvent(const MouseButtonPressEvent* event) {
    assert(event != nullptr);

    if (!HitTest(event->GetMousePosition())) {
        return false;
    }

    for (auto iter = children_.begin(); iter != children_.end(); ++iter) {
        if ((*iter)->HitTest(event->GetMousePosition())) {
            Widget* temp = *iter;
            children_.erase(iter);
            children_.push_front(temp);

            return true;
        }
    }

    return false;
}