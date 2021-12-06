#include "Core/ResourceManager/ResourceManager.hpp"
#include "Core/Platform/Rectangle.hpp"
#include "Core/Platform/RenderTexture.hpp"
#include "GUI/Styles/ButtonStyle.hpp"
#include "GUI/Widgets/Widget.hpp"

const Color ButtonStyle::kColorOnRelease{ColorFromRGBA(0x434343ff)};
const Color ButtonStyle::kColorOnHover  {ColorFromRGBA(0x505050ff)};
const Color ButtonStyle::kColorOnPress  {ColorFromRGBA(0x5680c2ff)};

ButtonStyle::ButtonStyle(const char* image)
    : image_{ResourceManager::GetInstance()->LoadTexture(image)} {}

ButtonStyle::~ButtonStyle() {}

void ButtonStyle::Apply(Widget* widget, IRenderTarget* render_target) {
    assert(widget        != nullptr);
    assert(render_target != nullptr);

    Rectangle rectangle(Rect2(widget->GetSize()), Color{});
    if (widget->IsPressed()) {
        rectangle.SetFillColor(kColorOnPress);
    } else if (widget->IsHovered()) {
        rectangle.SetFillColor(kColorOnHover);
    } else {
        rectangle.SetFillColor(kColorOnRelease);
    }

    render_target->RenderRectangle(rectangle);

    Vector2i position(static_cast<int32_t>((widget->GetSize().x - image_.GetSize().x) / 2),
                      static_cast<int32_t>((widget->GetSize().y - image_.GetSize().y) / 2));
    image_.SetPosition(position);

    render_target->RenderImage(image_);
}

const Color MenuButtonStyle::kColorOnRelease{ColorFromRGBA(0xa6a6a6ff)};
const Color MenuButtonStyle::kColorOnHover  {ColorFromRGBA(0x5d84beff)};
const Color MenuButtonStyle::kColorOnPress  {ColorFromRGBA(0x5d84beff)};

MenuButtonStyle::MenuButtonStyle() {}

MenuButtonStyle::~MenuButtonStyle() {}

void MenuButtonStyle::Apply(Widget* widget, IRenderTarget* render_target) {
    assert(widget        != nullptr);
    assert(render_target != nullptr);

    Rectangle rectangle(Rect2(widget->GetSize()), Color{});
    if (widget->IsPressed()) {
        rectangle.SetFillColor(kColorOnPress);
    } else if (widget->IsHovered()) {
        rectangle.SetFillColor(kColorOnHover);
    } else {
        rectangle.SetFillColor(kColorOnRelease);
    }

    render_target->RenderRectangle(rectangle);   
}