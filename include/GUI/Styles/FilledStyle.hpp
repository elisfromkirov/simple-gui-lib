#ifndef __FILLED_STYLE_HPP__
#define __FILLED_STYLE_HPP__

#include "Core/Math/Rect2.hpp"
#include "Core/Platform/Color.hpp"
#include "GUI/Styles/IStyle.hpp"

class FilledStyle : public IStyle {
public:
    enum WidgetType {
        kFrame,
        kList,
        kMenuBar,
        kTitleBar,
        kTabBar,
        kLightPanel,
        kDarkPanel,
        kMainPanel,
    };

public:
    FilledStyle(WidgetType widget_type);
    FilledStyle(const Color& color);
    virtual ~FilledStyle() override;

    virtual void Apply(Widget* widget, IRenderTarget* render_target) override;

protected:
    Color color_;
};

#endif // __FILLED_STYLE_HPP__