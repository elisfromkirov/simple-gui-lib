#include "Button.hpp"

Button::Button(Sprite* sprite, const Vector2u& position)
    : ContainerWidget{sprite->GetSize(), position} {
    ImageWidget* image_on_button = new ImageWidget(sprite, position);
    Attach(image_on_button, Vector2u());
}

Button::~Button() {}
