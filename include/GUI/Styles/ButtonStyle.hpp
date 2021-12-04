#ifndef __BUTTON_STYLE_HPP__
#define __BUTTON_STYLE_HPP__

#include "Core/Platform/Color.hpp"
#include "Core/Platform/Image.hpp"
#include "GUI/Styles/IStyle.hpp"

static const uint32_t kIconSize{24};
static const uint32_t kButtonSize{30};

class ButtonStyle : public IStyle {
private:
    static const Color kColorOnRelease;
    static const Color kColorOnHover;
    static const Color kColorOnPress;

public:
    ButtonStyle(const char* image);
    virtual ~ButtonStyle() override;

    virtual void Apply(Widget* widget, RenderTexture* texture) override;

protected:
    Image image_;
};

class MenuButtonStyle : public IStyle {
private:
    static const Color kColorOnRelease;
    static const Color kColorOnHover;
    static const Color kColorOnPress;

public:
    MenuButtonStyle();
    virtual ~MenuButtonStyle() override;

    virtual void Apply(Widget* widget, RenderTexture* texture) override;
};

#endif // __BUTTON_STYLE_HPP__