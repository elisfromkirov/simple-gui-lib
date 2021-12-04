#include "Core/ResourceManager/Resources.hpp"
#include "Core/Platform/InputEvent.hpp"
#include "Core/Platform/RenderTexture.hpp"
#include "GUI/Events/WidgetEvent.hpp"
#include "GUI/Styles/ButtonStyle.hpp"
#include "GUI/Styles/SliderStyle.hpp"
#include "GUI/Widgets/Slider.hpp"
#include "GUI/Widgets/ScrollBar.hpp"

HorizontalScrollBar::HorizontalScrollBar(uint32_t width, float step)
    : ContainerWidget{Rect2{width, kButtonSize}},
      value_{0.f},
      step_{step},
      slider_{nullptr},
      left_button_{nullptr},
      right_button_{nullptr} {
    Rect2 bounds(width - kButtonSize * 2, kButtonSize, rect_.position.x + kButtonSize, rect_.position.y);
    slider_ = new HorizontalSlider(bounds, kButtonSize);
    slider_->ApplyStyle(new HorizontalSliderStyle());
    slider_->ValueChanged.Connect<HorizontalScrollBar>(this, &HorizontalScrollBar::SliderValueChangeResponse);
    Attach(slider_);

    left_button_ = new Button(Rect2(kButtonSize, kButtonSize));
    left_button_->ApplyStyle(new ButtonStyle(kLeftArrowImage));
    left_button_->Clicked.Connect<HorizontalScrollBar>(this, &HorizontalScrollBar::LeftButtonClickResponse);
    AttachInLeft(left_button_);

    right_button_ = new Button(Rect2(kButtonSize, kButtonSize));
    right_button_->ApplyStyle(new ButtonStyle(kRightArrowImage));
    right_button_->Clicked.Connect<HorizontalScrollBar>(this, &HorizontalScrollBar::RightButtonClickResponse);
    AttachInRight(right_button_);
}

HorizontalScrollBar::~HorizontalScrollBar() {}

void HorizontalScrollBar::SetValue(float value) {
    assert(slider_ != nullptr);

    slider_->SetValue(value);
}

float HorizontalScrollBar::GetValue() const {
    assert(slider_ != nullptr);
    
    return slider_->GetValue();
}

void HorizontalScrollBar::SliderValueChangeResponse(float value) {
    value_ = value;
    
    ValueChanged(value);
}

void HorizontalScrollBar::LeftButtonClickResponse() {
    value_ -= step_;
    value_ = std::min(value_, 1.f);
    value_ = std::max(value_, 0.f);

    slider_->SetValue(value_);
}

void HorizontalScrollBar::RightButtonClickResponse() {
    value_ += step_;
    value_ = std::min(value_, 1.f);
    value_ = std::max(value_, 0.f);

    slider_->SetValue(value_);
}

VerticalScrollBar::VerticalScrollBar(uint32_t height, float step)
    : ContainerWidget{Rect2{kButtonSize, height}},
      step_{step},
      value_{0.f},
      slider_{nullptr},
      up_button_{nullptr},
      down_button_{nullptr} {
    Rect2 bounds(kButtonSize, height - kButtonSize * 2, rect_.position.x, rect_.position.y  + kButtonSize);
    slider_ = new VerticalSlider(bounds, kButtonSize);
    slider_->ApplyStyle(new VerticalSliderStyle());
    slider_->ValueChanged.Connect<VerticalScrollBar>(this, &VerticalScrollBar::SliderValueChangeResponse);
    Attach(slider_);

    up_button_ = new Button(Rect2(kButtonSize, kButtonSize));
    up_button_->ApplyStyle(new ButtonStyle(kUpArrowImage));
    up_button_->Clicked.Connect<VerticalScrollBar>(this, &VerticalScrollBar::UpButtonClickResponse);
    AttachInTop(up_button_);

    down_button_ = new Button(Rect2(kButtonSize, kButtonSize));
    down_button_->ApplyStyle(new ButtonStyle(kDownArrowImage));
    down_button_->Clicked.Connect<VerticalScrollBar>(this, &VerticalScrollBar::DownButtonClickResponse);
    AttachInBottom(down_button_);
}

VerticalScrollBar::~VerticalScrollBar() {}

void VerticalScrollBar::SetValue(float value) {
    assert(slider_ != nullptr);

    slider_->SetValue(value);
}

float VerticalScrollBar::GetValue() const {
    assert(slider_ != nullptr);
    
    return slider_->GetValue();
}


void VerticalScrollBar::SliderValueChangeResponse(float value) {
    value_ = value;

    ValueChanged(value_);
}

void VerticalScrollBar::UpButtonClickResponse() {
    value_ -= step_;
    value_ = std::min(value_, 1.f);
    value_ = std::max(value_, 0.f);

    slider_->SetValue(value_);
}

void VerticalScrollBar::DownButtonClickResponse() {
    value_ += step_;
    value_ = std::min(value_, 1.f);
    value_ = std::max(value_, 0.f);

    slider_->SetValue(value_);
}