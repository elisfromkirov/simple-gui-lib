#ifndef __TITLE_HPP__
#define __TITLE_HPP__

#include "Button.hpp"
#include "ImageWidget.hpp"
#include "TextWidget.hpp"
#include "Widget.hpp"

class Title : public Widget {
private:
    static const Font kTitleFont;

public:
    Title(const std::string& title, Widget* widget);

    virtual ~Title() override;

private:
    Sprite* close_button_sprite_;
    Text*   title_text_;
};

#endif // __TITLE_HPP__
