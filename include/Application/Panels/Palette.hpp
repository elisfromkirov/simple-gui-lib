#ifndef __PALETTE_HPP__
#define __PALETTE_HPP__

#include <cassert>
#include <cstdint>

#include "Core/Platform/Color.hpp"
#include "Core/Signal/Signal.hpp"
#include "GUI/Widgets/ContainerWidget.hpp"
#include "GUI/Widgets/Label.hpp"
#include "GUI/Widgets/Slider.hpp"

class Palette : public ContainerWidget {
public:
    Palette();
    virtual ~Palette() override;

public:
    void SetColor(const Color& color);

    Signal<void (const Color&)> ColorChanged;

public:
    void RedSliderValueChangeResponse  (float value);
    void GreenSliderValueChangeResponse(float value);
    void BlueSliderValueChangeResponse (float value);

protected:
    Color color_;

    Label*            label_;
    HorizontalSlider* red_slider_;
    HorizontalSlider* green_slider_;
    HorizontalSlider* blue_slider_;
};

class ThicknessSlider : public ContainerWidget {
public:
    ThicknessSlider(uint32_t max_thickness);
    virtual ~ThicknessSlider() override;

public:
    void SetThickness(uint32_t thickness);

    Signal<void (uint32_t)> ThicknessChanged;

public:
    void SliderValueChangeResponse(float value);

protected:
    uint32_t thickness_;
    uint32_t max_thickness_;

    Label*            label_;
    HorizontalSlider* slider_;
};

#endif // __PALETTE_HPP__