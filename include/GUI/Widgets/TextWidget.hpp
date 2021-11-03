#ifndef __TEXT_WIDGET_HPP__
#define __TEXT_WIDGET_HPP__

#include <cassert>
#include <cstdint>

#include "Core/Math/Vector2.hpp"
#include "GUI/Widgets/Widget.hpp"
#include "Platform/Renderer.hpp"
#include "Platform/Text.hpp"

class TextWidget : public Widget {
private:
    static const char* kDefaultFontName;

public:
    TextWidget(const std::string& string);

    virtual ~TextWidget() override;

    virtual void OnRender(Renderer* renderer) const override;

    void SetString(const std::string& string);

protected:
    Text* text_;
};

#endif // __TEXT_WIDGET_HPP__
