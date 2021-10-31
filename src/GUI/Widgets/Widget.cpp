
#include "Widget.hpp"

Widget::Widget(const Vector2u& size, const Vector2u& position)
    : size_{size},
      position_{position},
      parent_{nullptr},
      handlers_{} {}

Widget::~Widget() {}

bool Widget::HitTest(const Vector2u& point) const {
    return position_.x < point.x && point.x < position_.x + size_.x &&
           position_.y < point.y && point.y < position_.y + size_.y; 
}

void Widget::OnRender(Renderer* renderer) {}

bool Widget::OnMouseButtonPress(const MouseButtonPressEvent* event) {
    assert(event != nullptr);

    return OnMouseEvent<MouseButtonPressEvent, kMouseButtonPress>(event);    
}

bool Widget::OnMouseButtonRelease(const MouseButtonReleaseEvent* event) {
    assert(event != nullptr);

    return OnMouseEvent<MouseButtonReleaseEvent, kMouseButtonRelease>(event);
}

bool Widget::OnMouseMove(const MouseMoveEvent* event) {
    assert(event != nullptr);

    return OnMouseEvent<MouseMoveEvent, kMouseMove>(event);
}

Vector2u Widget::GetSize() const {
    return size_;
}

void Widget::SetSize(const Vector2u& size) {
    size_ = size;
}

Vector2u Widget::GetPosition() const {
    return position_;
}

void Widget::SetPosition(const Vector2u& position) {
    position_ = position;
}

Widget* Widget::GetParent() const {
    return parent_;
}

void Widget::SetParent(Widget* parent) {
    parent_ = parent;
}