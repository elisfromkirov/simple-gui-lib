#ifndef __APPLICATION_HPP__
#define __APPLICATION_HPP__

#include <cassert>
#include <cstdint>

#include "Core/Platform/Input.hpp"
#include "Core/Platform/Renderer.hpp"
#include "Core/Platform/RenderWindow.hpp"

class EventManager;
class LogManager;
class ResourceManager;
class WidgetManager;

class Application {
public:
    Application(const std::string& name);
    ~Application();

    virtual void Run();

protected:
    LogManager*      log_manager_;
    EventManager*    event_manager_;
    ResourceManager* resource_manager_;
    WidgetManager*   widget_manager_;

    RenderWindow     window_;
    Renderer         renderer_;
    Input            input_;
};

#endif // __APPLICATION_HPP__