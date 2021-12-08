#include "Application/Panels/PreferencesPanels.hpp"
#include "Application/Tools/Tools.hpp"
#include "Core/ResourceManager/Resources.hpp"

static void DrawLine(RenderTexture* canvas, Rectangle* rectangle, Vector2i begin, Vector2i end) {
    Vector2i delta(abs(end.x - begin.x), abs(end.y - begin.y));
    Vector2i sign((end.x > begin.x ? 1 : -1), (end.y > begin.y ? 1 : -1)); 

    int32_t error = delta.x - delta.y;

    rectangle->SetPosition(end);
    canvas->RenderRectangle(*rectangle);
    while(begin.x != end.x || begin.y != end.y) {    
        rectangle->SetPosition(begin);
        canvas->RenderRectangle(*rectangle);
    
        int32_t error2 = error * 2;
        if(error2 > -delta.y) {
            error   -= delta.y;
            begin.x += sign.x;
        }
        if(error2 < delta.x) {
            error   += delta.x;
            begin.y += sign.y;
        }
    }
}

Pencil::Pencil()
    : rectangle_{Rect2{1, 1}, Color{0.f, 0.f, 0.f, 1.f}},
      preferences_panel_{nullptr} {
    preferences_panel_ = new PencilPreferencesPanel(this);
}

Pencil::~Pencil() {}

void Pencil::BeginDraw(RenderTexture* canvas, const Vector2i& position) {
    assert(canvas != nullptr);

    DrawLine(canvas, &rectangle_, position, position);

    canvas->Display();
}

void Pencil::Draw(RenderTexture* canvas, const Vector2i& position, const Vector2i& old_position) {
    assert(canvas != nullptr);

    DrawLine(canvas, &rectangle_, old_position, position);

    canvas->Display();
}

void Pencil::EndDraw(RenderTexture* canvas, const Vector2i& position) {
    assert(canvas != nullptr);
}

const char* Pencil::GetIconFileName() const {
    return kPencilImage;
}

const char* Pencil::GetName() const {
    return "Pencil";
}

Widget* Pencil::GetPreferencesPanel() {
    return preferences_panel_;
}

void Pencil::SetColor(const Color& color) {
    rectangle_.SetFillColor(color);
}

Eraser::Eraser()
    : rectangle_{Rect2{1, 1}, Color{1.f, 1.f, 1.f, 1.f}},
      preferences_panel_{nullptr} {
    preferences_panel_ = new EraserPreferencesPanel(this, 10);
}

Eraser::~Eraser() {}

void Eraser::BeginDraw(RenderTexture* canvas, const Vector2i& position) {
    assert(canvas != nullptr);

    DrawLine(canvas, &rectangle_, position, position);

    canvas->Display();
}

void Eraser::Draw(RenderTexture* canvas, const Vector2i& position, const Vector2i& old_position) {
    assert(canvas != nullptr);

    DrawLine(canvas, &rectangle_, old_position, position);

    canvas->Display();
}

void Eraser::EndDraw(RenderTexture* canvas, const Vector2i& position) {
    assert(canvas != nullptr);
}

const char* Eraser::GetIconFileName() const {
    return kEraserImage;
}

const char* Eraser::GetName() const {
    return "Eraser";
}

Widget* Eraser::GetPreferencesPanel() {
    return preferences_panel_;
}

void Eraser::SetThickness(uint32_t thickness) {
    rectangle_.SetSize(Vector2u{thickness, thickness});
}

Brush::Brush()
    : rectangle_{Rect2{1, 1}, Color{1.f, 1.f, 1.f, 1.f}},
      preferences_panel_{nullptr} {
    preferences_panel_ = new BrushPreferencesPanel(this, 10);
}

Brush::~Brush() {}

void Brush::BeginDraw(RenderTexture* canvas, const Vector2i& position) {
    assert(canvas != nullptr);

    DrawLine(canvas, &rectangle_, position, position);

    canvas->Display();
}

void Brush::Draw(RenderTexture* canvas, const Vector2i& position, const Vector2i& old_position) {
    assert(canvas != nullptr);

    DrawLine(canvas, &rectangle_, old_position, position);

    canvas->Display();
}

void Brush::EndDraw(RenderTexture* canvas, const Vector2i& position) {
    assert(canvas != nullptr);
}

const char* Brush::GetIconFileName() const {
    return kBrushImage;
}

const char* Brush::GetName() const {
    return "Brush";
}

Widget* Brush::GetPreferencesPanel() {
    return preferences_panel_;
}

void Brush::SetColor(const Color& color) {
    rectangle_.SetFillColor(color);
}

void Brush::SetThickness(uint32_t thickness) {
    rectangle_.SetSize(Vector2u{thickness, thickness});
}