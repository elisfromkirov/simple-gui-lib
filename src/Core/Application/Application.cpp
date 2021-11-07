#include "Core/Application/Application.hpp"

Application::Application(const char* name)
    : event_manager_{nullptr},
      log_manager_{nullptr},
      window_{name},
      input_{&window_},
      renderer_{&window_} {
    event_manager_ = EventManager::GetEventManager();
    assert(event_manager_ != nullptr);
    
    log_manager_ = LogManager::GetLogManager();
    assert(log_manager_ != nullptr);
}

Application::~Application() {
    delete event_manager_;
    delete log_manager_;
}

void Application::Run() {
    while (window_.IsOpen()) {
        OnInput();
        OnRender();
    }
}

void Application::OnRender() {
    renderer_.Clear(Color{0, 0, 0, 1});

    renderer_.Present();
}

void Application::OnInput() {
    input_.PumpEvents();

    event_manager_->DispatchEvents();
}
