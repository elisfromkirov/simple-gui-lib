#include "Core/EventManager/EventManager.hpp"
#include "Core/Platform/InputEvent.hpp"
#include "GUI/Events/WidgetEvent.hpp"
#include "GUI/Widgets/Slider.hpp"

Thumb::Thumb(const Vector2u& size, const Rect2& bounds)
    : Widget{Rect2{std::min(size.x, bounds.size.x), std::min(size.y, bounds.size.y), 
                   bounds.position.x, bounds.position.y}},
      bounds_{bounds},
      value_{0.f, 0.f} {}

Thumb::~Thumb() {}

void Thumb::Resize(const Vector2u& size) {
    rect_.size.x = std::min(size.x, bounds_.size.x); 
    rect_.size.y = std::min(size.y, bounds_.size.y);

    UpdateValue();
}

void Thumb::Move(const Vector2i& position) {
    rect_.position = position;

    UpdateValue();
}

bool Thumb::OnMouseButtonPressEvent(const MouseButtonPressEvent* event) {
    assert(event != nullptr);

    if (!HitTest(event->GetMousePosition())) {
        return false;
    }
    pressed_ = true;

    EventManager::GetInstance()->PostEvent<MouseCaptureEvent>(this);

    return true;
}

bool Thumb::OnMouseButtonReleaseEvent(const MouseButtonReleaseEvent* event) {
    assert(event != nullptr);

    if (!pressed_) {
        return false;
    }
    pressed_ = false;

    EventManager::GetInstance()->PostEvent<MouseCaptureLostEvent>(this);

    return true;
}

bool Thumb::OnMouseMoveEvent(const MouseMoveEvent* event) {
    assert(event != nullptr);

    if (!pressed_) {
        return false;
    }

    Vector2i position{rect_.position + event->GetMousePosition() - event->GetOldMousePosition()};
    position.x = std::max(position.x, bounds_.position.x);
    position.x = std::min(position.x, bounds_.position.x +
                                      static_cast<int32_t>(bounds_.size.x - rect_.size.x));
    position.y = std::max(position.y, bounds_.position.y);
    position.y = std::min(position.y, bounds_.position.y +
                                      static_cast<int32_t>(bounds_.size.y - rect_.size.x));

    EventManager::GetInstance()->PostEvent<MoveEvent>(this, position, rect_.position);

    return true;
}

void Thumb::SetBounds(const Rect2& bounds) {
    bounds_ = bounds;
}

const Rect2& Thumb::GetBounds() const {
    return bounds_;
}

void Thumb::SetValue(const Vector2f& value) {
    assert(value.x <= 1.f);
    assert(value.y <= 1.f);

    Vector2i position(bounds_.position.x + ((bounds_.size.x - rect_.size.x) * value.x), 
                      bounds_.position.y + ((bounds_.size.y - rect_.size.y) * value.y));

    EventManager::GetInstance()->PostEvent<MoveEvent>(this, position, rect_.position);
}

const Vector2f& Thumb::GetValue() const {
    return value_;
}

void Thumb::UpdateValue() {
    value_.x = static_cast<float>(rect_.position.x - bounds_.position.x) /
               static_cast<float>(bounds_.size.x - rect_.size.x);
    value_.y = static_cast<float>(rect_.position.y - bounds_.position.y) /
               static_cast<float>(bounds_.size.y - rect_.size.y);

    ValueChanged(value_);
}

HorizontalSlider::HorizontalSlider(const Rect2& rect, uint32_t thumb_width)
    : ContainerWidget{rect},
      thumb_{nullptr} {
    thumb_ = new Thumb(Vector2u(thumb_width, rect.size.y), rect);
    thumb_->ValueChanged.Connect<HorizontalSlider>(this, &HorizontalSlider::ValueChangeResponse);
    Attach(thumb_);
}

HorizontalSlider::~HorizontalSlider() {}

void HorizontalSlider::Move(const Vector2i& position) {
    assert(thumb_ != nullptr);

    Rect2 bounds{thumb_->GetBounds()};
    bounds.position = position;
    thumb_->SetBounds(bounds);

    ContainerWidget::Move(position);
}

void HorizontalSlider::Resize(const Vector2u& size) {
    assert(thumb_ != nullptr);

    Rect2 bounds{thumb_->GetBounds()};
    bounds.size = size;
    thumb_->SetBounds(bounds);

    ContainerWidget::Resize(size);
}

uint32_t HorizontalSlider::GetThumbWidth() const {
    assert(thumb_ != nullptr);

    return thumb_->GetSize().x;
}

void HorizontalSlider::SetThumbWidth(uint32_t width) {
    assert(thumb_ != nullptr);

    thumb_->Resize(Vector2u{width, rect_.size.y});
}

float HorizontalSlider::GetValue() {
    assert(thumb_ != nullptr);

    return thumb_->GetValue().x;
}

void HorizontalSlider::SetValue(float value) {
    assert(thumb_ != nullptr);

    thumb_->SetValue(Vector2f{value, 0.f});
}

void HorizontalSlider::ValueChangeResponse(const Vector2f& value) {
    ValueChanged(value.x);
}


VerticalSlider::VerticalSlider(const Rect2& rect, uint32_t thumb_height)
    : ContainerWidget{rect},
      thumb_{nullptr} {
    thumb_ = new Thumb(Vector2u(rect.size.x, thumb_height), rect);
    thumb_->ValueChanged.Connect<VerticalSlider>(this, &VerticalSlider::ValueChangeResponse);
    Attach(thumb_);
}

VerticalSlider::~VerticalSlider() {}

void VerticalSlider::Move(const Vector2i& position) {
    assert(thumb_ != nullptr);

    Rect2 bounds{thumb_->GetBounds()};
    bounds.position = position;
    thumb_->SetBounds(bounds);

    ContainerWidget::Move(position);
}

void VerticalSlider::Resize(const Vector2u& size) {
    assert(thumb_ != nullptr);

    Rect2 bounds{thumb_->GetBounds()};
    bounds.size = size;
    thumb_->SetBounds(bounds);

    ContainerWidget::Resize(size);
}

uint32_t VerticalSlider::GetThumbHeight() const {
    assert(thumb_ != nullptr);

    return thumb_->GetSize().y;   
}

void VerticalSlider::SetThumbHeight(uint32_t height) {
    assert(thumb_ != nullptr);

    thumb_->Resize(Vector2u{rect_.size.x, height});
}

float VerticalSlider::GetValue() {
    assert(thumb_ != nullptr);

    return thumb_->GetValue().y;
}

void VerticalSlider::SetValue(float value) {
    assert(thumb_ != nullptr);

    thumb_->SetValue(Vector2f{0.f, value});
}

void VerticalSlider::ValueChangeResponse(const Vector2f& value) {
    ValueChanged(value.y);
}