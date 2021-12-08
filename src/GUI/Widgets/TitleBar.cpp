#include "Core/EventManager/EventManager.hpp"
#include "Core/ResourceManager/Resources.hpp"
#include "Core/ResourceManager/ResourceManager.hpp"
#include "Core/Platform/InputEvent.hpp"
#include "Core/Platform/RenderTexture.hpp"
#include "GUI/Events/WidgetEvent.hpp"
#include "GUI/Styles/ButtonStyle.hpp"
#include "GUI/Styles/FilledStyle.hpp"
#include "GUI/Widgets/TitleBar.hpp"

TitleBar::TitleBar(Widget* titled_widget, const std::string& title) 
    : ContainerWidget{Rect2{titled_widget->GetSize().x, kIconSize * 2, 
                            titled_widget->GetPosition().x, titled_widget->GetPosition().y}},
      titled_widget_{titled_widget},
      title_{nullptr},
      close_button_{nullptr} {
    assert(titled_widget_ != nullptr);

    close_button_ = new Button(Rect2(kIconSize * 4 / 3 , kIconSize * 4 / 3));
    close_button_->Move(rect_.position + Vector2i(kIconSize / 3, kIconSize / 3));
    close_button_->ApplyStyle(new LightButtonStyle(kCloseImage));
    close_button_->Clicked.Connect<TitleBar>(this, &TitleBar::CloseTitledWidget);
    Attach(close_button_);

    title_ = new Label(title, ResourceManager::GetInstance()->LoadFont(kMediumFont));
    title_->Move(rect_.position + Vector2i(kIconSize * 2, kIconSize / 3));
    title_->SetCharSize(kIconSize);
    title_->SetTextColor(Color(0.f, 0.f, 0.f, 1.f));
    Attach(title_);

    ApplyStyle(new FilledStyle(FilledStyle::kTitleBar));
}

TitleBar::~TitleBar() {}

bool TitleBar::OnMouseButtonPressEvent(const MouseButtonPressEvent* event) {
    assert(event != nullptr);

    if (!HitTest(event->GetMousePosition())) {
        return false;
    }
    pressed_ = true;

    EventManager::GetInstance()->PostEvent<MouseCaptureInEvent>(this);

    return true;
}

bool TitleBar::OnMouseButtonReleaseEvent(const MouseButtonReleaseEvent* event) {
    assert(event != nullptr);

    if (!pressed_) {
        return false;
    }
    pressed_ = false;

    EventManager::GetInstance()->PostEvent<MouseCaptureOutEvent>(this);

    if (HitTest(event->GetMousePosition())) {
        return true;
    }

    return true;
}

bool TitleBar::OnMouseMoveEvent(const MouseMoveEvent* event) {
    assert(event != nullptr);

    if (pressed_) {
        Vector2i position{rect_.position + event->GetMousePosition() - event->GetOldMousePosition()};

        EventManager::GetInstance()->PostEvent<MoveEvent>(titled_widget_, position, rect_.position);
    }

    return false;
}

void TitleBar::CloseTitledWidget() {
    assert(titled_widget_ != nullptr);

    EventManager::GetInstance()->PostEvent<CloseEvent>(titled_widget_);
}