#ifndef __APPLICATION_HPP__
#define __APPLICATION_HPP__

#include "Button.hpp"
#include "ButtonHandler.hpp"
#include "EventDispatcher.hpp"
#include "Input.hpp"
#include "MouseEvent.hpp"
#include "Renderer.hpp"
#include "Window.hpp"

class Application : public IEventListener {
public:
    Application();
    virtual ~Application() override;

    virtual bool OnEvent(const IEvent* event) override;

    void Close();

    void Run();

private:
    EventDispatcher* event_dispatcher_;

    Window   window_;
    Input    input_;
    Renderer renderer_;

    Sprite*  sprite_;
    Button*  button_;
};

class CloseApplicationFunctor {
public:
    CloseApplicationFunctor(Application* application);
    ~CloseApplicationFunctor();

    void operator()();

private:
    Application* application_;
};

#endif // __APPLICATION_HPP__
