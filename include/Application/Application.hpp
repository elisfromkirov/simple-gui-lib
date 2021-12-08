#ifndef __APPLICATION_HPP__
#define __APPLICATION_HPP__

#include <cassert>
#include <cstdint>
#include <string>

class LogManager;
class EventManager;
class ResourceManager;
class ToolManager;
class PluginManager;

#include "Core/Platform/RenderWindow.hpp"
#include "GUI/Widgets/Window.hpp"

class Application {
private:
    static const Vector2u kDefaultSize;

public:
    Application(const std::string& name);
    ~Application();

    void Run();

protected:
    LogManager*      log_manager_;
    EventManager*    event_manager_;
    ResourceManager* resource_manager_;
    ToolManager*     tool_manager_;
    PluginManager*   plugin_manager_;

    RenderWindow     render_window_;

    Window           window_;
};

#endif // __APPLICATION_HPP__