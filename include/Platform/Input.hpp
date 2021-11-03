#ifndef __INPUT_HPP__
#define __INPUT_HPP__

#include <cassert>
#include <cstdio>

#include "Core/EventManager/EventManager.hpp"
#include "GUI/Event/InputEvent.hpp"
#include "Platform/Platform.hpp"
#include "Platform/Window.hpp"

class Input {
public:
    Input(Window* window);
    ~Input();

    void PumpEvents();

private:
    sf::RenderWindow* native_window_;

    EventManager*     event_manager_;

    Vector2u          position_;
    MouseButton       button_;
    bool              button_pressed_;

private:
    void SendCloseEvent      (const NativeEvent& event);

    void SendMouseButtonEvent(const NativeEvent& event);

    void SendMouseMoveEvent  (const NativeEvent& event);

    void SendKeyEvent        (const NativeEvent& event);

    MouseButton GetButton    (const NativeEvent& event);

    Key GetKey               (const NativeEvent& event);
};

#endif // __INPUT_HPP__
