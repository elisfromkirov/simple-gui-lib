#include "Button.hpp"

Button::Button(Sprite* sprite, const Vector2u& position)
    : Widget{sprite->GetSize(), position} {
    Attach(new ImageWidget(sprite, position), Vector2u());
}

Button::~Button() {}
