#ifndef __LABEL_HPP__
#define __LABEL_HPP__

#include <cassert>
#include <cstdint>

#include "GUI/Widgets/Widget.hpp"

class Label : public Widget {
public:
    Label(const std::string& string, const Color& color = Color{0, 0, 0, 1});

    virtual ~Label() override;

    void SetCharacterSize(uint32_t char_size);

    void SetString(const std::string& string);

protected:
    virtual void Render(Renderer* renderer) const override;

    virtual void Resize(const Vector2u& size) override; 

    virtual void Move(const Vector2i& displacement) override;

protected:
    Text text_;
};

#endif // __LABEL_HPP__
