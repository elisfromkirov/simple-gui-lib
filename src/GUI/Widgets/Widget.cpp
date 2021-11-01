#include "Widget.hpp"

Widget::Widget(const Vector2u& size, const Vector2u& position)
    : size_{size},
      position_{position},
      parent_{nullptr},
      handlers_{} {}

Widget::~Widget() {
    for (auto iter = children_.begin(); iter != children_.end(); ++iter) {
        Widget* child = *iter;

        delete child;
    }
}

bool Widget::HitTest(const Vector2u& point) const {
    return position_.x < point.x && point.x < position_.x + size_.x &&
           position_.y < point.y && point.y < position_.y + size_.y; 
}

void Widget::OnRender(Renderer* renderer) {
    assert(renderer != nullptr);

    for (auto iter = children_.rbegin(); iter != children_.rend(); ++iter) {
        (*iter)->OnRender(renderer);
    }
}

bool Widget::OnMouseButtonPress(const MouseButtonPressEvent* event) {
    assert(event != nullptr);

    for (auto iter = children_.begin(); iter != children_.end(); ++iter) {
        if ((*iter)->HitTest(event->GetPosition())) {
            continue;
        }

        bool handled = (*iter)->OnMouseButtonPress(event);
        if (handled) {
            return true;
        }
    }

    return OnMouseEvent<MouseButtonPressEvent, kMouseButtonPress>(event);
}

bool Widget::OnMouseButtonRelease(const MouseButtonReleaseEvent* event) {
    assert(event != nullptr);

    for (auto iter = children_.begin(); iter != children_.end(); ++iter) {
        if ((*iter)->HitTest(event->GetPosition())) {
            continue;
        }

        bool handled = (*iter)->OnMouseButtonRelease(event);
        if (handled) {
            return true;
        }
    }

    return OnMouseEvent<MouseButtonReleaseEvent, kMouseButtonRelease>(event);
}

bool Widget::OnMouseMove(const MouseMoveEvent* event) {
    assert(event != nullptr);

    for (auto iter = children_.begin(); iter != children_.end(); ++iter) {
        if ((*iter)->HitTest(event->GetPosition())) {
            continue;
        }

        bool handled = (*iter)->OnMouseMove(event);
        if (handled) {
            return true;
        }
    }

    return OnMouseEvent<MouseMoveEvent, kMouseMove>(event);
}

bool Widget::Attach(Widget* widget, const Vector2u& relative_position) {
    assert(widget != nullptr);

    if (widget->GetParent() != nullptr) {
        return false;
    }

    widget->SetParent(this);
    widget->SetPosition(widget->GetPosition() + relative_position);

    children_.push_front(widget);

    return true;
}

bool Widget::Detach(Widget* widget) {
    assert(widget != nullptr);

    if (widget->GetParent() != this) {
        return false;
    }

    widget->SetParent(nullptr);

    children_.remove(widget);

    return true;
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
    for (auto iter = children_.begin(); iter != children_.end(); ++iter) {
        (*iter)->SetPosition(position_ + (*iter)->GetPosition() - position);
    }

    position_ = position;
}

Widget* Widget::GetParent() const {
    return parent_;
}

void Widget::SetParent(Widget* parent) {
    parent_ = parent;
}
