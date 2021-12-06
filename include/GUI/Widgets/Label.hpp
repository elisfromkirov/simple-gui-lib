#ifndef __LABEL_HPP__
#define __LABEL_HPP__

#include <cassert>
#include <cstdint>

#include "Core/Platform/Text.hpp"
#include "GUI/Widgets/Widget.hpp"

class Label : public Widget {
public:
    Label(const std::string& string, const Font& font);
    virtual ~Label() override;

    virtual void OnRender(IRenderTarget* render_target) override;

    void SetCharSize(uint32_t char_size);

    void SetString(const std::string& string);

    void SetTextColor(const Color& color);

protected:
    Text text_;
};

#endif // __LABEL_HPP__