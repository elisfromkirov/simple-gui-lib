#include "GUI/WidgetManager/WidgetManager.hpp"

#include <cstdio>

WidgetManager* WidgetManager::singleton{nullptr};

WidgetManager* WidgetManager::GetInstance() {
    if (singleton == nullptr) {
        singleton = new WidgetManager();
    }
    return singleton;
}

void WidgetManager::Release() {
    delete this;
}

WidgetManager::WidgetManager() 
    : root_widget_{nullptr}, 
      mouse_grabbing_widget_{nullptr},
      focus_widget_{nullptr},
      event_dispatcher{this} {
    event_dispatcher.SetEventHandler<MouseButtonPressEvent>  (&WidgetManager::OnMouseButtonPressEvent);
    event_dispatcher.SetEventHandler<MouseButtonReleaseEvent>(&WidgetManager::OnMouseButtonReleaseEvent);
    event_dispatcher.SetEventHandler<MouseMoveEvent>         (&WidgetManager::OnMouseMoveEvent);
    event_dispatcher.SetEventHandler<KeyPressEvent>          (&WidgetManager::OnKeyPressEvent);
    event_dispatcher.SetEventHandler<KeyReleaseEvent>        (&WidgetManager::OnKeyReleaseEvent);
    event_dispatcher.SetEventHandler<MouseCaptureEvent>      (&WidgetManager::OnMouseCaptureEvent);
    event_dispatcher.SetEventHandler<MouseCaptureLostEvent>  (&WidgetManager::OnMouseCaptureLostEvent);
    event_dispatcher.SetEventHandler<FocusInEvent>           (&WidgetManager::OnFocusInEvent);
    event_dispatcher.SetEventHandler<FocusOutEvent>          (&WidgetManager::OnFocusOutEvent);
    event_dispatcher.SetEventHandler<CloseEvent>             (&WidgetManager::OnCloseEvent);
    event_dispatcher.SetEventHandler<MoveEvent>              (&WidgetManager::OnMoveEvent);
    event_dispatcher.SetEventHandler<ResizeEvent>            (&WidgetManager::OnResizeEvent);
}

WidgetManager::~WidgetManager() {}

Widget* WidgetManager::GetRootWidget() {
    return root_widget_;
}

void WidgetManager::SetRootWidget(Widget* root) {
    root_widget_           = root;
    mouse_grabbing_widget_ = root;
    focus_widget_          = root; 
}

void WidgetManager::OnMouseButtonPressEvent(const MouseButtonPressEvent* event) {
    assert(event != nullptr);

    if (mouse_grabbing_widget_ != nullptr) {
        mouse_grabbing_widget_->OnMouseButtonPressEvent(event);
    }
}

void WidgetManager::OnMouseButtonReleaseEvent(const MouseButtonReleaseEvent* event) {
    assert(event != nullptr);

    if (mouse_grabbing_widget_ != nullptr) {
        mouse_grabbing_widget_->OnMouseButtonReleaseEvent(event);
    }
}

void WidgetManager::OnMouseMoveEvent(const MouseMoveEvent* event) {
    assert(event != nullptr);
    if (mouse_grabbing_widget_ != nullptr) {
        mouse_grabbing_widget_->OnMouseMoveEvent(event);
    }
}

void WidgetManager::OnKeyPressEvent(const KeyPressEvent* event) {
    assert(event != nullptr);
}

void WidgetManager::OnKeyReleaseEvent(const KeyReleaseEvent* event) {
    assert(event != nullptr);
}

void WidgetManager::OnMouseCaptureEvent(const MouseCaptureEvent* event) {
    assert(event != nullptr);

    mouse_grabbing_widget_ = event->GetWidget();
}

void WidgetManager::OnMouseCaptureLostEvent(const MouseCaptureLostEvent* event) {
    assert(event != nullptr);

    mouse_grabbing_widget_ = root_widget_;
}

void WidgetManager::OnFocusInEvent(const FocusInEvent* event) {
    assert(event != nullptr);
}

void WidgetManager::OnFocusOutEvent(const FocusOutEvent* event) {
    assert(event != nullptr);
}

void WidgetManager::OnCloseEvent(const CloseEvent* event) {
    assert(event != nullptr);

    Widget* widget = event->GetWidget();
    assert(widget != nullptr);

    widget->OnCloseEvent(event);
}

void WidgetManager::OnMoveEvent(const MoveEvent* event) {
    assert(event != nullptr);

    Widget* widget = event->GetWidget();
    assert(widget != nullptr);

    widget->OnMoveEvent(event);
}

void WidgetManager::OnResizeEvent(const ResizeEvent* event) {
    assert(event != nullptr);

    Widget* widget = event->GetWidget();
    assert(widget != nullptr);

    widget->OnResizeEvent(event);
}

void WidgetManager::OnShowEvent(const ShowEvent* event) {
    assert(event != nullptr);

    Widget* widget = event->GetWidget();
    assert(widget != nullptr);

    widget->OnShowEvent(event);
}

void WidgetManager::OnHideEvent(const HideEvent* event) {
    assert(event != nullptr);

    Widget* widget = event->GetWidget();
    assert(widget != nullptr);

    widget->OnHideEvent(event);
}