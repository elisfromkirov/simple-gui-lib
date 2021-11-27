#include "Core/EventManager/EventManager.hpp"
#include "Core/Platform/InputEvent.hpp"
#include "GUI/Events/WidgetEvent.hpp"
#include "GUI/Widgets/Button.hpp"

Button::Button(const Vector2u& size, const Vector2i& position)
    : ContainerWidget{size, position} {}

Button::~Button() {}

bool Button::OnMouseButtonPressEvent(const MouseButtonPressEvent* event) {
    assert(event != nullptr);

    if (!HitTest(event->GetMousePosition())) {
        return false;
    }

    pressed_ = true;

    EventManager* event_manager = EventManager::GetInstance();
    assert(event_manager != nullptr);

    event_manager->PostEvent<MouseCaptureEvent>(this);

    return true;
}

bool Button::OnMouseButtonReleaseEvent(const MouseButtonReleaseEvent* event) {
    assert(event != nullptr);

    if (!pressed_) {
        return false;
    }

    pressed_ = false;

    EventManager* event_manager = EventManager::GetInstance();
    assert(event_manager != nullptr);

    event_manager->PostEvent<MouseCaptureLostEvent>(this);

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