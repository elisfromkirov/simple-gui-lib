#ifndef __BUTTON_STYLE_HPP__
#define __BUTTON_STYLE_HPP__

#include <cassert>
#include <cstdint>
#include <string>

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
    ButtonStyle(const std::string& image_file);
    virtual ~ButtonStyle() override;

    virtual void Apply(Widget* widget, IRenderTarget* render_target) override;

protected:
    Image image_;
};

class LightButtonStyle : public IStyle {
private:
    static const Color kColorOnRelease;
    static const Color kColorOnHover;
    static const Color kColorOnPress;

public:
    LightButtonStyle(const std::string& image_file);
    virtual ~LightButtonStyle() override;

    virtual void Apply(Widget* widget, IRenderTarget* render_target) override;

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

    virtual void Apply(Widget* widget, IRenderTarget* render_target) override;
};

#endif // __BUTTON_STYLE_HPP__