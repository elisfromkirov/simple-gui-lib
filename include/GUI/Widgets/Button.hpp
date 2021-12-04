#ifndef __BUTTON_HPP__
#define __BUTTON_HPP__

#include <cassert>
#include <cstdint>

#include "Core/Signal/Signal.hpp"
#include "GUI/Widgets/ContainerWidget.hpp"

class Button : public ContainerWidget {
public:
    Button(const Rect2& rect);
    virtual ~Button() override;

    virtual bool OnMouseButtonPressEvent(const MouseButtonPressEvent* event) override;

    virtual bool OnMouseButtonReleaseEvent(const MouseButtonReleaseEvent* event) override;
  
    virtual bool OnMouseMoveEvent(const MouseMoveEvent* event) override;

public:
    Signal<void()> Clicked;
};

#endif // __BUTTON_BASE_HPP__