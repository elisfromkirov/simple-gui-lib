#include "GUI/Events/WidgetEvent.hpp"
#include "GUI/Widgets/Widget.hpp"

WidgetEvent::WidgetEvent(uint64_t type, Widget* widget)
    : Event{type},
      widget_{widget} {}

WidgetEvent::~WidgetEvent() {}

Widget* WidgetEvent::GetWidget() const {
    return widget_;
}

MouseCaptureEvent::MouseCaptureEvent(Widget* widget)
    : WidgetEvent{kMouseCaptureEvent, widget} {}

MouseCaptureEvent::~MouseCaptureEvent() {}

uint64_t MouseCaptureEvent::GetStaticType() {
    return kMouseCaptureEvent;
}

MouseCaptureLostEvent::MouseCaptureLostEvent(Widget* widget)
    : WidgetEvent{kMouseCaptureLostEvent, widget} {}

MouseCaptureLostEvent::~MouseCaptureLostEvent() {}

uint64_t MouseCaptureLostEvent::GetStaticType() {
    return kMouseCaptureLostEvent;
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

ShowEvent::ShowEvent(Widget* widget)
    : WidgetEvent{kShowEvent, widget} {}

ShowEvent::~ShowEvent() {}

uint64_t ShowEvent::GetStaticType() {
    return kShowEvent;
}

HideEvent::HideEvent(Widget* widget)
    : WidgetEvent{kHideEvent, widget} {}

HideEvent::~HideEvent() {}

uint64_t HideEvent::GetStaticType() {
    return kHideEvent;
}
