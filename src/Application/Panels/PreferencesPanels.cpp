#include "Application/Panels/MainPanel.hpp"
#include "Application/Panels/PreferencesPanels.hpp"
#include "GUI/Styles/FilledStyle.hpp"
#include "GUI/Styles/SliderStyle.hpp"

PencilPreferencesPanel::PencilPreferencesPanel(Pencil* pencil)
    : ContainerWidget{Rect2(kWidth, kSliderWidth * 4 + kIndent * 5)},
      pencil_{pencil},
      thickness_slider_{nullptr},
      red_slider_{nullptr},
      green_slider_{nullptr},
      blue_slider_{nullptr} {
    thickness_slider_ = new HorizontalSlider(Rect2(kWidth - 2 * kIndent, kSliderWidth, 
                                                   kIndent, kIndent),
                                             kSliderWidth / 3);
    thickness_slider_->ApplyStyle(new ProgressHorizontalSliderStyle());
    thickness_slider_->ValueChanged.Connect<PencilPreferencesPanel>(this, &PencilPreferencesPanel::UpdateThickness);
    Attach(thickness_slider_);

    red_slider_ = new HorizontalSlider(Rect2(kWidth - 2 * kIndent, kSliderWidth, 
                                             kIndent, kSliderWidth + 2 * kIndent),
                                       kSliderWidth / 3);
    red_slider_->ApplyStyle(new ProgressHorizontalSliderStyle());
    red_slider_->ValueChanged.Connect<PencilPreferencesPanel>(this, &PencilPreferencesPanel::UpdateRedColor);
    Attach(red_slider_);

    green_slider_ = new HorizontalSlider(Rect2(kWidth - 2 * kIndent, kSliderWidth,
                                               kIndent, 2 * kSliderWidth + 3 * kIndent),
                                        kSliderWidth / 3);
    green_slider_->ApplyStyle(new ProgressHorizontalSliderStyle());
    green_slider_->ValueChanged.Connect<PencilPreferencesPanel>(this, &PencilPreferencesPanel::UpdateGreenColor);
    Attach(green_slider_);

    blue_slider_ = new HorizontalSlider(Rect2(kWidth - 2 * kIndent, kSliderWidth,
                                              kIndent, 3 * kSliderWidth + 4 * kIndent),
                                        kSliderWidth / 3);
    blue_slider_->ApplyStyle(new ProgressHorizontalSliderStyle());
    blue_slider_->ValueChanged.Connect<PencilPreferencesPanel>(this, &PencilPreferencesPanel::UpdateBlueColor);
    Attach(blue_slider_);

    ApplyStyle(new FilledStyle(FilledStyle::kLightPanel));
}

PencilPreferencesPanel::~PencilPreferencesPanel() {}

void PencilPreferencesPanel::UpdateThickness(float value) {
    pencil_->SetThickness(static_cast<uint32_t>(value * static_cast<float>(pencil_->GetMaxThickness())));
}

void PencilPreferencesPanel::UpdateRedColor(float value) {
    Color color(pencil_->GetColor());
    color.red = value;

    pencil_->SetColor(color);
}

void PencilPreferencesPanel::UpdateGreenColor(float value) {
    Color color(pencil_->GetColor());
    color.green = value;

    pencil_->SetColor(color);
}

void PencilPreferencesPanel::UpdateBlueColor(float value) {
    Color color(pencil_->GetColor());
    color.blue = value;

    pencil_->SetColor(color);
}