#ifndef __BUTTON_BASE_HPP__
#define __BUTTON_BASE_HPP__

#include <cassert>
#include <cstdint>

#include "GUI/Signal/Signal.hpp"
#include "GUI/Widgets/Widget.hpp"

class ButtonBase : public Widget {
public:
    ButtonBase(const Vector2u& size, const Vector2i& position);

    virtual ~ButtonBase() override;

    virtual bool OnMouseButtonPress(const MouseButtonPressEvent* event) override;

    virtual bool OnMouseButtonRelease(const MouseButtonReleaseEvent* event) override;

public:
    Signal<void> Pressed;
    Signal<void> Click;

protected:
    bool pressed_;
};

#endif // __BUTTON_BASE_HPP__
