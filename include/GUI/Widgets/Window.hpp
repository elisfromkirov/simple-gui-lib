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

    virtual bool OnEvent(const Event* event) override;

    virtual bool OnMouseButtonPressEvent(const MouseButtonPressEvent* event) override;
    
    virtual bool OnMouseButtonReleaseEvent(const MouseButtonReleaseEvent* event) override;
    
    virtual bool OnMouseMoveEvent(const MouseMoveEvent* event) override;

    virtual bool OnMouseCaptureInEvent(const MouseCaptureInEvent* event) override;
    
    virtual bool OnMouseCaptureOutEvent(const MouseCaptureOutEvent* event) override;

    virtual bool OnMouseEnterEvent(const MouseEnterEvent* event) override;

    virtual bool OnMouseLeaveEvent(const MouseLeaveEvent* event) override;

    virtual bool OnKeyPressEvent(const KeyPressEvent* event) override;
    
    virtual bool OnKeyReleaseEvent(const KeyReleaseEvent* event) override;    
    
    virtual bool OnFocusInEvent(const FocusInEvent* event) override;
    
    virtual bool OnFocusOutEvent(const FocusOutEvent* event) override;
    
    virtual bool OnCloseEvent(const CloseEvent* event) override;
    
    virtual bool OnMoveEvent(const MoveEvent* event) override;
    
    virtual bool OnResizeEvent(const ResizeEvent* event) override;

    virtual bool OnHorizontalScrollEvent(const HorizontalScrollEvent* event) override;

    virtual bool OnVerticalScrollEvent(const VerticalScrollEvent* event) override;

    virtual bool OnShowPopUpWidgetEvent(const ShowPopUpWidgetEvent* event) override;

    virtual bool OnHidePopUpWidgetEvent(const HidePopUpWidgetEvent* event) override;

protected:
    Widget* mouse_grabbing_widget_;

    Widget* focus_widget_;
};

#endif // __WINDOW_HPP__