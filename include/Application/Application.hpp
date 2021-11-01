#ifndef __APPLICATION_HPP__
#define __APPLICATION_HPP__

#include "CommandQueue.hpp"
#include "EventDispatcher.hpp"
#include "Input.hpp"
#include "MainPanel.hpp"
#include "Renderer.hpp"
#include "Window.hpp"

class Application {
public:
    Application();
    ~Application();

    void Run();

private:
    EventDispatcher* event_dispatcher_;
    CommandQueue*    command_queue_;

    Window           window_;
    Input            input_;
    Renderer         renderer_;

    MainPanel        main_panel_;
};

#endif // __APPLICATION_HPP__
