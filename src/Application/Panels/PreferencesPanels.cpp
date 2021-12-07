#include "Application/Tools/Tools.hpp"
#include "Application/Panels/PreferencesPanels.hpp"

PencilPreferencesPanel::PencilPreferencesPanel(Pencil* pencil)
    : ContainerWidget{},
      pencil_{pencil},
      palette_{nullptr} {
    palette_   = new Palette();
    palette_->ColorChanged.Connect<PencilPreferencesPanel>(this, &PencilPreferencesPanel::ChangeColorResponse);
    Attach(palette_);

    rect_.size = palette_->GetSize();

    texture_   = new RenderTexture(rect_.size);
}

PencilPreferencesPanel::~PencilPreferencesPanel() {}

void PencilPreferencesPanel::ChangeColorResponse(const Color& color) {
    assert(pencil_);
    
    pencil_->SetColor(color);
}

EraserPreferencesPanel::EraserPreferencesPanel(Eraser* eraser, uint32_t max_thickness)
    : ContainerWidget{},
      eraser_{eraser},
      thickness_slider_{nullptr} {
    thickness_slider_ = new ThicknessSlider(max_thickness);
    thickness_slider_->ThicknessChanged.Connect<EraserPreferencesPanel>(this, &EraserPreferencesPanel::ChangeThicknessResponse);
    Attach(thickness_slider_);
    
    rect_.size = thickness_slider_->GetSize();

    texture_   = new RenderTexture(rect_.size);
}

EraserPreferencesPanel::~EraserPreferencesPanel() {}

void EraserPreferencesPanel::ChangeThicknessResponse(uint32_t thickness) {
    assert(eraser_);
    
    eraser_->SetThickness(thickness);
}

BrushPreferencesPanel::BrushPreferencesPanel(Brush* brush, uint32_t max_thickness)
    : ContainerWidget{},
      brush_{brush},
      palette_{nullptr},
      thickness_slider_{nullptr} {
    palette_ = new Palette();
    palette_->ColorChanged.Connect<BrushPreferencesPanel>(this, &BrushPreferencesPanel::ChangeColorResponse);
    Attach(palette_);

    thickness_slider_ = new ThicknessSlider(max_thickness);
    thickness_slider_->Move(Vector2i(0.f, palette_->GetSize().y));
    thickness_slider_->ThicknessChanged.Connect<BrushPreferencesPanel>(this, &BrushPreferencesPanel::ChangeThicknessResponse);
    Attach(thickness_slider_);

    rect_.size.x = std::max(palette_->GetSize().x, thickness_slider_->GetSize().x);
    rect_.size.y = palette_->GetSize().y + thickness_slider_->GetSize().y;

    texture_   = new RenderTexture(rect_.size);
}

BrushPreferencesPanel::~BrushPreferencesPanel() {}

void BrushPreferencesPanel::ChangeColorResponse(const Color& color) {
    assert(brush_ != nullptr);

    brush_->SetColor(color);
}

void BrushPreferencesPanel::ChangeThicknessResponse(uint32_t thickness) {
    assert(brush_ != nullptr);

    brush_->SetThickness(thickness);
}