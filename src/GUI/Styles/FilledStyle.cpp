#include "Core/Platform/Rectangle.hpp"
#include "Core/Platform/RenderTexture.hpp"
#include "GUI/Styles/FilledStyle.hpp"
#include "GUI/Widgets/Widget.hpp"

FilledStyle::FilledStyle(WidgetType widget_type)
    : color_{} {
    switch (widget_type) {
        case kFrame: {
            color_ = ColorFromRGBA(0xff);
        } break;
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
        case kLightPanel: {
            color_ = ColorFromRGBA(0xa9a9a9ff);
        } break;
        case kDarkPanel: {
            color_ = ColorFromRGBA(0x656565ff);
        } break;
        case kMainPanel: {
            color_ = ColorFromRGBA(0x1f1f1fff);
        } break;
    }
}

FilledStyle::FilledStyle(const Color& color)
    : color_{color} {}

FilledStyle::~FilledStyle() {}

void FilledStyle::Apply(Widget* widget, IRenderTarget* render_target) {
    assert(widget        != nullptr);
    assert(render_target != nullptr);

    render_target->RenderRectangle(Rectangle(Rect2(widget->GetSize()), color_));
}