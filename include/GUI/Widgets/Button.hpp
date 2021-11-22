#ifndef __BUTTON_HPP__
#define __BUTTON_HPP__

#include <cassert>
#include <cstdint>

#include "Core/Signal/Signal.hpp"
#include "GUI/Widgets/Widget.hpp"

class Button : public Widget {
public:
    Button(const Vector2u& size, const Vector2i& position = Vector2i());
    virtual ~Button() override;

    virtual bool OnMouseButtonPressEvent(const MouseButtonPressEvent* event) override;

    virtual bool OnMouseButtonReleaseEvent(const MouseButtonReleaseEvent* event) override;
  
    virtual bool OnMouseMoveEvent(const MouseMoveEvent* event) override;

public:
    Signal<void()> Clicked;
};

#endif // __BUTTON_BASE_HPP__