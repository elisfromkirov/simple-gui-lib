#include "Application/Panels/Palette.hpp"
#include "Application/Panels/ToolPanel.hpp"
#include "Core/ResourceManager/Resources.hpp"
#include "Core/ResourceManager/ResourceManager.hpp"
#include "GUI/Styles/FilledStyle.hpp"
#include "GUI/Styles/SliderStyle.hpp"

Palette::Palette()
    : ContainerWidget{Rect2{ToolPanel::kSliderWidth, ToolPanel::kIndent * 5 + ToolPanel::kSliderHeight * 4}},
      color_{0.f, 0.f, 0.f, 1.f},
      label_{nullptr},
      red_slider_{nullptr},
      green_slider_{nullptr},
      blue_slider_{nullptr} {
    label_ = new Label("Color", ResourceManager::GetInstance()->LoadFont(kMediumFont)); 
    label_->Move(Vector2i(ToolPanel::kIndent, ToolPanel::kIndent));
    label_->SetTextColor(Color(0.f, 0.f, 0.f, 1.f));
    Attach(label_);

    Rect2    slider_rect{ToolPanel::kSliderWidth - 2 * ToolPanel::kIndent, ToolPanel::kSliderHeight};
    uint32_t thumb_width{ToolPanel::kSliderHeight / 3};

    slider_rect.position.x = ToolPanel::kIndent;
    slider_rect.position.y = ToolPanel::kIndent * 2 + ToolPanel::kSliderHeight;

    red_slider_ = new HorizontalSlider(slider_rect, thumb_width);
    red_slider_->ApplyStyle(new ChoseColorHorizontalSliderStyle(Color(1.f, 0.f, 0.f, 1.f)));
    red_slider_->ValueChanged.Connect<Palette>(this, &Palette::RedSliderValueChangeResponse);

    slider_rect.position.x = ToolPanel::kIndent;
    slider_rect.position.y = ToolPanel::kIndent * 3 + ToolPanel::kSliderHeight * 2;

    green_slider_ = new HorizontalSlider(slider_rect, thumb_width);
    green_slider_->ApplyStyle(new ChoseColorHorizontalSliderStyle(Color(0.f, 1.f, 0.f, 1.f)));
    green_slider_->ValueChanged.Connect<Palette>(this, &Palette::GreenSliderValueChangeResponse);

    slider_rect.position.x = ToolPanel::kIndent;
    slider_rect.position.y = ToolPanel::kIndent * 4 + ToolPanel::kSliderHeight * 3;

    blue_slider_ = new HorizontalSlider(slider_rect, thumb_width);
    blue_slider_->ApplyStyle(new ChoseColorHorizontalSliderStyle(Color(0.f, 0.f, 1.f, 1.f)));
    blue_slider_->ValueChanged.Connect<Palette>(this, &Palette::BlueSliderValueChangeResponse);

    Attach(red_slider_);
    Attach(green_slider_);
    Attach(blue_slider_);
}

Palette::~Palette() {}

void Palette::SetColor(const Color& color) {
    color_ = color;

    red_slider_->SetValue(color_.red);
    green_slider_->SetValue(color_.green);
    blue_slider_->SetValue(color_.blue);
}

void Palette::RedSliderValueChangeResponse(float value) {
    color_.red = value;
    ColorChanged(color_);
}

void Palette::GreenSliderValueChangeResponse(float value) {
    color_.green = value;
    ColorChanged(color_);
}

void Palette::BlueSliderValueChangeResponse(float value) {
    color_.blue = value;
    ColorChanged(color_);
}

ThicknessSlider::ThicknessSlider(uint32_t max_thickness) 
    : ContainerWidget{Rect2{ToolPanel::kSliderWidth, ToolPanel::kIndent * 3 + ToolPanel::kSliderHeight * 2}},
      thickness_{0},
      max_thickness_{max_thickness},
      slider_{nullptr} {
    label_ = new Label("Thickness", ResourceManager::GetInstance()->LoadFont(kMediumFont)); 
    label_->Move(Vector2i(ToolPanel::kIndent, ToolPanel::kIndent));
    label_->SetTextColor(Color(0.f, 0.f, 0.f, 1.f));
    Attach(label_);

    Rect2    slider_rect{ToolPanel::kSliderWidth - 2 * ToolPanel::kIndent, ToolPanel::kSliderHeight};
    uint32_t thumb_width{ToolPanel::kSliderHeight / 3};

    slider_rect.position.x = ToolPanel::kIndent;
    slider_rect.position.y = ToolPanel::kIndent * 2 + ToolPanel::kSliderHeight;

    slider_ = new HorizontalSlider(slider_rect, thumb_width);
    slider_->ApplyStyle(new ProgressHorizontalSliderStyle());
    slider_->ValueChanged.Connect<ThicknessSlider>(this, &ThicknessSlider::SliderValueChangeResponse);
    Attach(slider_);
}

ThicknessSlider::~ThicknessSlider() {}

void ThicknessSlider::SetThickness(uint32_t thickness) {
    thickness_ = std::min(thickness, max_thickness_);
    slider_->SetValue(static_cast<float>(thickness_) / static_cast<float>(max_thickness_));
}

void ThicknessSlider::SliderValueChangeResponse(float value) {
    thickness_ = static_cast<uint32_t>(value * max_thickness_);
    ThicknessChanged(thickness_);
}