#ifndef __BUTTON_HPP__
#define __BUTTON_HPP__

#include <cassert>
#include <cstdint>

#include "ContainerWidget.hpp"
#include "ImageWidget.hpp"

class Button : public ContainerWidget {
public:
    Button(Sprite* sprite, const Vector2u& position);

    virtual ~Button() override;
};

#endif // __BUTTON_HPP__
