#include "GUI/WidgetManager/WidgetManager.hpp"

WidgetManager* WidgetManager::singleton{nullptr};

WidgetManager::WidgetManager() 
    : root_widget_{nullptr}, 
      grabbing_widget_{nullptr},
      focused_widget_{nullptr} {}

WidgetManager::~WidgetManager() {}

void WidgetManager::OnEvent(const Event* event) {
    assert(root_widget_ != nullptr);
    assert(event        != nullptr);

    switch (event->GetType()) {
        case kMouseButtonPress: {
            const MouseButtonPressEvent* e = static_cast<const MouseButtonPressEvent*>(event);

            if (grabbing_widget_ == nullptr) {
                root_widget_->OnMouseButtonPressEvent(e);
            } else {
                grabbing_widget_->OnMouseButtonPressEvent(e);
            }
        } break;
        case kMouseButtonRelease: {
            const MouseButtonReleaseEvent* e = static_cast<const MouseButtonReleaseEvent*>(event);

            if (grabbing_widget_ == nullptr) {
                root_widget_->OnMouseButtonReleaseEvent(e);
            } else {
                grabbing_widget_->OnMouseButtonReleaseEvent(e);
            }
        } break;
        case kMouseMove: {
            const MouseMoveEvent* e = static_cast<const MouseMoveEvent*>(event);

            if (grabbing_widget_ == nullptr) {
                root_widget_->OnMouseMoveEvent(e);
            } else {
                grabbing_widget_->OnMouseMoveEvent(e);
            }
        } break;
        case kMouseCaptureRequest: {
            const MouseCaptureRequestEvent* e = static_cast<const MouseCaptureRequestEvent*>(event);

            Widget* target = e->GetWidget();
            assert(target != nullptr);

            grabbing_widget_ = target;
        } break;
        case kMouseCaptureLost: {
            const MouseCaptureLostEvent* e = static_cast<const MouseCaptureLostEvent*>(event);

            Widget* target = e->GetWidget();
            assert(target != nullptr);

            grabbing_widget_ = nullptr;
        } break;
        case kClose: {
            const CloseEvent* e = static_cast<const CloseEvent*>(event);

            Widget* target = e->GetWidget();
            assert(target != nullptr);

            target->OnCloseEvent(e);
        } break;
        case kMove: {
            const MoveEvent* e = static_cast<const MoveEvent*>(event);

            Widget* target = e->GetWidget();
            assert(target != nullptr);

            target->OnMoveEvent(e);
        } break;
        case kResize: {
            const ResizeEvent* e = static_cast<const ResizeEvent*>(event);

            Widget* target = e->GetWidget();
            assert(target != nullptr);

            target->OnResizeEvent(e);
        } break;
    }
}

Widget* WidgetManager::GetRootWidget() {
    return root_widget_;
}

void WidgetManager::SetRootWidget(Widget* root) {
    root_widget_ = root;
}

WidgetManager* WidgetManager::GetWidgetManager() {
    if (singleton == nullptr) {
        singleton = new WidgetManager();
    }
    return singleton;
}
