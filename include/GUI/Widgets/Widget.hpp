#ifndef __WIDGET_HPP__
#define __WIDGET_HPP__

#include <cassert>
#include <cstdint>
#include <list>

#include "Core/EventManager/EventDispatcher.hpp"
#include "Core/Math/Rect2.hpp"
#include "Core/Math/Vector2.hpp"
#include "Core/Platform/IRenderTarget.hpp"

class MouseButtonPressEvent;
class MouseButtonReleaseEvent;
class MouseMoveEvent;
class MouseEnterEvent;
class MouseLeaveEvent;
class KeyPressEvent;
class KeyReleaseEvent;
class MouseCaptureInEvent;
class MouseCaptureOutEvent;
class FocusInEvent;
class FocusOutEvent;
class CloseEvent;
class MoveEvent;
class ResizeEvent;
class HorizontalScrollEvent;
class VerticalScrollEvent;
class ShowPopUpWidgetEvent;
class HidePopUpWidgetEvent;
class ContainerWidget;
class RenderTexture;

class Widget : public EventDispatcher {
public:
    Widget(const Rect2& rect = Rect2());
    virtual ~Widget();

    virtual bool HitTest(const Vector2i& point) const;

    virtual void Resize(const Vector2u& size);

    virtual void Move(const Vector2i& position);
    
    virtual void OnRender(IRenderTarget* render_target);

    virtual bool OnMouseButtonPressEvent(const MouseButtonPressEvent* event);

    virtual bool OnMouseButtonReleaseEvent(const MouseButtonReleaseEvent* event);
    
    virtual bool OnMouseMoveEvent(const MouseMoveEvent* event);

    virtual bool OnMouseCaptureInEvent(const MouseCaptureInEvent* event);

    virtual bool OnMouseCaptureOutEvent(const MouseCaptureOutEvent* event);

    virtual bool OnMouseEnterEvent(const MouseEnterEvent* event);

    virtual bool OnMouseLeaveEvent(const MouseLeaveEvent* event);

    virtual bool OnKeyPressEvent(const KeyPressEvent* event);

    virtual bool OnKeyReleaseEvent(const KeyReleaseEvent* event);

    virtual bool OnFocusInEvent(const FocusInEvent* event);
    
    virtual bool OnFocusOutEvent(const FocusOutEvent* event);
    
    virtual bool OnCloseEvent(const CloseEvent* event);
    
    virtual bool OnMoveEvent(const MoveEvent* event);
    
    virtual bool OnResizeEvent(const ResizeEvent* event);

    virtual bool OnHorizontalScrollEvent(const HorizontalScrollEvent* event);

    virtual bool OnVerticalScrollEvent(const VerticalScrollEvent* event);

    virtual bool OnShowPopUpWidgetEvent(const ShowPopUpWidgetEvent* event);

    virtual bool OnHidePopUpWidgetEvent(const HidePopUpWidgetEvent* event);

    const Vector2u& GetSize() const;

    const Vector2i& GetPosition() const;

    const ContainerWidget* GetParent() const;
    void SetParent(ContainerWidget* parent);

    bool IsPressed() const;

    bool IsHovered() const;

    bool IsHided() const;

protected:
    Vector2i MapPositionToParent() const;

protected:
    Rect2             rect_;

    ContainerWidget*  parent_;

    bool              pressed_;
    bool              hovered_;
    bool              hided_;
};

#endif // __WIDGET_HPP__