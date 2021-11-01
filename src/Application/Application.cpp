#include "Application.hpp"

Application::Application()
    : event_dispatcher_{nullptr},
      command_queue_{nullptr},
      window_{"paint"},
      input_{&window_},
      renderer_{&window_},
      main_panel_{window_} {
    event_dispatcher_ = EventDispatcher::GetEventDispatcher();
    event_dispatcher_->AddListener(&main_panel_);

    command_queue_ = CommandQueue::GetCommandQueue();
}

Application::~Application() {}

void Application::Run() {
    while (window_.IsOpen()) {
        input_.PumpEvents();

        event_dispatcher_->DispatchEvents();

        command_queue_->ExecuteCommands();

        renderer_.Clear(Color{1, 0, 0, 1});

        main_panel_.OnRender(&renderer_);

        renderer_.Present();
    }
}
