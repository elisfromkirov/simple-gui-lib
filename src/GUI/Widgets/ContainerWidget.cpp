#include "Core/EventManager/EventManager.hpp"
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
      styles_{} {
    SetEventFilter<ContainerWidget, MouseMoveEvent> (this, &ContainerWidget::FilterMouseMoveEvent);
}

ContainerWidget::ContainerWidget(const Rect2& rect)
    : ContainerWidget{} {
    rect_    = rect;

    texture_ = new RenderTexture(rect.size);
}

ContainerWidget::~ContainerWidget() {
    delete texture_;
    
    for (auto iter = children_.begin(); iter != children_.end(); ++iter) {
        delete (*iter);
    }

    for (auto iter = styles_.begin(); iter != styles_.end(); ++iter) {
        delete (*iter);
    }
}

bool ContainerWidget::FilterMouseMoveEvent(const MouseMoveEvent* event) {
    assert(event != nullptr);

    if (!(HitTest(event->GetMousePosition()) && HitTest(event->GetOldMousePosition()))) {
        return false;
    }

    for (auto iter = children_.begin(); iter != children_.end(); ++iter) {
        if ((*iter)->HitTest(event->GetOldMousePosition())) {
            EventManager::GetInstance()->PostEvent<MouseLeaveEvent>(*iter, event->GetOldMousePosition());
        }
        if ((*iter)->HitTest(event->GetMousePosition())) {
            EventManager::GetInstance()->PostEvent<MouseEnterEvent>(*iter, event->GetMousePosition());
        }
    }
    return true;
}

bool ContainerWidget::OnEvent(const Event* event) {
    assert(event != nullptr);

    FilterEvent(event);

    for (auto iter = children_.begin(); iter != children_.end(); ++iter) {
        bool handled = (*iter)->OnEvent(event);
        if (handled) {
            return true;
        }
    }

    return HandleEvent(event);
}

bool ContainerWidget::OnMouseEnterEvent(const MouseEnterEvent* event) {
    assert(event != nullptr);

    for (auto iter = children_.begin(); iter != children_.end(); ++iter) {
        if ((*iter)->HitTest(event->GetMousePosition())) {
            (*iter)->OnMouseEnterEvent(event);
        }
    }

    return false;
}

bool ContainerWidget::OnMouseLeaveEvent(const MouseLeaveEvent* event) {
    assert(event != nullptr);

    for (auto iter = children_.begin(); iter != children_.end(); ++iter) {
        if ((*iter)->HitTest(event->GetMousePosition())) {
            (*iter)->OnMouseLeaveEvent(event);
        }
    }

    return true;
}

void ContainerWidget::Resize(const Vector2u& size) {
    delete texture_;
    texture_ = new RenderTexture(size);

    rect_.size = size;
}

void ContainerWidget::Move(const Vector2i& position) {
    for (auto iter = children_.begin(); iter != children_.end(); ++iter) {
        (*iter)->Move((*iter)->GetPosition() - rect_.position + position);
    }

    rect_.position = position;
}

void ContainerWidget::OnRender(IRenderTarget* render_target) {
    assert(texture_      != nullptr);
    assert(render_target != nullptr);

    texture_->Clear();

    for (auto iter = styles_.begin(); iter != styles_.end(); ++iter) {
        (*iter)->Apply(this, texture_);
    }

    for (auto iter = children_.rbegin(); iter != children_.rend(); ++iter) {
        (*iter)->OnRender(texture_);
    }

    texture_->Display();

    render_target->RenderImage(Image(texture_, MapPositionToParent()));
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