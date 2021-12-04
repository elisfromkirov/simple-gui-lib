#include "Application/Application.hpp"
#include "Core/EventManager/EventManager.hpp"
#include "Core/LogManager/LogManager.hpp"
#include "Core/ResourceManager/ResourceManager.hpp"
#include "Core/ResourceManager/Resources.hpp"
#include "Core/Platform/Color.hpp"
#include "Core/Platform/RenderWindow.hpp"
#include "GUI/Styles/ButtonStyle.hpp"
#include "GUI/Styles/FilledStyle.hpp"
#include "GUI/Styles/SliderStyle.hpp"
#include "GUI/Widgets/Button.hpp"
#include "GUI/Widgets/List.hpp"
#include "GUI/Widgets/Slider.hpp"
#include "GUI/Widgets/ScrollBar.hpp"
#include "GUI/Widgets/MenuBar.hpp"
#include "GUI/Widgets/TitleBar.hpp"
#include "GUI/Widgets/Window.hpp"

#include <cstdio>

void ScrollResponse(float value) {
    printf("%lg\n", value);
}

Application::Application(const std::string& name)
    : event_manager_{nullptr},
      log_manager_{nullptr},
      resource_manager_{nullptr},
      render_window_{nullptr},
      window_{nullptr} {
    event_manager_ = EventManager::GetInstance();
    assert(event_manager_    != nullptr);

    log_manager_ = LogManager::GetInstance();
    assert(log_manager_      != nullptr);
    
    resource_manager_ = ResourceManager::GetInstance();
    assert(resource_manager_ != nullptr);

    render_window_ = new RenderWindow(name, Vector2u(1600, 1200));
    assert(render_window_    != nullptr);

    window_ = new Window(Vector2u(1600, 1200));
    window_->ApplyStyle(new FilledStyle(Color(1.f, 0.f, 0.f, 1.f)));

    event_manager_->RegisterListener(window_);
    
    // ContainerWidget* widget2 = new ContainerWidget(Rect2(800, 800, 200, 200));
    // widget2->ApplyStyle(new FilledStyle(Color(0.f, 0.f, 1.f, 1.f)));

    // TitleBar* title_bar = new TitleBar(widget2, "Some Title");
    // widget2->Attach(title_bar);

    // window_->Attach(widget2);

    // ContainerWidget* widget = nullptr;

    // ScrollingHorizontalList* list = new ScrollingHorizontalList(Rect2{200, 400, 100, 100});
    
    // widget = new ContainerWidget(Rect2{200, 100, 0, 0});
    // widget->ApplyStyle(new FilledStyle(Color(0.f, 0.f, 1.f, 1.f)));
    // list->InsertItem(widget);

    // widget = new ContainerWidget(Rect2{200, 100, 0, 0});
    // widget->ApplyStyle(new FilledStyle(Color(0.f, 1.f, 0.f, 1.f)));
    // list->InsertItem(widget);

    // widget2->AttachInMiddle(list);

    //HorizontalSlider* slider = new HorizontalSlider(Rect2{200, 30, 1000, 100}, 10);
    // slider->ApplyStyle(new ProgressHorizontalSliderStyle());
    // slider->ValueChanged.Connect(ScrollResponse);

    // window_->Attach(slider);

    // ScrollingVerticalList* list2 = new ScrollingVerticalList(Rect2{200, 400, 500, 500});
    
    // widget = new ContainerWidget(Rect2{100, 400, 0, 0});
    // widget->ApplyStyle(new FilledStyle(Color(0.f, 0.f, 1.f, 1.f)));
    // list2->InsertItem(widget);

    // widget = new ContainerWidget(Rect2{100, 400, 0, 0});
    // widget->ApplyStyle(new FilledStyle(Color(0.f, 1.f, 0.f, 1.f)));
    // list2->InsertItem(widget);

    // window_->Attach(list2);

    MenuBar* menu_bar = new MenuBar(window_);
    window_->AttachInTop(menu_bar);

    Menu* menu1 = new Menu(300, "menu1");
    menu1->InsertItem("menu1: item1");
    menu1->InsertItem("menu1: item2");
    menu1->InsertItem("menu1: item3");
    menu1->InsertItem("menu1: item4");
    menu1->InsertItem("menu1: item5");
    menu1->InsertItem("menu1: item6");
    menu1->InsertItem("menu1: item7");
    menu1->InsertItem("menu1: item8");
    menu_bar->InsertMenu(menu1);
    // window_->AttachInLeft(menu1);

    Menu* menu2 = new Menu(300, "menu2");
    menu2->InsertItem("menu2: item1");
    menu2->InsertItem("menu2: item2");
    menu2->InsertItem("menu2: item3");
    menu2->InsertItem("menu2: item4");
    menu2->InsertItem("menu2: item5");
    menu2->InsertItem("menu2: item6");
    menu2->InsertItem("menu2: item7");
    menu2->InsertItem("menu2: item8");
    menu_bar->InsertMenu(menu2);
    // window_->AttachInRight(menu2);
}

Application::~Application() {
    assert(event_manager_    != nullptr);
    assert(log_manager_      != nullptr);
    assert(resource_manager_ != nullptr);
    assert(render_window_    != nullptr);
 
    delete render_window_;

    resource_manager_->Release();
    event_manager_->Release();
    log_manager_->Release();
}

void Application::Run() {
    while (render_window_->IsOpen()) {
        render_window_->PumpEvents();

        event_manager_->DispatchEvents();

        render_window_->Clear(Color(1.f, 1.f, 1.f, 1.f));
        window_->OnRenderToWindow(render_window_);
        render_window_->Display();
    }
}