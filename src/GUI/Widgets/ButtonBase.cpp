#include "Core/EventManager/EventManager.hpp"
#include "GUI/Widgets/ButtonBase.hpp"

ButtonBase::ButtonBase(const Vector2u& size, const Vector2i& position)
    : Widget{size, position} {}

ButtonBase::~ButtonBase() {}

bool ButtonBase::OnMouseButtonPressEvent(const MouseButtonPressEvent* event) {
    assert(event != nullptr);

    if (!HitTest(event->GetMousePosition())) {
        return false;
    }

    state_ = kPressed;

    EventManager* event_manager = EventManager::GetEventManager();
    assert(event_manager != nullptr);

    event_manager->PostEvent<MouseCaptureRequestEvent>(this);

    return true;
}

bool ButtonBase::OnMouseButtonReleaseEvent(const MouseButtonReleaseEvent* event) {
    assert(event != nullptr);

    if (state_ != kPressed) {
        return false;
    }

    state_ = kReleased;

    EventManager* event_manager = EventManager::GetEventManager();
    assert(event_manager != nullptr);

    event_manager->PostEvent<MouseCaptureLostEvent>(this);

    if (HitTest(event->GetMousePosition())) {
        Clicked();
        return true;
    }

    return true;
}

bool ButtonBase::OnMouseMoveEvent(const MouseMoveEvent* event) {
    assert(event != nullptr);

    if (state_ == kPressed) {
        return true;
    }

    if (HitTest(event->GetMousePosition())) {
        state_ = kHovered;
        return true;
    }

    return false;
}