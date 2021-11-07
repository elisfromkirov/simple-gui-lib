#include "GUI/Widgets/Widget.hpp"

Widget::Widget(const Vector2u& size, const Vector2i& position)
    : size_{size},
      position_{position},
      parent_{nullptr},
      children_{},
      visible_{true} {}

Widget::~Widget() {
    for (auto iter = children_.begin(); iter != children_.end(); ++iter) {
        delete (*iter);
    }
}

void Widget::OnRender(Renderer* renderer) const {
    assert(renderer != nullptr);

    Render(renderer);

    for (auto iter = children_.rbegin(); iter != children_.rend(); ++iter) {
        if ((*iter)->IsVisible()) {
            (*iter)->OnRender(renderer);
        }
    }
}

void Widget::OnResize(const Vector2u& size) {
    Resize(size);

    for (auto iter = children_.begin(); iter != children_.end(); ++iter) {
        (*iter)->Resize(size);
    }
}

void Widget::OnMove(const Vector2i& displacement) {
    Move(displacement);

    for (auto iter = children_.begin(); iter != children_.end(); ++iter) {
        (*iter)->Move(displacement);
    }
}

Widget* Widget::OnHitTest(const Vector2u& point) {
    for (auto iter = children_.begin(); iter != children_.end(); ++iter) {
        Widget* hit_widget = (*iter)->OnHitTest(point);
        if (hit_widget != nullptr) {
            return hit_widget;
        }
    }

    if (Contains(point)) {
        return this;
    }

    return nullptr;
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

const Vector2i& Widget::GetPosition() const {
    return position_;
}

Widget* Widget::GetParent() const {
    return parent_;
}

bool Widget::IsVisible() {
    return visible_;
}

void Widget::SetVisible(bool visible) {
    visible_ = visible;
}

bool Widget::OnMouseButtonPress(const MouseButtonPressEvent* event) {
    assert(event != nullptr);

    for (auto iter = children_.begin(); iter != children_.end(); ++iter) {
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
        bool handled = (*iter)->OnMouseMove(event);
        if (handled) {
            return true;
        }
    }

    return false;
}

bool Widget::OnMouseHover(const MouseHoverEvent* event) {
    assert(event != nullptr);

    return true;
}

bool Widget::OnMouseLeave(const MouseLeaveEvent* event) {
    assert(event != nullptr);

    return true;
}

bool Widget::Contains(const Vector2u& point) const {
    return static_cast<uint32_t>(position_.x) < point.x && point.x < position_.x + size_.x &&
           static_cast<uint32_t>(position_.y) < point.y && point.y < position_.y + size_.y; 
}

void Widget::Render(Renderer* renderer) const {
    assert(renderer != nullptr);
}

void Widget::Resize(const Vector2u& size) {
    size_ = size;
}

void Widget::Move(const Vector2i& displacement) {
    position_ += displacement;
}
