#ifndef __SCROLL_BAR_HPP__
#define __SCROLL_BAR_HPP__

#include <cassert>
#include <cstdint>

#include "Core/Signal/Signal.hpp"
#include "GUI/Widgets/Button.hpp"
#include "GUI/Widgets/ContainerWidget.hpp"
#include "GUI/Widgets/Slider.hpp"

class HorizontalScrollBar : public ContainerWidget {
public:
    HorizontalScrollBar(uint32_t width, float step);
    virtual ~HorizontalScrollBar() override;

    void SetValue(float value);
    float GetValue() const;

public:
    Signal<void (float)> ValueChanged;

public:
    void SliderValueChangeResponse(float value);
    void LeftButtonClickResponse();
    void RightButtonClickResponse();

protected:
    float             value_;
    float             step_;

    HorizontalSlider* slider_;
    Button*           left_button_;
    Button*           right_button_;
};

class VerticalScrollBar : public ContainerWidget {
public:
    VerticalScrollBar(uint32_t height, float step);
    virtual ~VerticalScrollBar() override;

    void SetValue(float value);
    float GetValue() const;

public:
    Signal<void (float)> ValueChanged;

public:
    void SliderValueChangeResponse(float value);
    void UpButtonClickResponse();
    void DownButtonClickResponse();

protected:
    float   step_;
    float   value_;

    VerticalSlider* slider_;
    Button*         up_button_;
    Button*         down_button_;
};

#endif // __SCROLL_BAR_HPP__