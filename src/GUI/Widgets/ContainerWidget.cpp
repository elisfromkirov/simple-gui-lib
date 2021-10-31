#include "ContainerWidget.hpp"

ContainerWidget::ContainerWidget(const Vector2u& size, const Vector2u& position)
    : Widget{size, position} {}

ContainerWidget::~ContainerWidget() {
    for (auto iter = children_.begin(); iter != children_.end(); ++iter) {
        Widget* child = *iter;

        delete child;
    }
}

void ContainerWidget::OnRender(Renderer* renderer) {
    assert(renderer != nullptr);

    for (auto iter = children_.begin(); iter != children_.end(); ++iter) {
        (*iter)->OnRender(renderer);
    }
}

bool ContainerWidget::OnMouseButtonPress(const MouseButtonPressEvent* event) {
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

    return HandleEvent<MouseButtonPressEvent, kMouseButtonPress>(event);
}

bool ContainerWidget::OnMouseButtonRelease(const MouseButtonReleaseEvent* event) {
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

    return HandleEvent<MouseButtonReleaseEvent, kMouseButtonRelease>(event);
}

bool ContainerWidget::OnMouseMove(const MouseMoveEvent* event) {
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

    return HandleEvent<MouseMoveEvent, kMouseMove>(event);
}

bool ContainerWidget::Attach(Widget* widget, const Vector2u& relative_position) {
    assert(widget != nullptr);

    if (widget->GetParent() != nullptr) {
        return false;
    }

    widget->SetParent(this);
    widget->SetPosition(widget->GetPosition() + relative_position);

    children_.push_front(widget);

    return true;
}

bool ContainerWidget::Detach(Widget* widget) {
    assert(widget != nullptr);

    if (widget->GetParent() != this) {
        return false;
    }

    widget->SetParent(nullptr);

    children_.remove(widget);

    return true;
}
