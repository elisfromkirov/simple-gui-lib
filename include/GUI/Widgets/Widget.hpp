#ifndef __WIDGET_HPP__
#define __WIDGET_HPP__

#include <cassert>
#include <cstdint>
#include <list>

#include "Core/EventManager/IEventListener.hpp"
#include "Core/Math/Rect2.hpp"
#include "Core/Math/Vector2.hpp"
#include "Core/Platform/InputEvent.hpp"
#include "Core/Platform/Renderer.hpp"
#include "GUI/Event/WidgetEvent.hpp"
#include "GUI/Style/IStyle.hpp"

class CompositeWidget;

class Widget : public IEventListener {
public:
    enum State : uint32_t {
        kNone     = 0x0000,
        kReleased = 0x0001,
        kPressed  = 0x0002,
        kHovered  = 0x0004        
    };

public:
    Widget(const Vector2u& size = Vector2u(), const Vector2i& position = Vector2i());
    virtual ~Widget();

    virtual void OnRender(Renderer* renderer);

    virtual void Resize(const Vector2u& size);

    virtual void Move(const Vector2i& position);

    virtual bool HitTest(const Vector2i& point) const;

    virtual void OnEvent(const Event* event) override;

    virtual bool OnMouseButtonPressEvent(const MouseButtonPressEvent* event);

    virtual bool OnMouseButtonReleaseEvent(const MouseButtonReleaseEvent* event);

    virtual bool OnMouseMoveEvent(const MouseMoveEvent* event);

    virtual bool OnFocusInEvent(const FocusInEvent* event);

    virtual bool OnFocusOutEvent(const FocusOutEvent* event);

    virtual bool OnCloseEvent(const CloseEvent* event);

    virtual bool OnMoveEvent(const MoveEvent* event);

    virtual bool OnResizeEvent(const ResizeEvent* event);

    const Vector2u& GetSize() const;
    
    const Vector2i& GetPosition() const;

    const CompositeWidget* GetParent() const;
    void SetParent(CompositeWidget* parent);
    
    State GetState() const;

    void ApplyStyle(IStyle* style);

protected:
    void ApplyStyles(Renderer* renderer);

protected:
    Vector2u           size_;
    Vector2i           position_;

    CompositeWidget*   parent_;

    State              state_;

    std::list<IStyle*> styles_;
};

#endif // __WIDGET_HPP__