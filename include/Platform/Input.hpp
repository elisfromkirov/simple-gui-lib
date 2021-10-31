#ifndef __INPUT_HPP__
#define __INPUT_HPP__

#include <cassert>
#include <cstdio>

#include "EventDispatcher.hpp"
#include "KeyEvent.hpp"
#include "MouseEvent.hpp"
#include "Window.hpp"

class Input {
public:
    Input(Window* window);
    ~Input();

    bool PumpEvents();

private:
    sf::RenderWindow* native_window_;

    EventDispatcher*  event_dispatcher_;

    Vector2u          position_;
    MouseButton       button_;
    bool              button_pressed_;

private:
    void SendMouseButtonEvent(const sf::Event& event);

    void SendMouseMoveEvent(const sf::Event& event);

    void SendKeyEvent(const sf::Event& event);

    MouseButton GetButton(const sf::Event& event);

    Key GetKey(const sf::Event& event);
};

#endif // __INPUT_HPP__
