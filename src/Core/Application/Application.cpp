#include "Core/Application/Application.hpp"

Application::Application()
    : event_manager_{nullptr},
      log_manager_{nullptr},
      resource_manager_{nullptr} {
    event_manager_ = EventManager::GetEventManager();
    assert(event_manager_ != nullptr);
    
    log_manager_ = LogManager::GetLogManager();
    assert(log_manager_ != nullptr);

    resource_manager_ = ResourceManager::GetResourceManager();
    assert(resource_manager_ != nullptr);
}

Application::~Application() {
    delete event_manager_;
    delete log_manager_;
    delete resource_manager_;
}