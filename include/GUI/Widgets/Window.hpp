#ifndef __WINDOW_HPP__
#define __WINDOW_HPP__

class Window : public ContainerWindow {
public:
    Window(const Vector2u& size);
    virtual ~Window() override;

    virtual void OnEvent(const Event* event) override;

    virtual bool OnMouseButtonPressEvent(const MouseButtonPressEvent* event);
    
    virtual bool OnMouseButtonReleaseEvent(const MouseButtonReleaseEvent* event);
    
    virtual bool OnMouseMoveEvent(const MouseMoveEvent* event);
    
    virtual bool OnKeyPressEvent(const KeyPressEvent* event);
    
    virtual bool OnKeyReleaseEvent(const KeyReleaseEvent* event);
    
    virtual bool OnMouseCaptureEvent(const MouseCaptureEvent* event);
    
    virtual bool OnMouseCaptureLostEvent(const MouseCaptureLostEvent*   event);
    
    virtual bool OnFocusInEvent(const FocusInEvent* event);
    
    virtual bool OnFocusOutEvent(const FocusOutEvent* event);
    
    virtual bool OnCloseEvent(const CloseEvent* event);
    
    virtual bool OnMoveEvent(const MoveEvent* event);
    
    virtual bool OnResizeEvent(const ResizeEvent* event);

protected:
    Widget* mouse_grabbing_widget_;
    Widget* focus_widget_;    
};

#endif // __WINDOW_HPP__