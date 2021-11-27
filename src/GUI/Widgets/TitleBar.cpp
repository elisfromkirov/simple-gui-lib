#include "Core/EventManager/EventManager.hpp"
#include "Core/ResourceManager/Resources.hpp"
#include "Core/ResourceManager/ResourceManager.hpp"
#include "Core/Platform/InputEvent.hpp"
#include "GUI/Events/WidgetEvent.hpp"
#include "GUI/Styles/DefaultStyle.hpp"
#include "GUI/Widgets/TitleBar.hpp"

TitleBar::TitleBar(Widget* titled_widget, const std::string& title) 
    : ContainerWidget{Vector2u{titled_widget->GetSize().x, kDefaultHeight}, titled_widget->GetPosition()},
      titled_widget_{titled_widget},
      title_{nullptr},
      close_button_{nullptr} {
    ResourceManager* resource_manager = ResourceManager::GetInstance();
    assert(resource_manager != nullptr);

    Icon* icon = new Icon(resource_manager->LoadTexture(kCloseImage));
    icon->Move(position_ + Vector2i{static_cast<int32_t>(kDefaultHeight - icon->GetSize().x) / 2,
                                    static_cast<int32_t>(kDefaultHeight - icon->GetSize().x) / 2});

    close_button_ = new Button(icon->GetSize());
    close_button_->Move(icon->GetPosition());
    close_button_->ApplyStyle(new SystemButtonStyle());

    close_button_->Attach(icon);
    close_button_->Clicked.Connect<TitleBar>(this, &TitleBar::CloseTitledWidget);

    title_ = new Label(title, resource_manager->LoadFont(kMediumFont));
    title_->SetCharSize(kDefaultCharSize);
    title_->SetTextColor(Color(1.f, 1.f, 1.f, 1.f));
    title_->Move(position_ + Vector2i{static_cast<int32_t>(kDefaultHeight), 
                                     static_cast<int32_t>(kDefaultHeight - kDefaultCharSize) / 3});

    Attach(close_button_);
    Attach(title_);

    ApplyStyle(new TitleBarStyle());
}

TitleBar::~TitleBar() {}

bool TitleBar::OnMouseButtonPressEvent(const MouseButtonPressEvent* event) {
    assert(event != nullptr);

    if (!HitTest(event->GetMousePosition())) {
        return false;
    }

    pressed_ = true;

    EventManager* event_manager = EventManager::GetInstance();
    assert(event_manager != nullptr);

    event_manager->PostEvent<MouseCaptureEvent>(this);

    return true;
}

bool TitleBar::OnMouseButtonReleaseEvent(const MouseButtonReleaseEvent* event) {
    assert(event != nullptr);

    if (!pressed_) {
        return false;
    }

    pressed_ = false;

    EventManager* event_manager = EventManager::GetInstance();
    assert(event_manager != nullptr);

    event_manager->PostEvent<MouseCaptureLostEvent>(this);

    if (HitTest(event->GetMousePosition())) {
        return true;
    }

    return true;
}

bool TitleBar::OnMouseMoveEvent(const MouseMoveEvent* event) {
    assert(event != nullptr);

    if (pressed_) {
        EventManager* event_manager = EventManager::GetInstance();
        assert(event_manager != nullptr);

        Vector2i position{position_ + event->GetMousePosition() - event->GetOldMousePosition()};
        event_manager->PostEvent<MoveEvent>(titled_widget_, position, position_);
    }

    return false;
}

void TitleBar::CloseTitledWidget() {
    EventManager* event_manager = EventManager::GetInstance();
    assert(event_manager != nullptr);

    event_manager->PostEvent<CloseEvent>(titled_widget_);
}