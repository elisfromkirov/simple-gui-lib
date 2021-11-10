#ifndef __TITLE_BAR_HPP__
#define __TITLE_BAR_HPP__

#include <cassert>
#include <cstdint>

#include "GUI/Widgets/Image.hpp"
#include "GUI/Widgets/Label.hpp"
#include "GUI/Widgets/Widget.hpp"

class TitleBar : public Widget {
public:
    TitleBar(Widget* widget, const std::string& name, const Color& color);

    virtual ~TitleBar() override;

protected:
    virtual void Render(Renderer* renderer) const override;

    virtual void Resize(const Vector2u& size) override;

protected:
    Color color_;
};

#endif // __TITLE_BAR_HPP__
