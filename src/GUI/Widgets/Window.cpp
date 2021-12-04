#include "Core/Platform/Color.hpp"
#include "Core/Platform/Image.hpp"
#include "Core/Platform/InputEvent.hpp"
#include "Core/Platform/RenderTexture.hpp"
#include "GUI/Events/WidgetEvent.hpp"
#include "GUI/Widgets/Window.hpp"

#include <cstdio>

Window::Window(const Vector2u& size)
    : ContainerWidget{Rect2{size}},
      mouse_grabbing_widget_{nullptr},
      focus_widget_{nullptr},
      context_menu_{nullptr} {}

Window::~Window() {}

void Window::OnRenderToWindow(RenderWindow* window) {
    assert(window != nullptr);

    texture_->Clear(Color(1.f, 1.f, 1.f, 1.f));
    RenderChildren(texture_);
    if (context_menu_ != nullptr) {
        context_menu_->OnRender(texture_);
    }
    texture_->Display();

    window->RenderImage(Image(texture_));
}

bool Window::OnEvent(const Event* event) {
    assert(event != nullptr);

    bool handled = CallEventCallback(event);
    if (handled) {
        return true;
    }

    return DispatchEventToChildren(event);
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

    mouse_grabbing_widget_ = nullptr;
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

bool Window::OnShowContextMenuEvent(const ShowContextMenuEvent* event) {
    assert(event != nullptr);

    mouse_grabbing_widget_ = nullptr;
    focus_widget_          = nullptr;

    Menu* context_menu = event->GetContextMenu();
    assert(context_menu != nullptr);

    children_.push_front(context_menu);

    return true;
}

bool Window::OnHideContextMenuEvent(const HideContextMenuEvent* event) {
    assert(event != nullptr);

    children_.pop_front();

    return true;
}