#ifndef __APPLICATION_HPP__
#define __APPLICATION_HPP__

#include <cassert>
#include <cstdint>

#include "Core/Platform/RenderWindow.hpp"

class EventManager;
class LogManager;
class ResourceManager;

class Application {
public:
    Application(const std::string& name);
    ~Application();

    void Run();

protected:
    EventManager*    event_manager_;
    LogManager*      log_manager_;
    ResourceManager* resource_manager_;

    RenderWindow     window_;
};

#endif // __APPLICATION_HPP__