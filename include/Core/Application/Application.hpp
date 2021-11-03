#ifndef __APPLICATION_HPP__
#define __APPLICATION_HPP__

#include "Core/EventManager/EventManager.hpp"
#include "Core/LogManager/LogManager.hpp"
#include "Core/ResourceManager/ResourceManager.hpp"

class Application {
public:
    Application();
    ~Application();

protected:
    EventManager*    event_manager_;
    LogManager*      log_manager_;
    ResourceManager* resource_manager_;
};

#endif // __APPLICATION_HPP__
