#include "GUI/Widgets/Widget.hpp"

Widget::Widget(const Vector2u& size, const Vector2u& position)
    : size_{size},
      position_{position},
      parent_{nullptr} {}

Widget::~Widget() {
    for (auto iter = children_.begin(); iter != children_.end(); ++iter) {
        Widget* child = *iter;

        delete child;
    }
}

bool Widget::OnEvent(const Event* event) {
    switch (event->GetType()) {
        case kMouseButtonPress:
            return OnMouseButtonPress(reinterpret_cast<const MouseButtonPressEvent*>(event));
        
        case kMouseButtonRelease:
            return OnMouseButtonRelease(reinterpret_cast<const MouseButtonReleaseEvent*>(event));
        
        case kMouseMove:
            return OnMouseMove(reinterpret_cast<const MouseMoveEvent*>(event));
    }

    return false;
}

bool Widget::HitTest(const Vector2u& point) const {
    return position_.x < point.x && point.x < position_.x + size_.x &&
           position_.y < point.y && point.y < position_.y + size_.y; 
}

void Widget::OnRender(Renderer* renderer) const {
    assert(renderer != nullptr);

    for (auto iter = children_.rbegin(); iter != children_.rend(); ++iter) {
        (*iter)->OnRender(renderer);
    }
}

bool Widget::Attach(Widget* widget) {
    assert(widget != nullptr);

    if (widget->GetParent() != nullptr) {
        return false;
    }

    widget->parent_ = this;
    children_.push_front(widget);

    return true;
}

bool Widget::Detach(Widget* widget) {
    assert(widget != nullptr);

    if (widget->GetParent() != this) {
        return false;
    }

    widget->parent_ = nullptr;
    children_.remove(widget);

    return true;
}

const Vector2u& Widget::GetSize() const {
    return size_;
}

const Vector2u& Widget::GetPosition() const {
    return position_;
}

Widget* Widget::GetParent() const {
    return parent_;
}

bool Widget::OnMouseButtonPress(const MouseButtonPressEvent* event) {
    assert(event != nullptr);

    for (auto iter = children_.begin(); iter != children_.end(); ++iter) {
        if ((*iter)->HitTest(event->GetMousePosition())) {
            continue;
        }

        bool handled = (*iter)->OnMouseButtonPress(event);
        if (handled) {
            return true;
        }
    }

    return false;
}

bool Widget::OnMouseButtonRelease(const MouseButtonReleaseEvent* event) {
    assert(event != nullptr);

    for (auto iter = children_.begin(); iter != children_.end(); ++iter) {
        if ((*iter)->HitTest(event->GetMousePosition())) {
            continue;
        }

        bool handled = (*iter)->OnMouseButtonRelease(event);
        if (handled) {
            return true;
        }
    }

    return false;
}

bool Widget::OnMouseMove(const MouseMoveEvent* event) {
    assert(event != nullptr);

    for (auto iter = children_.begin(); iter != children_.end(); ++iter) {
        if ((*iter)->HitTest(event->GetMousePosition())) {
            continue;
        }

        bool handled = (*iter)->OnMouseMove(event);
        if (handled) {
            return true;
        }
    }

    return false;
}
