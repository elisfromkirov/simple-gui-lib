#ifndef __TEXT_WIDGET_HPP__
#define __TEXT_WIDGET_HPP__

#include <cassert>
#include <cstdint>

#include "Core/Math/Vector2.hpp"
#include "GUI/Widgets/Widget.hpp"
#include "Platform/Renderer.hpp"
#include "Platform/Text.hpp"

class TextVeiw : public Widget {
public:
    TextVeiw(Text* text, const Vector2u& size, const Vector2u& postion = Vector2u());

    virtual ~TextVeiw() override;

    virtual void OnRender(Renderer* renderer) const override;

protected:
    Text* text_;
};

#endif // __TEXT_WIDGET_HPP__
