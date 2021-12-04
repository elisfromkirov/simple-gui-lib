#include "Core/Platform/Rectangle.hpp"
#include "Core/Platform/RenderTexture.hpp"
#include "GUI/Styles/FilledStyle.hpp"
#include "GUI/Widgets/Widget.hpp"

FilledStyle::FilledStyle(WidgetType widget_type)
    : color_{} {
    switch (widget_type) {
        case kList: {
            color_ = ColorFromRGBA(0xa9a9a9ff);
        } break;
        case kMenuBar: {
            color_ = ColorFromRGBA(0xa9a9a9ff);
        } break;
        case kTitleBar: {
            color_ = ColorFromRGBA(0xa9a9a9ff);
        } break;
        case kTabBar: {
            color_ = ColorFromRGBA(0x656565ff);
        } break;
        case kMainWindow: {
            color_ = ColorFromRGBA(0x1f1f1fff);
        } break;
    }
}

FilledStyle::FilledStyle(const Color& color)
    : color_{color} {}

FilledStyle::~FilledStyle() {}

void FilledStyle::Apply(Widget* widget, RenderTexture* texture) {
    assert(widget  != nullptr);
    assert(texture != nullptr);

    texture->RenderRectangle(Rectangle(Rect2(widget->GetSize()), color_));
}