#ifndef __WIDGET_HPP__
#define __WIDGET_HPP__

#include <cassert>
#include <cstdint>
#include <list>

#include "Core/EventManager/EventDispatcher.hpp"
#include "Core/Math/Vector2.hpp"
#include "Core/Platform/RenderTexture.hpp"

class MouseButtonPressEvent;
class MouseButtonReleaseEvent;
class MouseMoveEvent;
class KeyPressEvent;
class KeyReleaseEvent;
class MouseCaptureEvent;
class MouseCaptureLostEvent;
class FocusInEvent;
class FocusOutEvent;
class CloseEvent;
class MoveEvent;
class ResizeEvent;
class ShowEvent;
class HideEvent;
class ContainerWidget;
class Style;

class Widget : public EventDispatcher {
public:
    Widget(const Vector2u& size = Vector2u(), const Vector2i& position = Vector2i());
    virtual ~Widget();

    virtual bool HitTest(const Vector2i& point) const;

    virtual void Resize(const Vector2u& size);

    virtual void Move(const Vector2i& position);
    
    virtual void OnRender(RenderTexture* texture);

    virtual bool OnMouseButtonPressEvent(const MouseButtonPressEvent* event);

    virtual bool OnMouseButtonReleaseEvent(const MouseButtonReleaseEvent* event);
    
    virtual bool OnMouseMoveEvent(const MouseMoveEvent* event);

    virtual bool OnKeyPressEvent(const KeyPressEvent* event);

    virtual bool OnKeyReleaseEvent(const KeyReleaseEvent* event);

    virtual bool OnMouseCaptureEvent(const MouseCaptureEvent* event);

    virtual bool OnMouseCaptureLostEvent(const MouseCaptureLostEvent* event);
    
    virtual bool OnFocusInEvent(const FocusInEvent* event);
    
    virtual bool OnFocusOutEvent(const FocusOutEvent* event);
    
    virtual bool OnCloseEvent(const CloseEvent* event);
    
    virtual bool OnMoveEvent(const MoveEvent* event);
    
    virtual bool OnResizeEvent(const ResizeEvent* event);
    
    virtual bool OnShowEvent(const ShowEvent* event);
    
    virtual bool OnHideEvent(const HideEvent* event);

    const Vector2u& GetSize() const;

    const Vector2i& GetPosition() const;

    const ContainerWidget* GetParent() const;
    void SetParent(ContainerWidget* parent);

    bool IsPressed() const;

    bool IsHovered() const;

    bool IsHided() const;

    void ApplyStyle(Style* style);

protected:
    Vector2i MapPositionToParent() const; 

    void RenderStyles(RenderTexture* texture);

protected:
    Vector2u          size_;
    Vector2i          position_;

    ContainerWidget*  parent_;

    bool              pressed_;
    bool              hovered_;
    bool              hided_;

    std::list<Style*> styles_;
};

#endif // __WIDGET_HPP__