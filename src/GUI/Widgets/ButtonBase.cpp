#include "GUI/Widgets/ButtonBase.hpp"

ButtonBase::ButtonBase(const Vector2u& size, const Vector2i& position)
    : Widget{size, position},
      pressed_{false} {
    filled_ = true;
    fill_color_ = Color(0.f, 1.f, 0.f);
}

ButtonBase::~ButtonBase() {}

bool ButtonBase::OnMouseButtonPress(const MouseButtonPressEvent* event) {
    assert(event != nullptr);
    
    if (HitTest(event->GetMousePosition())) {
        pressed_ = true;
        Pressed();
        return true;
    }

    return false;
}

bool ButtonBase::OnMouseButtonRelease(const MouseButtonReleaseEvent* event) {
    assert(event != nullptr);

    if (HitTest(event->GetMousePosition()) && pressed_ == true) {
        pressed_ = false;
        Click();
        return true;
    }

    return false;
}
