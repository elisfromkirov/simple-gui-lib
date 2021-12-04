#ifndef __WINDOW_HPP__
#define __WINDOW_HPP__

#include <cassert>
#include <cstdint>

#include "Core/Platform/RenderWindow.hpp"
#include "GUI/Widgets/ContainerWidget.hpp"
#include "GUI/Widgets/MenuBar.hpp"
#include "GUI/Widgets/Widget.hpp"

class Window : public ContainerWidget {
public:
    Window(const Vector2u& size);
    virtual ~Window() override;

    void OnRenderToWindow(RenderWindow* window);

    virtual bool OnEvent(const Event* event) override;

    virtual bool OnMouseButtonPressEvent(const MouseButtonPressEvent* event) override;
    
    virtual bool OnMouseButtonReleaseEvent(const MouseButtonReleaseEvent* event) override;
    
    virtual bool OnMouseMoveEvent(const MouseMoveEvent* event) override;
    
    virtual bool OnKeyPressEvent(const KeyPressEvent* event) override;
    
    virtual bool OnKeyReleaseEvent(const KeyReleaseEvent* event) override;
    
    virtual bool OnMouseCaptureEvent(const MouseCaptureEvent* event) override;
    
    virtual bool OnMouseCaptureLostEvent(const MouseCaptureLostEvent* event) override;
    
    virtual bool OnFocusInEvent(const FocusInEvent* event) override;
    
    virtual bool OnFocusOutEvent(const FocusOutEvent* event) override;
    
    virtual bool OnCloseEvent(const CloseEvent* event) override;
    
    virtual bool OnMoveEvent(const MoveEvent* event) override;
    
    virtual bool OnResizeEvent(const ResizeEvent* event) override;

    virtual bool OnHorizontalScrollEvent(const HorizontalScrollEvent* event) override;

    virtual bool OnVerticalScrollEvent(const VerticalScrollEvent* event) override;

    virtual bool OnShowContextMenuEvent(const ShowContextMenuEvent* event) override;

    virtual bool OnHideContextMenuEvent(const HideContextMenuEvent* event) override;

protected:
    Widget* mouse_grabbing_widget_;

    Widget* focus_widget_;

    Menu*   context_menu_;
};

#endif // __WINDOW_HPP__