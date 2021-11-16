#ifndef __WIDGET_EVENT_HPP__
#define __WIDGET_EVENT_HPP__

#include <cassert>
#include <cstdint>

#include "Core/EventManager/Event.hpp"
#include "Core/Math/Vector2.hpp"

class Widget;

enum WidgetEventType : uint64_t {
    kNoneWidgetEvent     = kWidgetEventCategory | 0x00000000,

    kMouseCaptureRequest = kWidgetEventCategory | 0x00000001,
    kMouseCaptureLost    = kWidgetEventCategory | 0x00000002,

    kMouseHover          = kWidgetEventCategory | 0x00000004,
    kMouseLeave          = kWidgetEventCategory | 0x00000008,

    kFocusIn             = kWidgetEventCategory | 0x00000010,
    kFocusOut            = kWidgetEventCategory | 0x00000020,

    kClose               = kWidgetEventCategory | 0x00000040,
    kMove                = kWidgetEventCategory | 0x00000080,
    kResize              = kWidgetEventCategory | 0x00000100,
    
    kShow                = kWidgetEventCategory | 0x00000200,
    kHide                = kWidgetEventCategory | 0x00000400
};

class WidgetEvent : public Event {
public:
    WidgetEvent(uint64_t type, Widget* widget);

    virtual ~WidgetEvent() override;

    Widget* GetWidget() const;

protected:
    Widget* widget_;
};

class MouseCaptureRequestEvent : public WidgetEvent {
public:
    MouseCaptureRequestEvent(Widget* widget);
    virtual ~MouseCaptureRequestEvent() override;
};

class MouseCaptureLostEvent : public WidgetEvent {
public:
    MouseCaptureLostEvent(Widget* widget);
    virtual ~MouseCaptureLostEvent() override;
};

class FocusInEvent : public WidgetEvent {
public:
    FocusInEvent(Widget* widget);
    virtual ~FocusInEvent() override;
};

class FocusOutEvent : public WidgetEvent {
public:
    FocusOutEvent(Widget* widget);
    virtual ~FocusOutEvent() override;
};

class CloseEvent : public WidgetEvent {
public:
    CloseEvent(Widget* widget);
    virtual ~CloseEvent() override;
};

class MoveEvent : public WidgetEvent {
public:
    MoveEvent(Widget* widget, const Vector2i& position, const Vector2i& new_position);
    virtual ~MoveEvent() override;

    const Vector2i& GetPosition() const;

    const Vector2i& GetNewPosition() const;

protected:
    Vector2i position_;
    Vector2i new_position_;
};

class ResizeEvent : public WidgetEvent {
public:
    ResizeEvent(Widget* widget, const Vector2u& size, const Vector2u& new_size);
    virtual ~ResizeEvent() override;

    const Vector2u& GetSize() const;

    const Vector2u& GetNewSize() const; 

protected:
    Vector2u size_;
    Vector2u new_size_;
};

#endif // __WIDGET_EVENT_HPP__