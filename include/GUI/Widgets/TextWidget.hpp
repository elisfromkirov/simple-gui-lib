#ifndef __TEXT_WIDGET_HPP__
#define __TEXT_WIDGET_HPP__

#include <cassert>
#include <cstdint>

#include "Renderer.hpp"
#include "Text.hpp"
#include "Vector2.hpp"
#include "Widget.hpp"

class TextWidget : public Widget {
public:
    TextWidget(Text* text, const Vector2u& size, const Vector2u& postion = Vector2u());

    virtual ~TextWidget() override;

    virtual void OnRender(Renderer* renderer) override;

protected:
    Text* text_;
};

#endif // __TEXT_WIDGET_HPP__
