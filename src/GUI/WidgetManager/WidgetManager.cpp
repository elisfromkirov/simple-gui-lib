#include "GUI/WidgetManager/WidgetManager.hpp"

WidgetManager::WidgetManager(Widget* root_widget) 
    : root_widget_{root_widget} {}

WidgetManager::~WidgetManager() {}

void WidgetManager::OnEvent(const Event* event) {
    assert(event != nullptr);

    switch (event->GetType()) {
        case kMouseButtonPress: {
            const MouseButtonPressEvent* e = reinterpret_cast<const MouseButtonPressEvent*>(event);
            root_widget_->OnMouseButtonPress(e);
        } break;
        case kMouseButtonRelease: {
            const MouseButtonReleaseEvent* e = reinterpret_cast<const MouseButtonReleaseEvent*>(event);
            root_widget_->OnMouseButtonRelease(e);
        } break;
        case kMouseMove: {
            const MouseMoveEvent* e = reinterpret_cast<const MouseMoveEvent*>(event);
            root_widget_->OnMouseMove(e);
        } break;
    }
}
