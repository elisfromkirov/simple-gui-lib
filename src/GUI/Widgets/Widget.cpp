#include "Core/Platform/InputEvent.hpp"
#include "GUI/Events/WidgetEvent.hpp"
#include "GUI/Styles/Style.hpp"
#include "GUI/Widgets/Widget.hpp"
#include "GUI/Widgets/ContainerWidget.hpp"

Widget::Widget(const Vector2u& size, const Vector2i& position)
    : size_{size},
      position_{position},
      parent_{nullptr},
      pressed_{false},
      hovered_{false},
      hided_{false},
      styles_{} {
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
}

Widget::~Widget() {
    for (auto iter = styles_.begin(); iter != styles_.end(); ++iter) {
        delete (*iter);
    }
}

void Widget::Resize(const Vector2u& size) {
    size_ = size;
}

void Widget::Move(const Vector2i& position) {
    position_ = position;
}

bool Widget::HitTest(const Vector2i& point) const {
    Vector2i relative_position = point - position_;
 
    return 0.f < relative_position.x && relative_position.x < static_cast<int32_t>(size_.x) &&
           0.f < relative_position.y && relative_position.y < static_cast<int32_t>(size_.y);
}

void Widget::OnRender(RenderTexture* texture) {
    RenderStyles(texture);
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

bool OnKeyPressEvent(const KeyPressEvent* event) {
    assert(event != nullptr);

    return false;
}

bool OnKeyReleaseEvent(const KeyReleaseEvent* event) {
    assert(event != nullptr);

    return false;
}

bool OnMouseCaptureEvent(const MouseCaptureEvent* event) {
    assert(event != nullptr);

    return false;
}

bool OnMouseCaptureLostEvent(const MouseCaptureLostEvent* event) {
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

const Vector2u& Widget::GetSize() const {
    return size_;
}

const Vector2i& Widget::GetPosition() const {
    return position_;
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

void Widget::ApplyStyle(Style* style) {
    assert(style != nullptr);

    styles_.push_back(style);
}

Vector2i Widget::MapPositionToParent() const {
    if (parent_ != nullptr) {
        return position_ - parent_->GetPosition();
    }
    return position_;
}

void Widget::RenderStyles(RenderTexture* texture) {
    assert(texture != nullptr);

    for (auto iter = styles_.begin(); iter != styles_.end(); ++iter) {
        (*iter)->Apply(this, texture);
    }
}