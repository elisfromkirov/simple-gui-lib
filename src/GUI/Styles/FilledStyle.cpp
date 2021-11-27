#include "Core/Platform/Rectangle.hpp"
#include "Core/Platform/RenderTexture.hpp"
#include "GUI/Styles/FilledStyle.hpp"
#include "GUI/Widgets/Widget.hpp"

FilledStyle::FilledStyle(const Color& color)
    : color_on_release_{color},
      color_on_hover_{color},
      color_on_press_{color} {}

FilledStyle::FilledStyle(const Color& color_on_release,
                         const Color& color_on_hover,
                         const Color& color_on_press)
    : color_on_release_{color_on_release},
      color_on_hover_{color_on_hover},
      color_on_press_{color_on_press} {}

FilledStyle::~FilledStyle() {}

void FilledStyle::Apply(Widget* widget, RenderTexture* texture) {
    assert(widget  != nullptr);
    assert(texture != nullptr);

    Rectangle rectangle(Rect2{widget->GetSize(), widget->GetPosition()});
    rectangle.SetFillColor(color_on_release_);

    texture->RenderRectangle(rectangle);
}