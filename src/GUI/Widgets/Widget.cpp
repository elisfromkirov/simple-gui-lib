#include "GUI/Widgets/Widget.hpp"
#include "GUI/Widgets/CompositeWidget.hpp"

Widget::Widget(const Vector2u& size, const Vector2i& position)
    : size_{size},
      position_{position},
      parent_{nullptr},
      state_{kReleased},
      styles_{} {}

Widget::~Widget() {
    for (auto iter = styles_.begin(); iter != styles_.end(); ++iter) {
        IStyle* style = (*iter);

        delete style;
    }
}

void Widget::OnRender(Renderer* renderer) {
    assert(renderer != nullptr);

    ApplyStyles(renderer);
}

Rect2 Widget::GetFillArea() const {
    return Rect2{size_, MapPositionToParent()};
}

void Widget::Resize(const Vector2u& size) {
    size_ = size;
}

void Widget::Move(const Vector2i& position) {
    position_ = position;
}

bool Widget::HitTest(const Vector2i& point) const {
    Vector2i relative_position = point - position_;
 
    return 0.f < relative_position.x && relative_position.x < static_cast<int32_t>(size_.x) &&
           0.f < relative_position.y && relative_position.y < static_cast<int32_t>(size_.y);
}

bool Widget::OnMouseButtonPressEvent(const MouseButtonPressEvent* event) {
    assert(event != nullptr);

    return false;
}

bool Widget::OnMouseButtonReleaseEvent(const MouseButtonReleaseEvent* event) {
    assert(event != nullptr);

    return false;
}

bool Widget::OnMouseMoveEvent(const MouseMoveEvent* event) {
    assert(event != nullptr);

    return false;
}

bool Widget::OnFocusInEvent(const FocusInEvent* event) {
    assert(event != nullptr);

    return false;
}

bool Widget::OnFocusOutEvent(const FocusOutEvent* event) {
    assert(event != nullptr);

    return false;
}

bool Widget::OnCloseEvent(const CloseEvent* event) {
    assert(event != nullptr);

    if (parent_ != nullptr) {
        parent_->Detach(this);
    }
    delete this;

    return false;
}

bool Widget::OnMoveEvent(const MoveEvent* event) {
    assert(event != nullptr);

    Move(event->GetNewPosition());    

    return true;
}

bool Widget::OnResizeEvent(const ResizeEvent* event) {
    assert(event != nullptr);

    Resize(event->GetNewSize());

    return true;
}

bool Widget::OnShowEvent(const ShowEvent* event) {
    assert(event != nullptr);

    return false;
}

bool Widget::OnHideEvent(const HideEvent* event) {
    assert(event != nullptr);

    return false;
}

const Vector2u& Widget::GetSize() const {
    return size_;
}

const Vector2i& Widget::GetPosition() const {
    return position_;
}

const CompositeWidget* Widget::GetParent() const {
    return parent_;
}

void Widget::SetParent(CompositeWidget* parent) {
    parent_ = parent;
}

Widget::State Widget::GetState() const {
    return state_;
}

void Widget::ApplyStyle(IStyle* style) {
    assert(style != nullptr);

    styles_.push_back(style);
}

void Widget::ApplyStyles(Renderer* renderer) {
    assert(renderer != nullptr);

    for (auto iter = styles_.begin(); iter != styles_.end(); ++iter) {
        IStyle* style = (*iter);

        style->Apply(this, renderer);
    }
}

Vector2i Widget::MapPositionToParent() const {
    if (parent_ != nullptr) {
        return position_ - parent_->GetPosition();
    }
    return position_;
}