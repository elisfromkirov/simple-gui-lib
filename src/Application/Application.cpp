#include "Application/Application.hpp"
#include "Application/MainPanel.hpp"
#include "Core/EventManager/EventManager.hpp"
#include "Core/LogManager/LogManager.hpp"
#include "Core/ResourceManager/ResourceManager.hpp"
#include "GUI/WidgetManager/WidgetManager.hpp"

Application::Application(const std::string& name)
    : log_manager_{nullptr},
      event_manager_{nullptr},
      resource_manager_{nullptr},
      widget_manager_{nullptr},
      window_{name, Vector2u(1600, 1200)},
      renderer_{&window_},
      input_{&window_} {
    log_manager_ = LogManager::GetInstance();
    assert(log_manager_ != nullptr);

    event_manager_ = EventManager::GetInstance();
    assert(event_manager_ != nullptr);

    resource_manager_ = ResourceManager::GetInstance();
    assert(resource_manager_ != nullptr);

    widget_manager_ = WidgetManager::GetInstance();
    assert(widget_manager_ != nullptr);

    MainPanel* main_panel = new MainPanel(Vector2u(1600, 1200));
    widget_manager_->SetRootWidget(main_panel);
}

Application::~Application() {
    widget_manager_->Release();
    resource_manager_->Release();
    event_manager_->Release();
    log_manager_->Release();
}

void Application::Run() {
    while (window_.IsOpen()) {
        input_.PumpEvents();

        event_manager_->DispatchEvents();

        renderer_.Clear();

        Widget* root_widget = widget_manager_->GetRootWidget();
        assert(root_widget != nullptr);

        root_widget->OnRender(&renderer_);

        renderer_.Display();
    }
}
