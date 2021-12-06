#include "GUI/Events/WidgetEvent.hpp"
#include "GUI/Widgets/MenuBar.hpp"
#include "GUI/Widgets/Widget.hpp"

WidgetEvent::WidgetEvent(uint64_t type, Widget* widget)
    : Event{type},
      widget_{widget} {}

WidgetEvent::~WidgetEvent() {}

Widget* WidgetEvent::GetWidget() const {
    return widget_;
}

MouseEnterEvent::MouseEnterEvent(Widget* widget, const Vector2i& position)
    : WidgetEvent{kMouseEnterEvent, widget},
      position_{position} {}
    
MouseEnterEvent::~MouseEnterEvent() {}

uint64_t MouseEnterEvent::GetStaticType() {
    return kMouseEnterEvent;
}

const Vector2i& MouseEnterEvent::GetMousePosition() const {
    return position_;
}

MouseLeaveEvent::MouseLeaveEvent(Widget* widget, const Vector2i& position)
    : WidgetEvent{kMouseLeaveEvent, widget},
      position_{position} {}

MouseLeaveEvent::~MouseLeaveEvent() {}

uint64_t MouseLeaveEvent::GetStaticType() {
    return kMouseLeaveEvent;
}

const Vector2i& MouseLeaveEvent::GetMousePosition() const {
    return position_;
}

MouseCaptureInEvent::MouseCaptureInEvent(Widget* widget)
    : WidgetEvent{kMouseCaptureInEvent, widget} {}

MouseCaptureInEvent::~MouseCaptureInEvent() {}

uint64_t MouseCaptureInEvent::GetStaticType() {
    return kMouseCaptureInEvent;
}

MouseCaptureOutEvent::MouseCaptureOutEvent(Widget* widget)
    : WidgetEvent{kMouseCaptureOutEvent, widget} {}

MouseCaptureOutEvent::~MouseCaptureOutEvent() {}

uint64_t MouseCaptureOutEvent::GetStaticType() {
    return kMouseCaptureOutEvent;
}

FocusInEvent::FocusInEvent(Widget* widget)
    : WidgetEvent{kFocusInEvent, widget} {}

FocusInEvent::~FocusInEvent() {}

uint64_t FocusInEvent::GetStaticType() {
    return kFocusInEvent;
}

FocusOutEvent::FocusOutEvent(Widget* widget)
    : WidgetEvent{kFocusOutEvent, widget} {}

FocusOutEvent::~FocusOutEvent() {}

uint64_t FocusOutEvent::GetStaticType() {
    return kFocusOutEvent;
}

CloseEvent::CloseEvent(Widget* widget)
    : WidgetEvent{kCloseEvent, widget} {}

CloseEvent::~CloseEvent() {}

uint64_t CloseEvent::GetStaticType() {
    return kCloseEvent;
}

MoveEvent::MoveEvent(Widget* widget, const Vector2i& position, const Vector2i& old_position)
    : WidgetEvent{kMoveEvent, widget},
      position_{position},
      old_position_{old_position} {}

MoveEvent::~MoveEvent() {}

uint64_t MoveEvent::GetStaticType() {
    return kMoveEvent;
}

const Vector2i& MoveEvent::GetPosition() const {
    return position_;
}

const Vector2i& MoveEvent::GetOldPosition() const {
    return old_position_;
}

ResizeEvent::ResizeEvent(Widget* widget, const Vector2u& size, const Vector2u& old_size)
    : WidgetEvent{kResizeEvent, widget},
      size_{size},
      old_size_{old_size} {}

ResizeEvent::~ResizeEvent() {}

uint64_t ResizeEvent::GetStaticType() {
    return kResizeEvent;
}

const Vector2u& ResizeEvent::GetSize() const {
    return size_;
}

const Vector2u& ResizeEvent::GetOldSize() const {
    return old_size_;
}

HorizontalScrollEvent::HorizontalScrollEvent(Widget* widget, float value, float old_value)
    : WidgetEvent{kHorizontalScrollEvent, widget},
      value_{value},
      old_value_{old_value} {}

HorizontalScrollEvent::~HorizontalScrollEvent() {}

uint64_t HorizontalScrollEvent::GetStaticType() {
    return kHorizontalScrollEvent;
}

float HorizontalScrollEvent::GetValue() const {
    return value_;
}

float HorizontalScrollEvent::GetOldValue() const {
    return old_value_;
}

VerticalScrollEvent::VerticalScrollEvent(Widget* widget, float value, float old_value)
    : WidgetEvent{kVerticalScrollEvent, widget},
      value_{value},
      old_value_{old_value} {}

VerticalScrollEvent::~VerticalScrollEvent() {}

uint64_t VerticalScrollEvent::GetStaticType() {
    return kVerticalScrollEvent;
}

float VerticalScrollEvent::GetValue() const {
    return value_;
}

float VerticalScrollEvent::GetOldValue() const {
    return old_value_;
}

ShowPopUpWidgetEvent::ShowPopUpWidgetEvent(Widget* widget)
    : WidgetEvent{kShowPopUpWidgetEvent, widget} {}

ShowPopUpWidgetEvent::~ShowPopUpWidgetEvent() {}

uint64_t ShowPopUpWidgetEvent::GetStaticType() {
    return kShowPopUpWidgetEvent;
}

HidePopUpWidgetEvent::HidePopUpWidgetEvent(Widget* widget)
    : WidgetEvent{kHidePopUpWidgetEvent, widget} {}

HidePopUpWidgetEvent::~HidePopUpWidgetEvent() {}

uint64_t HidePopUpWidgetEvent::GetStaticType() {
    return kHidePopUpWidgetEvent;
}