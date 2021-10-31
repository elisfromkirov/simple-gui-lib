#include "Application.hpp"

Application::Application()
    : window_{"paint"},
      input_{&window_},
      renderer_{&window_} {
    event_dispatcher_ = EventDispatcher::GetEventDispatcher();


}

Application::~Application() {}

void Application::Run() {
    while (window_.IsOpen()) {
        input_.PumpEvents();

        event_dispatcher_->DispatchEvents();

        renderer_.Clear();

        renderer_.Present();
    }
}
