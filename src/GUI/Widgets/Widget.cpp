#include "GUI/Widgets/Widget.hpp"

Widget::Widget(const Vector2u& size, const Vector2i& position)
    : size_{size},
      position_{position},
      parent_{nullptr},
      children_{},
      visible_{true},
      resizable_{true},
      movable_{true},
      active_{false},
      filled_{false},
      fill_color_{} {}

Widget::~Widget() {
    for (auto iter = children_.begin(); iter != children_.end(); ++iter) {
        delete (*iter);
    }
}

void Widget::OnRender(Renderer* renderer) const {
    assert(renderer != nullptr);

    if (IsFilled()) {
        RenderBackGround(renderer);
    }

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
        if ((*iter)->IsResizable()) {
            (*iter)->OnResize(size);
        }
    }
}

void Widget::OnMove(const Vector2i& displacement) {
    Move(displacement);

    for (auto iter = children_.begin(); iter != children_.end(); ++iter) {
        if ((*iter)->IsMovable()) {
            (*iter)->OnMove(displacement);
        }
    }
}

bool Widget::HitTest(const Vector2u& point) const {
    Vector2u position(static_cast<uint32_t>(position_.x), static_cast<uint32_t>(position_.y));

    return  position.x < point.x && point.x < position.x + size_.x &&
            position.y < point.y && point.y < position_.y + size_.y; 
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

    return false;
}

bool Widget::OnMouseLeave(const MouseLeaveEvent* event) {
    assert(event != nullptr);

    return false;
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

bool Widget::IsVisible() const {
    return visible_;
}

void Widget::SetVisible(bool visible) {
    visible_ = visible;
}

bool Widget::IsResizable() const {
    return resizable_;
}

void Widget::SetResizable(bool resizable) {
    resizable_ = resizable;
}

bool Widget::IsMovable() const {
    return movable_;
}

void Widget::SetMovable(bool movable) {
    movable_ = movable;
}

bool Widget::IsActive() const {
    return active_;
}

void Widget::SetActive(bool active) {
    active_ = active;
}

bool Widget::IsFilled() const {
    return filled_;
}

void Widget::SetFilled(bool filled) {
    filled_ = filled;
}

const Color& Widget::GetFillColor() const {
    return fill_color_;
}

void Widget::SetFillColor(const Color& color) {
    fill_color_ = color;
}

void Widget::RenderBackGround(Renderer* renderer) const {
    assert(renderer != nullptr);

    renderer->RenderRectangle(position_, size_, fill_color_);
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
