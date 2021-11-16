#include "GUI/Widgets/CompositeWidget.hpp"

CompositeWidget::CompositeWidget(const Vector2u& size, const Vector2i& position)
    : Widget{size, position},
      surface_{size},
      children_{} {}

CompositeWidget::~CompositeWidget() {
    for (auto iter = children_.begin(); iter != children_.end(); ++iter) {
        Widget* child = *iter;

        delete child;
    }
}

void CompositeWidget::OnRender(Renderer* renderer) {
    assert(renderer != nullptr);

    IRenderTarget* surface = renderer->GetRenderTarget();
    renderer->SetRenderTarget(&surface_);

    renderer->Clear();

    ApplyStyles(renderer);

    RenderChildren(renderer);

    renderer->Display();

    renderer->SetRenderTarget(surface);
    renderer->CopyTexture(&surface_, position_);
}

bool CompositeWidget::OnMouseButtonPressEvent(const MouseButtonPressEvent* event) {
    assert(event != nullptr);

    return DispatchMouseButtonPressEventToChildren(event);
}

bool CompositeWidget::OnMouseButtonReleaseEvent(const MouseButtonReleaseEvent* event) {
    assert(event != nullptr);

    return DispatchMouseButtonReleaseEventToChildren(event);
}

bool CompositeWidget::OnMouseMoveEvent(const MouseMoveEvent* event) {
    assert(event != nullptr);

    return DispatchMouseMoveEventToChildren(event);
}

void CompositeWidget::RenderChildren(Renderer* renderer) {
    assert(renderer != nullptr);

    for (auto iter = children_.begin(); iter != children_.end(); ++iter) {
        Widget* child = *iter;

        child->OnRender(renderer);
    }
}

bool CompositeWidget::DispatchMouseButtonPressEventToChildren(const MouseButtonPressEvent* event) {
    assert(event != nullptr);

    Vector2i position = event->GetMousePosition();
    event->SetMousePosition(position - position_);

    for (auto iter = children_.begin(); iter != children_.end(); ++iter) {
        Widget* child = *iter;

        bool handled = child->OnMouseButtonPressEvent(event);
        if (handled) {
            return true;
        }
    }

    event->SetMousePosition(position);

    return false;
}

bool CompositeWidget::DispatchMouseButtonReleaseEventToChildren(const MouseButtonReleaseEvent* event) {
    assert(event != nullptr);

    Vector2i position = event->GetMousePosition();
    event->SetMousePosition(position - position_);

    for (auto iter = children_.begin(); iter != children_.end(); ++iter) {
        Widget* child = *iter;

        bool handled = child->OnMouseButtonReleaseEvent(event);
        if (handled) {
            return true;
        }
    }

    event->SetMousePosition(position);

    return false;
}

bool CompositeWidget::DispatchMouseMoveEventToChildren(const MouseMoveEvent* event) {
    assert(event != nullptr);

    Vector2i position = event->GetMousePosition();
    event->SetMousePosition(position - position_);

    for (auto iter = children_.begin(); iter != children_.end(); ++iter) {
        Widget* child = *iter;

        bool handled = child->OnMouseMoveEvent(event);
        if (handled) {
            return true;
        }
    }

    event->SetMousePosition(position);

    return false;
}

bool CompositeWidget::Attach(Widget* widget) {
    assert(widget != nullptr);

    if (widget->GetParent() != nullptr) {
        return false;
    }

    widget->SetParent(this);
    children_.push_front(widget);

    return true;
}

bool CompositeWidget::Detach(Widget* widget) {
    assert(widget != nullptr);

    if (widget->GetParent() != this) {
        return false;
    }

    widget->SetParent(nullptr);
    children_.remove(widget);

    return true;
}
