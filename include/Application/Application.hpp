#ifndef __APPLICATION_HPP__
#define __APPLICATION_HPP__

#include "EventDispatcher.hpp"

#include "Input.hpp"
#include "Renderer.hpp"
#include "Window.hpp"

class Application {
public:
    Application();
    ~Application();

    void Run();

private:
    EventDispatcher* event_dispatcher_;

    Window   window_;
    Input    input_;
    Renderer renderer_;
};

#endif // __APPLICATION_HPP__
