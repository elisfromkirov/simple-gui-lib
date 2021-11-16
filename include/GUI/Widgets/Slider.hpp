#ifndef __SLIDER_HPP__
#define __SLIDER_HPP__

#include <cassert>
#include <cstdint>

#include "GUI/Signal/Signal.hpp"
#include "GUI/Widgets/CompositeWidget.hpp"

class Thumb : public Widget {
public:
    Thumb(const Vector2u& size, const Vector2i& position = Vector2i());
    virtual ~Thumb() override;

    virtual bool OnMouseButtonPressEvent(const MouseButtonPressEvent* event) override;

    virtual bool OnMouseButtonReleaseEvent(const MouseButtonReleaseEvent* event) override;

    virtual bool OnMouseMoveEvent(const MouseMoveEvent* event) override;

    const Rect2i& GetBounds() const;
    void SetBounds(const Rect2i& bounds);

protected:
    bool   pressed_;

    Rect2i bounds_;
};

class VerticalSlider : public CompositeWidget {
public:
    VerticalSlider(const Vector2u& size, const Vector2i& position = Vector2i());
    virtual ~VerticalSlider() override;

    virtual bool OnMouseButtonPressEvent(const MouseButtonPressEvent* event) override;

    virtual bool OnMouseButtonReleaseEvent(const MouseButtonReleaseEvent* event) override;

    virtual bool OnMouseMoveEvent(const MouseMoveEvent* event) override;

public:
    Signal<void, float> SliderMoved;

protected:
    Thumb* thumb_;

    float factor_;
};

#endif // __SLIDER_HPP__