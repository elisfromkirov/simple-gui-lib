#ifndef __BUTTON_HPP__
#define __BUTTON_HPP__

#include <cassert>
#include <cstdint>

#include "Widget.hpp"
#include "ImageWidget.hpp"

class Button : public Widget {
public:
    Button(Sprite* sprite, const Vector2u& position = Vector2u());

    virtual ~Button() override;
};

#endif // __BUTTON_HPP__
