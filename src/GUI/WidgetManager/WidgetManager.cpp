#include "GUI/WidgetManager/WidgetManager.hpp"

WidgetManager::WidgetManager(Widget* root_widget) 
    : root_widget_{root_widget}, hit_widget_{nullptr} {}

WidgetManager::~WidgetManager() {}

bool WidgetManager::OnEvent(const Event* event) {
    assert(event != nullptr);

    bool result = false;

    switch (event->GetType()) {
        case kMouseButtonPress: {
            const MouseButtonPressEvent* e = reinterpret_cast<const MouseButtonPressEvent*>(event);

            UpdateHitWidget(e);

            result = root_widget_->OnMouseButtonPress(e);
        } break;
        case kMouseButtonRelease: {
            const MouseButtonReleaseEvent* e = reinterpret_cast<const MouseButtonReleaseEvent*>(event);

            UpdateHitWidget(e);

            result = root_widget_->OnMouseButtonRelease(e);
        } break;
        case kMouseMove: {
            const MouseMoveEvent* e = reinterpret_cast<const MouseMoveEvent*>(event);

            UpdateHitWidget(e);

            result = root_widget_->OnMouseMove(e);
        } break;
    }

    return result;
}

void WidgetManager::UpdateHitWidget(const MouseEvent* event) {
    assert(event != nullptr);

    Widget* hit_widget = root_widget_->OnHitTest(event->GetMousePosition());

    if (hit_widget_ != hit_widget) {
        if (hit_widget_ != nullptr) {
            MouseLeaveEvent mouse_leave_event(event);
            hit_widget_->OnMouseLeave(&mouse_leave_event);
        }

        if (hit_widget != nullptr) {
            MouseHoverEvent mouse_hover_event(event);
            hit_widget->OnMouseHover(&mouse_hover_event);
        } 
        
        hit_widget_ = hit_widget;
    }
}
