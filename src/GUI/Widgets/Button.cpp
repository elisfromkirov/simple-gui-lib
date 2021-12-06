#include "Core/EventManager/EventManager.hpp"
#include "Core/Platform/InputEvent.hpp"
#include "GUI/Events/WidgetEvent.hpp"
#include "GUI/Widgets/Button.hpp"

Button::Button(const Rect2& rect)
    : ContainerWidget{rect} {}

Button::~Button() {}

bool Button::OnMouseButtonPressEvent(const MouseButtonPressEvent* event) {
    assert(event != nullptr);

    if (!HitTest(event->GetMousePosition())) {
        return false;
    }
    pressed_ = true;

    EventManager::GetInstance()->PostEvent<MouseCaptureInEvent>(this);

    return true;
}

bool Button::OnMouseButtonReleaseEvent(const MouseButtonReleaseEvent* event) {
    assert(event != nullptr);

    if (!pressed_) {
        return false;
    }
    pressed_ = false;

    EventManager::GetInstance()->PostEvent<MouseCaptureOutEvent>(this);

    if (HitTest(event->GetMousePosition())) {
        Clicked();
        return true;
    }

    return true;
}

bool Button::OnMouseMoveEvent(const MouseMoveEvent* event) {
    assert(event != nullptr);

    if (pressed_) {
        return true;
    }

    return false;
}

bool Button::OnMouseEnterEvent(const MouseEnterEvent* event) {
    assert(event != nullptr);

    hovered_ = true;
    return true;
}

bool Button::OnMouseLeaveEvent(const MouseLeaveEvent* event) {
    assert(event != nullptr);

    hovered_ = false;
    return true;
}