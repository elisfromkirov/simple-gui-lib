#ifndef __SLIDER_HPP__
#define __SLIDER_HPP__

#include <cassert>
#include <cstdint>

#include "Core/Signal/Signal.hpp"
#include "GUI/Widgets/ContainerWidget.hpp"

class Thumb : public Widget {
public:
    Thumb(const Vector2u& size, const Rect2& bounds);
    virtual ~Thumb() override;

    virtual void Resize(const Vector2u& size) override;

    virtual void Move(const Vector2i& position) override;

    virtual bool OnMouseButtonPressEvent(const MouseButtonPressEvent* event) override;

    virtual bool OnMouseButtonReleaseEvent(const MouseButtonReleaseEvent* event) override;

    virtual bool OnMouseMoveEvent(const MouseMoveEvent* event) override;

    void SetBounds(const Rect2& bounds);
    const Rect2& GetBounds() const;

    void SetValue(const Vector2f& value);
    const Vector2f& GetValue() const;
    
public:
    Signal<void (const Vector2f&)> ValueChanged;

protected:
    void UpdateValue();

protected:
    Rect2    bounds_;

    Vector2f value_;
};

class HorizontalSlider : public ContainerWidget {
public:
    HorizontalSlider(const Rect2& rect, uint32_t thumb_width);
    virtual ~HorizontalSlider() override;

    virtual void Move(const Vector2i& position) override;
    
    virtual void Resize(const Vector2u& size) override;

    uint32_t GetThumbWidth() const;
    void SetThumbWidth(uint32_t width);

    float GetValue();
    void SetValue(float value);

public:
    Signal<void (float)> ValueChanged;

public:
    void ValueChangeResponse(const Vector2f& value);

protected:    
    Thumb* thumb_;
};

class VerticalSlider : public ContainerWidget {
public:
    VerticalSlider(const Rect2& rect, uint32_t thumb_height);
    virtual ~VerticalSlider() override;

    virtual void Move(const Vector2i& position) override;

    virtual void Resize(const Vector2u& size) override;

    uint32_t GetThumbHeight() const;
    void SetThumbHeight(uint32_t height);

    float GetValue();
    void SetValue(float value);

public:
    Signal<void (float)> ValueChanged;

public:
    void ValueChangeResponse(const Vector2f& value);

protected:
    Thumb* thumb_;
};

#endif // __SLIDER_HPP__