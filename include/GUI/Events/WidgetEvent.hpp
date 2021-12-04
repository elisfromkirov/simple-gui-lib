#ifndef __WIDGET_EVENT_HPP__
#define __WIDGET_EVENT_HPP__

#include <cassert>
#include <cstdint>

#include "Core/EventManager/Event.hpp"
#include "Core/Math/Vector2.hpp"

class Menu;
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

    kHorizontalScrollEvent = kWidgetEventCategory | 0x00000200,
    kVerticalScrollEvent   = kWidgetEventCategory | 0x00000400,

    kShowContextMenuEvent  = kWidgetEventCategory | 0x00000800,
    kHideContextMenuEvent  = kWidgetEventCategory | 0x00001000,
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

class ShowContextMenuEvent : public WidgetEvent {
public:
    ShowContextMenuEvent(Widget* widget, Menu* menu);
    virtual ~ShowContextMenuEvent() override;

    static uint64_t GetStaticType();
    
    Menu* GetContextMenu() const;

protected:
    Menu* menu_;
};

class HideContextMenuEvent : public WidgetEvent {
public:
    HideContextMenuEvent(Widget* widget, Menu* menu);
    virtual ~HideContextMenuEvent() override;
    
    static uint64_t GetStaticType();

    Menu* GetContextMenu() const;

protected:
    Menu* menu_;
};

#endif // __WIDGET_EVENT_HPP__