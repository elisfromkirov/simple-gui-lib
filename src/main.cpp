#include "IEventListener.hpp"
#include "EventDispatcher.hpp"

#include "Input.hpp"
#include "QuitEvent.hpp"

#include "Renderer.hpp"
#include "Window.hpp"

class Application : public IEventListener {
public:
    Application() 
        : window_{"test sdl wrapper"},
          renderer_{&window_},
          running_{true},
          dispatcher_{nullptr} {
        dispatcher_ = EventDispatcher::GetEventDispatcher();
        assert(dispatcher_ != nullptr);

        dispatcher_->RegisterListener(this);
    }

    virtual ~Application() override {}

    virtual void OnEvent(const IEvent* event) override {
        if (event->GetMask() == kQuitEventMask) {
            running_ = false;
        }
    }

    void Running() {
        while (running_) {
            PumpEvents();
            dispatcher_->DispatchEvents();

            renderer_.SetRenderColor(Color{0.f, 0.f, 0.f});
            renderer_.Clear();

            renderer_.SetRenderColor(Color{1.f, 1.f, 1.f});
            renderer_.RenderPoint(Vector2<uint32_t>{100, 100});
            renderer_.RenderPoint(Vector2<uint32_t>{100, 200});
            renderer_.RenderPoint(Vector2<uint32_t>{200, 100});
            renderer_.RenderPoint(Vector2<uint32_t>{200, 200});

            renderer_.Present();
        }
    }

private:
    Window window_;
    Renderer renderer_;

    bool running_;

    EventDispatcher* dispatcher_;
};

int main() {
    Application application{};
    application.Running();
    return 0;
}
