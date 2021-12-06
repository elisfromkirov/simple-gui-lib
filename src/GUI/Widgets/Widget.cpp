#include "Core/Platform/InputEvent.hpp"
#include "GUI/Events/WidgetEvent.hpp"
#include "GUI/Widgets/Widget.hpp"
#include "GUI/Widgets/ContainerWidget.hpp"

Widget::Widget(const Rect2& rect)
    : rect_{rect},
      parent_{nullptr},
      pressed_{false},
      hovered_{false},
      hided_{false} {
    SetEventHandler<Widget, MouseButtonPressEvent>  (this, &Widget::OnMouseButtonPressEvent);
    SetEventHandler<Widget, MouseButtonReleaseEvent>(this, &Widget::OnMouseButtonReleaseEvent);
    SetEventHandler<Widget, MouseMoveEvent>         (this, &Widget::OnMouseMoveEvent);
    SetEventHandler<Widget, MouseCaptureInEvent>    (this, &Widget::OnMouseCaptureInEvent);
    SetEventHandler<Widget, MouseCaptureOutEvent>   (this, &Widget::OnMouseCaptureOutEvent);
    SetEventHandler<Widget, MouseEnterEvent>        (this, &Widget::OnMouseEnterEvent);
    SetEventHandler<Widget, MouseLeaveEvent>        (this, &Widget::OnMouseLeaveEvent);
    SetEventHandler<Widget, KeyPressEvent>          (this, &Widget::OnKeyPressEvent);
    SetEventHandler<Widget, KeyReleaseEvent>        (this, &Widget::OnKeyReleaseEvent);
    SetEventHandler<Widget, FocusInEvent>           (this, &Widget::OnFocusInEvent);
    SetEventHandler<Widget, FocusOutEvent>          (this, &Widget::OnFocusOutEvent);
    SetEventHandler<Widget, CloseEvent>             (this, &Widget::OnCloseEvent);
    SetEventHandler<Widget, MoveEvent>              (this, &Widget::OnMoveEvent);
    SetEventHandler<Widget, ResizeEvent>            (this, &Widget::OnResizeEvent);
    SetEventHandler<Widget, HorizontalScrollEvent>  (this, &Widget::OnHorizontalScrollEvent);
    SetEventHandler<Widget, VerticalScrollEvent>    (this, &Widget::OnVerticalScrollEvent);
    SetEventHandler<Widget, ShowPopUpWidgetEvent>   (this, &Widget::OnShowPopUpWidgetEvent);
    SetEventHandler<Widget, HidePopUpWidgetEvent>   (this, &Widget::OnHidePopUpWidgetEvent);
}

Widget::~Widget() {}

void Widget::Resize(const Vector2u& size) {
    rect_.size = size;
}

void Widget::Move(const Vector2i& position) {
    rect_.position = position;
}

bool Widget::HitTest(const Vector2i& point) const {
    return rect_.position.x < point.x && point.x < rect_.position.x + static_cast<int32_t>(rect_.size.x) && 
           rect_.position.y < point.y && point.y < rect_.position.y + static_cast<int32_t>(rect_.size.y); 
}

void Widget::OnRender(IRenderTarget* render_target) {}

bool Widget::OnMouseButtonPressEvent(const MouseButtonPressEvent* event) {
    assert(event != nullptr);

    return false;
}

bool Widget::OnMouseButtonReleaseEvent(const MouseButtonReleaseEvent* event) {
    assert(event != nullptr);

    return false;
}

bool Widget::OnMouseCaptureInEvent(const MouseCaptureInEvent* event) {
    assert(event != nullptr);

    return false;
}

bool Widget::OnMouseCaptureOutEvent(const MouseCaptureOutEvent* event) {
    assert(event != nullptr);

    return false;
}

bool Widget::OnMouseMoveEvent(const MouseMoveEvent* event) {
    assert(event != nullptr);

    return false;
}

bool Widget::OnMouseEnterEvent(const MouseEnterEvent* event) {
    assert(event != nullptr);

    return false;
}

bool Widget::OnMouseLeaveEvent(const MouseLeaveEvent* event) {
    assert(event != nullptr);

    return false;
}

bool Widget::OnKeyPressEvent(const KeyPressEvent* event) {
    assert(event != nullptr);

    return false;
}

bool Widget::OnKeyReleaseEvent(const KeyReleaseEvent* event) {
    assert(event != nullptr);

    return false;
}

bool Widget::OnFocusInEvent(const FocusInEvent* event) {
    assert(event != nullptr);

    return false;
}

bool Widget::OnFocusOutEvent(const FocusOutEvent* event) {
    assert(event != nullptr);

    return false;
}

bool Widget::OnCloseEvent(const CloseEvent* event) {
    assert(event != nullptr);

    if (parent_ != nullptr) {
        parent_->Detach(this);
    }
    delete this;

    return true;
}

bool Widget::OnMoveEvent(const MoveEvent* event) {
    assert(event != nullptr);

    Move(event->GetPosition());    

    return true;
}

bool Widget::OnResizeEvent(const ResizeEvent* event) {
    assert(event != nullptr);

    Resize(event->GetSize());

    return true;
}

bool Widget::OnHorizontalScrollEvent(const HorizontalScrollEvent* event) {
    assert(event != nullptr);

    return true;
}

bool Widget::OnVerticalScrollEvent(const VerticalScrollEvent* event) {
    assert(event != nullptr);

    return true;
}

bool Widget::OnShowPopUpWidgetEvent(const ShowPopUpWidgetEvent* event) {
    assert(event != nullptr);

    return true;
}

bool Widget::OnHidePopUpWidgetEvent(const HidePopUpWidgetEvent* event) {
    assert(event != nullptr);

    return true;
}

const Vector2u& Widget::GetSize() const {
    return rect_.size;
}

const Vector2i& Widget::GetPosition() const {
    return rect_.position;
}

const ContainerWidget* Widget::GetParent() const {
    return parent_;
}

void Widget::SetParent(ContainerWidget* parent) {
    parent_ = parent;
}

bool Widget::IsPressed() const {
    return pressed_;
}

bool Widget::IsHovered() const {
    return hovered_;
}

bool Widget::IsHided() const {
    return hovered_;
}

Vector2i Widget::MapPositionToParent() const {
    if (parent_ != nullptr) {
        return rect_.position - parent_->GetPosition();
    }
    return rect_.position;
}