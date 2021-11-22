#include "Core/EventManager/EventManager.hpp"
#include "GUI/Widgets/Button.hpp"

Button::Button(const Vector2u& size, const Vector2i& position)
    : Widget{size, position} {}

Button::~Button() {}

bool Button::OnMouseButtonPressEvent(const MouseButtonPressEvent* event) {
    assert(event != nullptr);

    if (!HitTest(event->GetMousePosition())) {
        return false;
    }

    state_ = kPressed;

    EventManager* event_manager = EventManager::GetInstance();
    assert(event_manager != nullptr);

    event_manager->PostEvent<MouseCaptureEvent>(this);

    return true;
}

bool Button::OnMouseButtonReleaseEvent(const MouseButtonReleaseEvent* event) {
    assert(event != nullptr);

    if (state_ != kPressed) {
        return false;
    }

    state_ = kReleased;

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

    if (state_ == kPressed) {
        return true;
    }

    return false;
}