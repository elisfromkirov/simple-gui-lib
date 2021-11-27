#ifndef __WIDGET_HPP__
#define __WIDGET_HPP__

#include <cassert>
#include <cstdint>
#include <list>

class MouseButtonPressEvent;
class MouseButtonReleaseEvent;
class MouseMoveEvent;
class FocusInEvent;
class FocusOutEvent;
class CloseEvent;
class MoveEvent;
class ResizeEvent;
class ShowEvent;
class HideEvent;
class Style;
class ContainerWidget;

#include "Core/EventManager/EventDispatcher.hpp"
#include "Core/Math/Vector2.hpp"
#include "Core/Platform/RenderTexture.hpp"

class Widget : public EventDispatcher {
public:
    Widget(const Vector2u& size, const Vector2i& position = Vector2i());
    virtual ~Widget();

    virtual bool HitTest(const Vector2i& point) const;

    virtual void Resize(const Vector2u& size);

    virtual void Move(const Vector2i& position);
    
    virtual void OnRender();

    virtual bool OnMouseButtonPressEvent(const MouseButtonPressEvent* event);

    virtual bool OnMouseButtonReleaseEvent(const MouseButtonReleaseEvent* event);
    
    virtual bool OnMouseMoveEvent(const MouseMoveEvent* event);
    
    virtual bool OnFocusInEvent(const FocusInEvent* event);
    
    virtual bool OnFocusOutEvent(const FocusOutEvent* event);
    
    virtual bool OnCloseEvent(const CloseEvent* event);
    
    virtual bool OnMoveEvent(const MoveEvent* event);
    
    virtual bool OnResizeEvent(const ResizeEvent* event);
    
    virtual bool OnShowEvent(const ShowEvent* event);
    
    virtual bool OnHideEvent(const HideEvent* event);

    const Vector2u& GetSize() const;

    const Vector2i& GetPosition() const;

    const CompositeWidget* GetParent() const;
    void SetParent(CompositeWidget* parent);

    bool IsPressed() const;

    bool IsHovered() const;

    bool IsHided() const;

    void ApplyStyle(Style* style);

protected:
    Vector2i MapPositionToParent() const; 
    
    void ApplyStyles();

protected:
    Vector2u          size_;
    Vector2i          position_;

    CompositeWidget*  parent_;

    bool pressed_;
    bool hovered_;
    bool hided_;

    RenderTexture     texture_;
    std::list<Style*> styles_;
};

#endif // __WIDGET_HPP__