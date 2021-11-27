#include "Core/Platform/InputEvent.hpp"
#include "GUI/Events/WidgetEvent.hpp"
#include "GUI/Widgets/ContainerWidget.hpp"

ContainerWidget::ContainerWidget(const Vector2u& size, const Vector2i& position)
    : Widget{size, position},
      children_{} {}

ContainerWidget::~ContainerWidget() {
    for (auto iter = children_.begin(); iter != children_.end(); ++iter) {
        delete (*iter);
    }
}

bool ContainerWidget::OnEvent(const Event* event) {
    assert(event != nullptr);

    bool handled = DispatchToChildren(event);
    if (handled) {
        return true;
    }

    return CallEventCallback(event);
}

void ContainerWidget::Resize(const Vector2u& size) {
    surface_.SetSize(size);
}

void ContainerWidget::Move(const Vector2i& position) {
    for (auto iter = children_.begin(); iter != children_.end(); ++iter) {
        Widget* child = *iter;

        child->Move(child->GetPosition() - position_ + position);
    }

    position_ = position;
}

void ContainerWidget::OnRender() {
    texture_.Clear();

    ApplyStyles();
    RenderChildren();

    texture_.Display();
}

void ContainerWidget::RenderChildren() {
    for (auto iter = children_.begin(); iter != children_.end(); ++iter) {
        (*iter)->OnRender(renderer);
    }
}

bool ContainerWidget::Attach(Widget* widget) {
    assert(widget != nullptr);

    if (widget->GetParent() != nullptr) {
        return false;
    }

    widget->SetParent(this);
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

bool ContainerWidget::DispatchToChildren(const Event* event) {
    assert(event != nullptr);

    for (auto iter = children_.begin(); iter != children_.end(); ++iter) {
        bool handled = (*iter)->OnMouseMoveEvent(event);
        if (handled) {
            return true;
        }
    }

    return false;
}