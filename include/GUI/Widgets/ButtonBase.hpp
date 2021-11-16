#ifndef __BUTTON_HPP__
#define __BUTTON_HPP__

#include <cassert>
#include <cstdint>

#include "GUI/Signal/Signal.hpp"
#include "GUI/Widgets/Widget.hpp"

class ButtonBase : public Widget {
public:
    ButtonBase(const Vector2u& size, const Vector2i& position = Vector2i());
    virtual ~ButtonBase() override;

    virtual bool OnMouseButtonPressEvent(const MouseButtonPressEvent* event) override;

    virtual bool OnMouseButtonReleaseEvent(const MouseButtonReleaseEvent* event) override;
    
    virtual bool OnMouseMoveEvent(const MouseMoveEvent* event) override;

public:
    Signal<void> Clicked;
};

#endif // __BUTTON_BASE_HPP__