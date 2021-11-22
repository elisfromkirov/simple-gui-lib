#ifndef __WIDGET_MANAGER_HPP__
#define __WIDGET_MANAGER_HPP__

#include <cassert>
#include <cstdint>

#include "Core/EventManager/EventDispatcher.hpp"
#include "Core/Platform/InputEvent.hpp"
#include "GUI/Event/WidgetEvent.hpp"
#include "GUI/Widgets/Widget.hpp"

class WidgetManager {
public:
    static WidgetManager* GetInstance();

    void Release();

    Widget* GetRootWidget();
    void    SetRootWidget(Widget* widget);

    void OnMouseButtonPressEvent  (const MouseButtonPressEvent*   event);
    void OnMouseButtonReleaseEvent(const MouseButtonReleaseEvent* event);
    void OnMouseMoveEvent         (const MouseMoveEvent*          event);
    void OnKeyPressEvent          (const KeyPressEvent*           event);
    void OnKeyReleaseEvent        (const KeyReleaseEvent*         event);
    void OnMouseCaptureEvent      (const MouseCaptureEvent*       event);
    void OnMouseCaptureLostEvent  (const MouseCaptureLostEvent*   event);
    void OnFocusInEvent           (const FocusInEvent*            event);
    void OnFocusOutEvent          (const FocusOutEvent*           event);
    void OnCloseEvent             (const CloseEvent*              event);
    void OnMoveEvent              (const MoveEvent*               event);
    void OnResizeEvent            (const ResizeEvent*             event);

public:
    WidgetManager();
    ~WidgetManager();

    WidgetManager(const WidgetManager& other) = delete;
    WidgetManager& operator=(const WidgetManager& other) = delete;

    static WidgetManager* singleton;

private:
    Widget* root_widget_;
    Widget* mouse_grabbing_widget_;
    Widget* focus_widget_;

    EventDispatcher<WidgetManager> event_dispatcher;
};

#endif // __WIDGET_MANAGER_HPP__