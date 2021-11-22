#include "Core/Platform/Renderer.hpp"
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

void FilledStyle::Apply(Widget* widget, Renderer* renderer) {
    assert(widget   != nullptr);
    assert(renderer != nullptr);
    
    switch (widget->GetState()) {
    case Widget::State::kReleased: {
        renderer->RenderRectangle(widget->GetPosition(), widget->GetSize(), color_on_release_);        
    } break;
    case Widget::State::kHovered: {
        renderer->RenderRectangle(widget->GetPosition(), widget->GetSize(), color_on_hover_);
    } break;
    case Widget::State::kPressed: {
        renderer->RenderRectangle(widget->GetPosition(), widget->GetSize(), color_on_press_);
    } break;
    default: {}
    }
}
