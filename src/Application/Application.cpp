#include "Application/Application.hpp"
#include "Core/EventManager/EventManager.hpp"
#include "Core/LogManager/LogManager.hpp"
#include "Core/ResourceManager/ResourceManager.hpp"
#include "Core/Platform/Color.hpp"

Application::Application(const std::string& name)
    : event_manager_{nullptr},
      log_manager_{nullptr},
      resource_manager_{nullptr},
      window_{name, Vector2u(1600, 1200)} {
    EventManager* event_manager_ = EventManager::GetInstance();
    assert(event_manager_ != nullptr);

    LogManager* log_manager_ = LogManager::GetInstance();
    assert(log_manager_ != nullptr);

    ResourceManager* resource_manager_ = ResourceManager::GetInstance();
    assert(resource_manager_ != nullptr);
}

Application::~Application() {
    resource_manager_->Release();
    event_manager_->Release();
    log_manager_->Release();
}

void Application::Run() {
    while (window_.IsOpen()) {
        window_.PumpEvents();

        event_manager_->DispatchEvents();

        window_.Clear(Color(1.f, 1.f, 1.f, 1.f));

        window_.Display();
    }
}