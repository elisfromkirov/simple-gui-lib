#ifndef __LABEL_HPP__
#define __LABEL_HPP__

#include <cassert>
#include <cstdint>

#include "Core/Platform/Text.hpp"
#include "GUI/Widgets/Widget.hpp"

class Label : public Widget {
public:
    Label(const std::string& string, const Font& font, const Vector2i& position = Vector2i());
    virtual ~Label() override;

    virtual void OnRender(RenderTexture* texture) override;

    virtual void Resize(const Vector2u& size) override;

    virtual void Move(const Vector2i& position) override;

    void SetCharSize(uint32_t char_size);

    void SetString(const std::string& string);

    void SetTextColor(const Color& color);

protected:
    Text text_;
};

#endif // __LABEL_HPP__