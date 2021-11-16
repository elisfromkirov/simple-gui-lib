#include "Core/EventManager/EventManager.hpp"
#include "GUI/Widgets/Slider.hpp"

Thumb::Thumb(const Vector2u& size, const Vector2i& position)
    : Widget{size, position},
      pressed_{false} {}

Thumb::~Thumb() {}

bool Thumb::OnMouseButtonPressEvent(const MouseButtonPressEvent* event) {
    assert(event != nullptr);
    
    if (!HitTest(event->GetMousePosition())) {
        return false;
    }

    pressed_ = true;

    return true;
}

bool Thumb::OnMouseButtonReleaseEvent(const MouseButtonReleaseEvent* event) {
    assert(event != nullptr);

    if (!pressed_) {
        return false;
    }

    pressed_ = false;

    return true;
}

bool Thumb::OnMouseMoveEvent(const MouseMoveEvent* event) {
    assert(event != nullptr);

    if (!pressed_) {
        return false;
    }

    Vector2i position = event->GetMousePosition();
    position.x = std::max(position.x, bounds_.position.x);
    position.x = std::min(position.x, bounds_.position.x + static_cast<int32_t>(bounds_.size.x));
    position.y = std::max(position.y, bounds_.position.y);
    position.y = std::min(position.y, bounds_.position.y + static_cast<int32_t>(bounds_.size.y));

    Vector2i displacement = position - position_;
    position_ = position;

    return true;
}

const Rect2i& Thumb::GetBounds() const {
    return bounds_;    
}

void Thumb::SetBounds(const Rect2i& bounds) {
    bounds_ = bounds;
}

VerticalSlider::VerticalSlider(const Vector2u& size, const Vector2i& position)
    : CompositeWidget{size, position},
      thumb_{nullptr},
      factor_{0.f} {
    assert(size.x < size.y);

    thumb_ = new Thumb(Vector2u{size.x, size.x}, Vector2i{0, 0});
    thumb_->SetBounds(Rect2i{Vector2u{size.x, size.y - size.x}, Vector2i{0, 0}});    
    Attach(thumb_);
}

VerticalSlider::~VerticalSlider() {}

bool VerticalSlider::OnMouseMoveEvent(const MouseMoveEvent* event) {
    assert(event != nullptr);

    bool handled = DispatchMouseMoveEventToChildren(event);
    if (!handled) {
        return false;
    }

    factor_ = static_cast<float>(thumb_->GetPosition().y)/static_cast<float>(size_.y - size_.x);
    SliderMoved(factor_);

    return true;
}
