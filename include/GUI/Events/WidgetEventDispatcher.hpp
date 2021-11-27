#ifndef __WIDGET_EVENT_DISPATCHER_HPP__
#define __WIDGET_EVENT_DISPATCHER_HPP__

class WidgetEventDispatcher : public EventDispatcher {
public:
    WidgetEventDispatcher(Widget* root_widget);

    virtual ~WidgetEventDispatcher() override;    

    void OnMouseButtonPressEvent(const MouseButtonPressEvent* event);

    void OnMouseButtonReleaseEvent(const MouseButtonReleaseEvent* event);

    void OnMouseMoveEvent(const MouseMoveEvent* event);

    void OnKeyPressEvent(const KeyPressEvent* event);

    void OnKeyReleaseEvent(const KeyReleaseEvent* event);

    void OnMouseCaptureEvent(const MouseCaptureEvent* event);

    void OnMouseCaptureLostEvent(const MouseCaptureLostEvent*   event);

    void OnFocusInEvent(const FocusInEvent* event);

    void OnFocusOutEvent(const FocusOutEvent* event);

    void OnCloseEvent(const CloseEvent* event);

    void OnMoveEvent(const MoveEvent* event);

    void OnResizeEvent(const ResizeEvent* event);

    void OnShowEvent(const ShowEvent* event);

    void OnHideEvent(const HideEvent* event);

protected:
    Widget* root_widget_;
    Widget* mouse_grabbing_widget_;
    Widget* focus_widget_;
};

#endif // __WIDGET_EVENT_DISPATCHER_HPP__