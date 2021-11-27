#include "Core/Platform/InputEvent.hpp"
#include "GUI/Events/WidgetEvent.hpp"
#include "GUI/Widgets/Window.hpp"

Window::Window(const Vector2u& size)
    : Widget{size},
      mouse_grabbing_widget_{nullptr},
      focus_widget_{nullptr} {}      

Window::~Window() {}

void Window::OnEvent(const Event* event) {
    assert(event != nullptr);

    bool handled = CallCallback(event);
    if (handled) {
        return true;
    }

    return DispatchToChildren(event);
}

bool Window::OnMouseButtonPressEvent(const MouseButtonPressEvent* event) {
    assert(event != nullptr);

    if (mouse_grabbing_widget_ != nullptr) {
        return mouse_grabbing_widget_->OnMouseButtonPressEvent(event);
    }
    return false;
}

bool Window::OnMouseButtonReleaseEvent(const MouseButtonReleaseEvent* event) {
    assert(event != nullptr);

    if (mouse_grabbing_widget_ != nullptr) {
        return mouse_grabbing_widget_->OnMouseButtonReleaseEvent(event);
    }
    return false;
}

bool Window::OnMouseMoveEvent(const MouseMoveEvent* event) {
    assert(event != nullptr);

    if (mouse_grabbing_widget_ != nullptr) {
        mouse_grabbing_widget_->OnMouseMoveEvent(event);
    }
    return false;
}

bool Window::OnKeyPressEvent(const KeyPressEvent* event) {
    assert(event != nullptr);

    return false;
}

bool Window::OnKeyReleaseEvent(const KeyReleaseEvent* event) {
    assert(event != nullptr);

    return false;
}

bool Window::OnMouseCaptureEvent(const MouseCaptureEvent* event) {
    assert(event != nullptr);

    mouse_grabbing_widget_ = event->GetWidget();
    return true;
}

bool Window::OnMouseCaptureLostEvent(const MouseCaptureLostEvent* event) {
    assert(event != nullptr);

    mouse_grabbing_widget_ = root_widget_;

    return true;
}

bool Window::OnFocusInEvent(const FocusInEvent* event) {
    assert(event != nullptr);

    return false;
}

bool Window::OnFocusOutEvent(const FocusOutEvent* event) {
    assert(event != nullptr);

    return false;
}

bool Window::OnCloseEvent(const CloseEvent* event) {
    assert(event != nullptr);

    Widget* widget = event->GetWidget();
    assert(widget != nullptr);

    return widget->OnCloseEvent(event);
}

bool Window::OnMoveEvent(const MoveEvent* event) {
    assert(event != nullptr);

    Widget* widget = event->GetWidget();
    assert(widget != nullptr);

    return widget->OnMoveEvent(event);
}

bool Window::OnResizeEvent(const ResizeEvent* event) {
    assert(event != nullptr);

    Widget* widget = event->GetWidget();
    assert(widget != nullptr);

    return widget->OnResizeEvent(event);
}