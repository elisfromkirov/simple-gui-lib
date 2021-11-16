#ifndef __PLATFORM_HPP__
#define __PLATFORM_HPP__

#include <cassert>
#include <cstdint>

#include <SFML/Graphics.hpp>

#include "Core/Platform/InputEvent.hpp"

class RenderWindow;

class Input {
public:
    Input(RenderWindow* window);
    ~Input();

    bool PumpEvents();

private:
    static MouseButton GetButton(const sf::Event& event);

    static Key         GetKey   (const sf::Event& event);

private:
    sf::RenderWindow* window_;

    Vector2i          position_;
    MouseButton       pressed_button_;
    bool              pressed_;

    Key               key_;
    bool              alt_;
    bool              control_;
    bool              shift_;
    bool              system_;
};

#endif // __PLATFORM_HPP__