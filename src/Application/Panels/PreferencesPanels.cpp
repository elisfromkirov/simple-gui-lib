#include "Application/Panels/MainPanel.hpp"
#include "Application/Panels/PreferencesPanels.hpp"
#include "GUI/Styles/FilledStyle.hpp"
#include "GUI/Styles/SliderStyle.hpp"

PencilPreferencesPanel::PencilPreferencesPanel(Pencil* pencil)
    : ContainerWidget{Rect2(MainPanel::kToolPanelWidth, 38)},
      pencil_{pencil},
      thickness_slider_{nullptr} {
    thickness_slider_ = new HorizontalSlider(Rect2(200, 30, 4, 4), 10);
    thickness_slider_->ApplyStyle(new ProgressHorizontalSliderStyle());
    thickness_slider_->ValueChanged.Connect<PencilPreferencesPanel>(this, &PencilPreferencesPanel::UpdateThickness);
    Attach(thickness_slider_);

    ApplyStyle(new FilledStyle(FilledStyle::kLightPanel));
}

PencilPreferencesPanel::~PencilPreferencesPanel() {}

void PencilPreferencesPanel::UpdateThickness(float value) {
    pencil_->SetThickness(static_cast<uint32_t>(value * 40.f));
}
