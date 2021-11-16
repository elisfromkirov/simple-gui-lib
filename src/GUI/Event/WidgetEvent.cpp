#include "GUI/Event/WidgetEvent.hpp"
#include "GUI/Widgets/Widget.hpp"

WidgetEvent::WidgetEvent(uint64_t type, Widget* widget)
    : Event{type},
      widget_{widget} {}

WidgetEvent::~WidgetEvent() {}

Widget* WidgetEvent::GetWidget() const {
    return widget_;
}

MouseCaptureRequestEvent::MouseCaptureRequestEvent(Widget* widget)
    : WidgetEvent{kMouseCaptureRequest, widget} {}

MouseCaptureRequestEvent::~MouseCaptureRequestEvent() {}

MouseCaptureLostEvent::MouseCaptureLostEvent(Widget* widget)
    : WidgetEvent{kMouseCaptureLost, widget} {}

MouseCaptureLostEvent::~MouseCaptureLostEvent() {}

FocusInEvent::FocusInEvent(Widget* widget)
    : WidgetEvent{kFocusIn, widget} {}

FocusInEvent::~FocusInEvent() {}

FocusOutEvent::FocusOutEvent(Widget* widget)
    : WidgetEvent{kFocusOut, widget} {}

FocusOutEvent::~FocusOutEvent() {}

CloseEvent::CloseEvent(Widget* widget)
    : WidgetEvent{kClose, widget} {}

CloseEvent::~CloseEvent() {}

MoveEvent::MoveEvent(Widget* widget, const Vector2i& position, const Vector2i& new_position)
    : WidgetEvent{kMove, widget},
      position_{position},
      new_position_{new_position} {}

MoveEvent::~MoveEvent() {}

const Vector2i& MoveEvent::GetPosition() const {
    return position_;
}

const Vector2i& MoveEvent::GetNewPosition() const {
    return new_position_;
}

ResizeEvent::ResizeEvent(Widget* widget, const Vector2u& size, const Vector2u& new_size)
    : WidgetEvent{kResize, widget},
      size_{size},
      new_size_{new_size} {}

ResizeEvent::~ResizeEvent() {}

const Vector2u& ResizeEvent::GetSize() const {
    return size_;
}

const Vector2u& ResizeEvent::GetNewSize() const {
    return new_size_;
}
