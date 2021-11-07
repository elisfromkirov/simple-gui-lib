#ifndef __APPLICATION_HPP__
#define __APPLICATION_HPP__

#include "Core/EventManager/EventManager.hpp"
#include "Core/LogManager/LogManager.hpp"
#include "Platform/Input.hpp"
#include "Platform/Renderer.hpp"
#include "Platform/Window.hpp"

class Application {
public:
    Application(const char* name);
    ~Application();

    void Run();

protected:
    virtual void OnRender();

    virtual void OnInput();

protected:
    EventManager*    event_manager_;
    LogManager*      log_manager_;

    Window   window_;
    Input    input_;
    Renderer renderer_;
};

#endif // __APPLICATION_HPP__
