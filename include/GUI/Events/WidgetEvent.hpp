#ifndef __WIDGET_EVENT_HPP__
#define __WIDGET_EVENT_HPP__

#include <cassert>
#include <cstdint>

#include "Core/EventManager/Event.hpp"
#include "Core/Math/Vector2.hpp"

class Widget;

enum WidgetEventType : uint64_t {
    kNoneWidgetEvent       = kWidgetEventCategory | 0x00000000,

    kMouseEnterEvent       = kWidgetEventCategory | 0x00000001,
    kMouseLeaveEvent       = kWidgetEventCategory | 0x00000002,

    kMouseCaptureInEvent   = kWidgetEventCategory | 0x00000004,
    kMouseCaptureOutEvent  = kWidgetEventCategory | 0x00000008,

    kFocusInEvent          = kWidgetEventCategory | 0x00000010,
    kFocusOutEvent         = kWidgetEventCategory | 0x00000020,

    kCloseEvent            = kWidgetEventCategory | 0x00000040,

    kMoveEvent             = kWidgetEventCategory | 0x00000080,
    kResizeEvent           = kWidgetEventCategory | 0x00000100,

    kHorizontalScrollEvent = kWidgetEventCategory | 0x00000200,
    kVerticalScrollEvent   = kWidgetEventCategory | 0x00000400,

    kShowPopUpWidgetEvent  = kWidgetEventCategory | 0x00000800,
    kHidePopUpWidgetEvent  = kWidgetEventCategory | 0x00001000,
};

class WidgetEvent : public Event {
public:
    WidgetEvent(uint64_t type, Widget* widget);

    virtual ~WidgetEvent() override;

    Widget* GetWidget() const;

protected:
    Widget* widget_;
};

class MouseEnterEvent : public WidgetEvent {
public:
    MouseEnterEvent(Widget* widget, const Vector2i& postion);
    virtual ~MouseEnterEvent() override;

    static uint64_t GetStaticType();

    const Vector2i& GetMousePosition() const;

protected:
    Vector2i position_;
};

class MouseLeaveEvent : public WidgetEvent {
public:
    MouseLeaveEvent(Widget* widget, const Vector2i& position);
    virtual ~MouseLeaveEvent() override;

    static uint64_t GetStaticType();

    const Vector2i& GetMousePosition() const;

protected:
    Vector2i position_;
};

class MouseCaptureInEvent : public WidgetEvent {
public:
    MouseCaptureInEvent(Widget* widget);
    virtual ~MouseCaptureInEvent() override;

    static uint64_t GetStaticType();
};

class MouseCaptureOutEvent : public WidgetEvent {
public:
    MouseCaptureOutEvent(Widget* widget);
    virtual ~MouseCaptureOutEvent() override;

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
    MoveEvent(Widget* widget, const Vector2i& position, const Vector2i& old_position);
    virtual ~MoveEvent() override;

    static uint64_t GetStaticType();

    const Vector2i& GetPosition() const;

    const Vector2i& GetOldPosition() const;

protected:
    Vector2i position_;
    Vector2i old_position_;
};

class ResizeEvent : public WidgetEvent {
public:
    ResizeEvent(Widget* widget, const Vector2u& size, const Vector2u& old_size);
    virtual ~ResizeEvent() override;

    static uint64_t GetStaticType();

    const Vector2u& GetSize() const;

    const Vector2u& GetOldSize() const; 

protected:
    Vector2u size_;
    Vector2u old_size_;
};

class HorizontalScrollEvent : public WidgetEvent {
public:
    HorizontalScrollEvent(Widget* widget, float value, float old_value);
    virtual ~HorizontalScrollEvent() override;

    static uint64_t GetStaticType();

    float GetValue() const;

    float GetOldValue() const;

protected:
    float value_;
    float old_value_;
};

class VerticalScrollEvent : public WidgetEvent {
public:
    VerticalScrollEvent(Widget* widget, float value, float old_value);
    virtual ~VerticalScrollEvent() override;

    static uint64_t GetStaticType();

    float GetValue() const;

    float GetOldValue() const;

protected:
    float value_;
    float old_value_;
};

class ShowPopUpWidgetEvent : public WidgetEvent {
public:
    ShowPopUpWidgetEvent(Widget* widget);
    virtual ~ShowPopUpWidgetEvent() override;

    static uint64_t GetStaticType();
};

class HidePopUpWidgetEvent : public WidgetEvent {
public:
    HidePopUpWidgetEvent(Widget* widget);
    virtual ~HidePopUpWidgetEvent() override;
    
    static uint64_t GetStaticType();
};

#endif // __WIDGET_EVENT_HPP__