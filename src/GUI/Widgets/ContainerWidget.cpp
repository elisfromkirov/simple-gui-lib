#include "Core/Platform/Color.hpp"
#include "Core/Platform/InputEvent.hpp"
#include "Core/Platform/Image.hpp"
#include "Core/Platform/RenderTexture.hpp"
#include "GUI/Events/WidgetEvent.hpp"
#include "GUI/Styles/IStyle.hpp"
#include "GUI/Widgets/ContainerWidget.hpp"

ContainerWidget::ContainerWidget()
    : Widget{},
      texture_{nullptr},
      children_{}, 
      styles_{} {}

ContainerWidget::ContainerWidget(const Rect2& rect)
    : Widget{rect},
      texture_{nullptr},
      children_{} {
    texture_ = new RenderTexture(rect.size);
}

ContainerWidget::~ContainerWidget() {
    for (auto iter = children_.begin(); iter != children_.end(); ++iter) {
        delete (*iter);
    }

    for (auto iter = styles_.begin(); iter != styles_.end(); ++iter) {
        delete (*iter);
    }
}

bool ContainerWidget::OnEvent(const Event* event) {
    assert(event != nullptr);

    bool handled = DispatchEventToChildren(event);
    if (handled) {
        return true;
    }

    return CallEventCallback(event);
}

void ContainerWidget::Resize(const Vector2u& size) {
    ResizeTexture(size);

    rect_.size = size;
}

void ContainerWidget::Move(const Vector2i& position) {
    MoveChildren(position);

    rect_.position = position;
}

void ContainerWidget::OnRender(RenderTexture* texture) {
    assert(texture != nullptr);

    texture_->Clear(Color());
    RenderStyles(texture_);
    RenderChildren(texture_);
    texture_->Display();

    texture->RenderImage(Image(texture_, MapPositionToParent()));
}

bool ContainerWidget::Attach(Widget* widget) {
    assert(widget != nullptr);

    if (widget->GetParent() != nullptr) {
        return false;
    }

    widget->SetParent(this);
    children_.push_back(widget);

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

bool ContainerWidget::AttachInMiddle(Widget* widget) {
    assert(widget != nullptr);

    Vector2i position(rect_.position.x + (rect_.size.x - widget->GetSize().x) / 2,
                      rect_.position.y + (rect_.size.y - widget->GetSize().y) / 2);
    widget->Move(position);

    return Attach(widget);
}

bool ContainerWidget::AttachInTop(Widget* widget) {
    assert(widget != nullptr);

    Vector2i position(rect_.position.x + (rect_.size.x - widget->GetSize().x) / 2,
                      rect_.position.y);
    widget->Move(position);

    return Attach(widget);
}

bool ContainerWidget::AttachInBottom(Widget* widget) {
    assert(widget != nullptr);

    Vector2i position(rect_.position.x + (rect_.size.x - widget->GetSize().x) / 2,
                      rect_.position.y + rect_.size.y - widget->GetSize().y);
    widget->Move(position);

    return Attach(widget);
}

bool ContainerWidget::AttachInLeft(Widget* widget) {
    assert(widget != nullptr);

    Vector2i position(rect_.position.x,
                      rect_.position.y + (rect_.size.y - widget->GetSize().y) / 2);
    widget->Move(position);

    return Attach(widget);
}

bool ContainerWidget::AttachInRight(Widget* widget) {
    assert(widget != nullptr);

    Vector2i position(rect_.position.x + rect_.size.x - widget->GetSize().x,
                      rect_.position.y + (rect_.size.y - widget->GetSize().y) / 2);
    widget->Move(position);

    return Attach(widget);
}

void ContainerWidget::ApplyStyle(IStyle* style) {
    assert(style != nullptr);

    styles_.push_back(style);
}

void ContainerWidget::ResizeTexture(const Vector2u& size) {
    delete texture_;

    texture_ = new RenderTexture(size);
}

void ContainerWidget::MoveChildren(const Vector2i& position) {
    for (auto iter = children_.begin(); iter != children_.end(); ++iter) {
        (*iter)->Move((*iter)->GetPosition() - rect_.position + position);
    }
}

void ContainerWidget::RenderStyles(RenderTexture* texture) {
    assert(texture != nullptr);

    for (auto iter = styles_.begin(); iter != styles_.end(); ++iter) {
        (*iter)->Apply(this, texture);
    }
}

void ContainerWidget::RenderChildren(RenderTexture* texture) {
    assert(texture != nullptr);

    for (auto iter = children_.begin(); iter != children_.end(); ++iter) {
        (*iter)->OnRender(texture);
    }
}

bool ContainerWidget::DispatchEventToChildren(const Event* event) {
    assert(event != nullptr);

    for (auto iter = children_.begin(); iter != children_.end(); ++iter) {
        bool handled = (*iter)->OnEvent(event);
        if (handled) {
            return true;
        }
    }

    return false;
}