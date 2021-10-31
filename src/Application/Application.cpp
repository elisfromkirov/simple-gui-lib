#include "Application.hpp"

Application::Application()
    : event_dispatcher_{nullptr},
      window_{"paint"},
      input_{&window_},
      renderer_{&window_},
      sprite_{nullptr},
      button_{nullptr} {
    event_dispatcher_ = EventDispatcher::GetEventDispatcher();
    event_dispatcher_->AddListener(this);

    sprite_ = new Sprite("../assets/Icons/Close.bmp");

    button_ = new Button(sprite_, Vector2u(100, 100));
    
    button_->SetHandler<kMouseButtonPress>(new ButtonHandler<CloseApplicationFunctor>(this));
}

Application::~Application() {
    delete button_;
    
    delete sprite_;
}

bool Application::OnEvent(const IEvent* event) {
    switch (event->GetMask()) {
        case kMouseButtonPress: {
            button_->OnMouseButtonPress(dynamic_cast<const MouseButtonPressEvent*>(event));
        } break;
        case kMouseButtonRelease: {
            button_->OnMouseButtonRelease(dynamic_cast<const MouseButtonReleaseEvent*>(event));
        } break;
        case kMouseMove: {
            button_->OnMouseMove(dynamic_cast<const MouseMoveEvent*>(event));
        } break;
        default: {}
    }

    return true;
}

void Application::Run() {
    while (window_.IsOpen()) {
        input_.PumpEvents();

        event_dispatcher_->DispatchEvents();

        renderer_.Clear(Color{1, 0, 0, 1});

        button_->OnRender(&renderer_);

        renderer_.Present();
    }
}

void Application::Close() {
    window_.Close();
}

CloseApplicationFunctor::CloseApplicationFunctor(Application* application)
    : application_{application} {
    assert(application_ != nullptr);
}

CloseApplicationFunctor::~CloseApplicationFunctor() {}

void CloseApplicationFunctor::operator()() {
    assert(application_ != nullptr);

    application_->Close();
}
