#ifndef __WIDGET_EVENT_HPP__
#define __WIDGET_EVENT_HPP__

#include <cassert>
#include <cstdint>

#include "Core/EventManager/Event.hpp"
#include "Core/Math/Vector2.hpp"

class Widget;

enum WidgetEventType : uint64_t {
    kNoneWidgetEvent       = kWidgetEventCategory | 0x00000000,

    kMouseCaptureEvent     = kWidgetEventCategory | 0x00000001,
    kMouseCaptureLostEvent = kWidgetEventCategory | 0x00000002,

    kMouseHoverEvent       = kWidgetEventCategory | 0x00000004,
    kMouseLeaveEvent       = kWidgetEventCategory | 0x00000008,

    kFocusInEvent          = kWidgetEventCategory | 0x00000010,
    kFocusOutEvent         = kWidgetEventCategory | 0x00000020,

    kCloseEvent            = kWidgetEventCategory | 0x00000040,
    kMoveEvent             = kWidgetEventCategory | 0x00000080,
    kResizeEvent           = kWidgetEventCategory | 0x00000100,
    
    kShowEvent             = kWidgetEventCategory | 0x00000200,
    kHideEvent             = kWidgetEventCategory | 0x00000400
};

class WidgetEvent : public Event {
public:
    WidgetEvent(uint64_t type, Widget* widget);

    virtual ~WidgetEvent() override;

    Widget* GetWidget() const;

protected:
    Widget* widget_;
};

class MouseCaptureEvent : public WidgetEvent {
public:
    MouseCaptureEvent(Widget* widget);
    virtual ~MouseCaptureEvent() override;

    static uint64_t GetStaticType();
};

class MouseCaptureLostEvent : public WidgetEvent {
public:
    MouseCaptureLostEvent(Widget* widget);
    virtual ~MouseCaptureLostEvent() override;

    static uint64_t GetStaticType();
};

class FocusInEvent : public WidgetEvent {
public:
    FocusInEvent(Widget* widget);
    virtual ~FocusInEvent() override;

    static uint64_t GetStaticType();
};

class FocusOutEvent : public WidgetEvent {
public:
    FocusOutEvent(Widget* widget);
    virtual ~FocusOutEvent() override;

    static uint64_t GetStaticType();
};

class CloseEvent : public WidgetEvent {
public:
    CloseEvent(Widget* widget);
    virtual ~CloseEvent() override;

    static uint64_t GetStaticType();
};

class MoveEvent : public WidgetEvent {
public:
    MoveEvent(Widget* widget, const Vector2i& position, const Vector2i& new_position);
    virtual ~MoveEvent() override;

    static uint64_t GetStaticType();

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

    static uint64_t GetStaticType();

    const Vector2u& GetSize() const;

    const Vector2u& GetNewSize() const; 

protected:
    Vector2u size_;
    Vector2u new_size_;
};

class ShowEvent : public WidgetEvent {
    ShowEvent(Widget* widget);
    virtual ~ShowEvent() override;

    static uint64_t GetStaticType();
};

class HideEvent : public WidgetEvent {
    HideEvent(Widget* widget);
    virtual ~HideEvent() override;

    static uint64_t GetStaticType();
};

#endif // __WIDGET_EVENT_HPP__