#include "Core/EventManager/EventManager.hpp"
#include "Core/Platform/Color.hpp"
#include "Core/Platform/Image.hpp"
#include "Core/Platform/InputEvent.hpp"
#include "Core/Platform/RenderTexture.hpp"
#include "GUI/Events/WidgetEvent.hpp"
#include "GUI/Widgets/Window.hpp"

#include <cstdio>

Window::Window(const Vector2u& size)
    : ContainerWidget{size},
      mouse_grabbing_widget_{nullptr},
      focus_widget_{nullptr} {}

Window::~Window() {}

bool Window::OnEvent(const Event* event) {
    assert(event != nullptr);

    FilterEvent(event);

    bool handled = HandleEvent(event);
    if (handled) {
        return true;
    }

    for (auto iter = children_.begin(); iter != children_.end(); ++iter) {
        handled = (*iter)->OnEvent(event);
        if (handled) {
            return true;
        }
    }
    return false;
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
        return mouse_grabbing_widget_->OnMouseMoveEvent(event);
    }
    return false;
}

bool Window::OnMouseCaptureInEvent(const MouseCaptureInEvent* event) {
    assert(event != nullptr);

    mouse_grabbing_widget_ = event->GetWidget();
    return true;
}

bool Window::OnMouseCaptureOutEvent(const MouseCaptureOutEvent* event) {
    assert(event != nullptr);

    mouse_grabbing_widget_ = nullptr;
    return true;
}

bool Window::OnMouseEnterEvent(const MouseEnterEvent* event) {
    assert(event != nullptr);

    Widget* widget = event->GetWidget();
    assert(widget != nullptr);

    widget->OnMouseEnterEvent(event);

    return true;
}

bool Window::OnMouseLeaveEvent(const MouseLeaveEvent* event) {
    assert(event != nullptr);

    Widget* widget = event->GetWidget();
    assert(widget != nullptr);

    widget->OnMouseLeaveEvent(event);
 
    return true;
}

bool Window::OnKeyPressEvent(const KeyPressEvent* event) {
    assert(event != nullptr);

    if (focus_widget_ != nullptr) {
        return focus_widget_->OnKeyPressEvent(event);
    }
    return true;
}

bool Window::OnKeyReleaseEvent(const KeyReleaseEvent* event) {
    assert(event != nullptr);

    if (focus_widget_ != nullptr) {
        return focus_widget_->OnKeyReleaseEvent(event);
    }
    return true;
}

bool Window::OnFocusInEvent(const FocusInEvent* event) {
    assert(event != nullptr);

    focus_widget_ = event->GetWidget();
    return true;
}

bool Window::OnFocusOutEvent(const FocusOutEvent* event) {
    assert(event != nullptr);

    focus_widget_ = nullptr;
    return true;
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

bool Window::OnHorizontalScrollEvent(const HorizontalScrollEvent* event) {
    assert(event != nullptr);

    Widget* widget = event->GetWidget();
    assert(widget != nullptr);

    return widget->OnHorizontalScrollEvent(event);
}

bool Window::OnVerticalScrollEvent(const VerticalScrollEvent* event) {
    assert(event != nullptr);

    Widget* widget = event->GetWidget();
    assert(widget != nullptr);

    return widget->OnVerticalScrollEvent(event);
}

bool Window::OnShowPopUpWidgetEvent(const ShowPopUpWidgetEvent* event) {
    assert(event != nullptr);

    mouse_grabbing_widget_ = nullptr;
    focus_widget_          = nullptr;

    Widget* widget = event->GetWidget();
    assert(widget != nullptr);

    children_.push_front(widget);

    return true;
}

bool Window::OnHidePopUpWidgetEvent(const HidePopUpWidgetEvent* event) {
    assert(event != nullptr);

    children_.pop_front();

    return true;
}