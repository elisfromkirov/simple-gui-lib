#include "Application/Application.hpp"
#include "Application/Panels/MainPanel.hpp"
#include "Application/Tools/ToolManager.hpp"
#include "Core/EventManager/EventManager.hpp"
#include "Core/LogManager/LogManager.hpp"
#include "Core/ResourceManager/ResourceManager.hpp"
#include "Core/Platform/Color.hpp"

const Vector2u Application::kDefaultSize{1600, 1200};

Application::Application(const std::string& name)
    : log_manager_{nullptr},
      event_manager_{nullptr},
      resource_manager_{nullptr},
      tool_manager_{nullptr},
      render_window_{name, kDefaultSize},
      window_{kDefaultSize} {
    log_manager_      = LogManager::GetInstance();
    event_manager_    = EventManager::GetInstance();    
    resource_manager_ = ResourceManager::GetInstance();
    tool_manager_     = ToolManager::GetInstance();

    window_.Attach(new MainPanel(window_.GetSize()));

    event_manager_->RegisterListener(&window_);
}

Application::~Application() {
    assert(tool_manager_     != nullptr);
    assert(resource_manager_ != nullptr);
    assert(event_manager_    != nullptr);
    assert(log_manager_      != nullptr);

    tool_manager_->Release();
    resource_manager_->Release();
    event_manager_->Release();
    log_manager_->Release();
}

void Application::Run() {
    while (render_window_.IsOpen()) {
        render_window_.PumpEvents();

        event_manager_->DispatchEvents();

        render_window_.Clear(Color());
        window_.OnRender(&render_window_);
        render_window_.Display();
    }
}