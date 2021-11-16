#include "Application/Application.hpp"
#include "Application/MainPanel.hpp"
#include "Core/EventManager/EventManager.hpp"
#include "Core/LogManager/LogManager.hpp"
#include "Core/ResourceManager/ResourceManager.hpp"
#include "GUI/WidgetManager/WidgetManager.hpp"

Application::Application(const std::string& name)
    : event_manager_{nullptr},
      log_manager_{nullptr},
      resource_manager_{nullptr},
      window_{name, Vector2u(1600, 1200)},
      renderer_{&window_},
      input_{&window_} {
    event_manager_ = EventManager::GetEventManager();
    assert(event_manager_ != nullptr);

    log_manager_ = LogManager::GetLogManager();
    assert(log_manager_ != nullptr);

    resource_manager_ = ResourceManager::GetResourceManager();
    assert(resource_manager_ != nullptr);

    widget_manager_ = WidgetManager::GetWidgetManager();
    assert(widget_manager_ != nullptr);

    event_manager_->RegisterListener(widget_manager_);

    MainPanel* main_panel = new MainPanel(Vector2u(1600, 1200));
    widget_manager_->SetRootWidget(main_panel);
}

Application::~Application() {
    delete event_manager_;
    delete log_manager_;
    delete resource_manager_;
    delete widget_manager_;
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
