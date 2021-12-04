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
    SetEventCallback<Widget, MouseButtonPressEvent>  (this, &Widget::OnMouseButtonPressEvent);
    SetEventCallback<Widget, MouseButtonReleaseEvent>(this, &Widget::OnMouseButtonReleaseEvent);
    SetEventCallback<Widget, MouseMoveEvent>         (this, &Widget::OnMouseMoveEvent);
    SetEventCallback<Widget, KeyPressEvent>          (this, &Widget::OnKeyPressEvent);
    SetEventCallback<Widget, KeyReleaseEvent>        (this, &Widget::OnKeyReleaseEvent);
    SetEventCallback<Widget, MouseCaptureEvent>      (this, &Widget::OnMouseCaptureEvent);
    SetEventCallback<Widget, MouseCaptureLostEvent>  (this, &Widget::OnMouseCaptureLostEvent);
    SetEventCallback<Widget, FocusInEvent>           (this, &Widget::OnFocusInEvent);
    SetEventCallback<Widget, FocusOutEvent>          (this, &Widget::OnFocusOutEvent);
    SetEventCallback<Widget, CloseEvent>             (this, &Widget::OnCloseEvent);
    SetEventCallback<Widget, MoveEvent>              (this, &Widget::OnMoveEvent);
    SetEventCallback<Widget, ResizeEvent>            (this, &Widget::OnResizeEvent);
    SetEventCallback<Widget, HorizontalScrollEvent>  (this, &Widget::OnHorizontalScrollEvent);
    SetEventCallback<Widget, VerticalScrollEvent>    (this, &Widget::OnVerticalScrollEvent);
    SetEventCallback<Widget, ShowContextMenuEvent>   (this, &Widget::OnShowContextMenuEvent);
    SetEventCallback<Widget, HideContextMenuEvent>   (this, &Widget::OnHideContextMenuEvent);
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

void Widget::OnRender(RenderTexture* texture) {
    assert(texture != nullptr);
}

bool Widget::OnMouseButtonPressEvent(const MouseButtonPressEvent* event) {
    assert(event != nullptr);

    return false;
}

bool Widget::OnMouseButtonReleaseEvent(const MouseButtonReleaseEvent* event) {
    assert(event != nullptr);

    return false;
}

bool Widget::OnMouseMoveEvent(const MouseMoveEvent* event) {
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

bool Widget::OnMouseCaptureEvent(const MouseCaptureEvent* event) {
    assert(event != nullptr);

    return false;
}

bool Widget::OnMouseCaptureLostEvent(const MouseCaptureLostEvent* event) {
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

bool Widget::OnShowContextMenuEvent(const ShowContextMenuEvent* event) {
    assert(event != nullptr);

    return true;
}

bool Widget::OnHideContextMenuEvent(const HideContextMenuEvent* event) {
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