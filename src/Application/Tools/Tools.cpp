#include <math.h>

#include "Application/Panels/PreferencesPanels.hpp"
#include "Application/Tools/Tools.hpp"
#include "Core/Platform/Color.hpp"
#include "Core/Platform/Rectangle.hpp"
#include "Core/Platform/RenderTexture.hpp"
#include "Core/ResourceManager/Resources.hpp"

Pencil::Pencil()
    : thickness_{0},
      color_{0.f, 0.f, 0.f, 1.f},
      preferences_panel_{nullptr} {
    preferences_panel_ = new PencilPreferencesPanel(this);
}

Pencil::~Pencil() {}

void Pencil::BeginDraw(RenderTexture* canvas, Vector2i position) {
    assert(canvas != nullptr);

    Rectangle rect(Rect2(thickness_, thickness_), color_);

    rect.SetPosition(position);
    canvas->RenderRectangle(rect);

    canvas->Display();
}

void Pencil::Draw(RenderTexture* canvas, Vector2i position, Vector2i old_position) {
    assert(canvas != nullptr);

    Rectangle rect(Rect2(thickness_, thickness_), color_);

    Vector2i delta(abs(position.x - old_position.x), abs(position.y - old_position.y));
    Vector2i sign((position.x > old_position.x ? 1 : -1), (position.y > old_position.y ? 1 : -1)); 

    int32_t error = delta.x - delta.y;

    rect.SetPosition(position);
    canvas->RenderRectangle(rect);
    while(old_position.x != position.x || old_position.y != position.y) {    
        rect.SetPosition(old_position);
        canvas->RenderRectangle(rect);
    
        int32_t error2 = error * 2;
        if(error2 > -delta.y) {
            error          -= delta.y;
            old_position.x += sign.x;
        }
        if(error2 < delta.x) {
            error          += delta.x;
            old_position.y += sign.y;
        }
    }

    canvas->Display();
}

void Pencil::EndDraw(RenderTexture* canvas, Vector2i position) {
    assert(canvas != nullptr);
}

const char* Pencil::GetIconFileName() const {
    return kPencilImage;
}

const char* Pencil::GetName() const {
    return "Pencil";
}

ContainerWidget* Pencil::GetPreferencesPanel() {
    return preferences_panel_;
}

void Pencil::SetThickness(uint32_t thickness) {
    thickness_ = thickness;
}

uint32_t Pencil::GetMaxThickness() const {
    return 20;
}

void Pencil::SetColor(const Color& color) {
    color_ = color;
}

const Color& Pencil::GetColor() {
    return color_;
}