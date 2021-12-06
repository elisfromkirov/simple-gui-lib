#include "Application/Panels/PreferencesPanels.hpp"
#include "Application/Tools/Tools.hpp"
#include "Core/Platform/Color.hpp"
#include "Core/Platform/Rectangle.hpp"
#include "Core/Platform/RenderTexture.hpp"
#include "Core/ResourceManager/Resources.hpp"

Pencil::Pencil()
    : thickness_{1},
      preferences_panel_{nullptr} {
    preferences_panel_ = new PencilPreferencesPanel(this);
}

Pencil::~Pencil() {}

void Pencil::BeginDraw(RenderTexture* canvas, const Vector2i& position) {
    assert(canvas != nullptr);

    canvas->RenderRectangle(Rectangle(Rect2(thickness_, thickness_, position.x, position.y), Color(1.f, 0.f, 0.f, 1.f)));
    canvas->Display();
}

void Pencil::Draw(RenderTexture* canvas, const Vector2i& position, const Vector2i& old_position) {
    assert(canvas != nullptr);
}

void Pencil::EndDraw(RenderTexture* canvas, const Vector2i& position) {
    assert(canvas != nullptr);
}

const char* Pencil::GetIconFileName() const {
    return kPencilImage;
}

ContainerWidget* Pencil::GetPreferencesPanel() {
    return preferences_panel_;
}

void Pencil::SetThickness(uint32_t thickness) {
    thickness_ = thickness;
}