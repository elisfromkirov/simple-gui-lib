#include "Core/EventManager/EventManager.hpp"
#include "Core/Platform/Input.hpp"
#include "Core/Platform/RenderWindow.hpp"

Input::Input(RenderWindow* window)
    : window_{nullptr},
      position_{0, 0},
      pressed_button_{kNoneButton},
      pressed_{false},
      key_{kNoneKey},
      alt_{false},
      control_{false},
      shift_{false},
      system_{false} {
    assert(window != nullptr);

    window_ = window->GetNativeWindow();
    assert(window_ != nullptr);
}

Input::~Input() {}

bool Input::PumpEvents() {
    assert(window_ != nullptr);

    EventManager* event_manager = EventManager::GetInstance();
    assert(event_manager != nullptr);

    sf::Event event{};
    while (window_->pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed: {
                window_->close();
            } return false;
            case sf::Event::MouseButtonPressed: {
                position_.x = event.mouseButton.x;
                position_.y = event.mouseButton.y;

                pressed_button_ = Input::GetButton(event);
                pressed_        = true;

                event_manager->PostEvent<MouseButtonPressEvent>(position_, pressed_button_);
            } break;
            case sf::Event::MouseButtonReleased: {
                position_.x = event.mouseButton.x;
                position_.y = event.mouseButton.y;

                pressed_button_ = Input::GetButton(event);
                pressed_        = false;
            
                event_manager->PostEvent<MouseButtonReleaseEvent>(position_, pressed_button_);
            } break;
            case sf::Event::MouseMoved: {
                position_.x = event.mouseMove.x;
                position_.y = event.mouseMove.y;
            
                event_manager->PostEvent<MouseMoveEvent>(position_, pressed_button_, pressed_);
            } break;
            case sf::Event::KeyPressed: {
                key_     = Input::GetKey(event);
                alt_     = event.key.alt; 
                control_ = event.key.control;
                shift_   = event.key.shift;
                system_  = event.key.system;

                event_manager->PostEvent<KeyPressEvent>(key_, alt_, control_, shift_, system_);
            } break;
            case sf::Event::KeyReleased: {
                key_     = Input::GetKey(event);
                alt_     = event.key.alt; 
                control_ = event.key.control;
                shift_   = event.key.shift;
                system_  = event.key.system;
                event_manager->PostEvent<KeyReleaseEvent>(key_, alt_, control_, shift_, system_);
            } break;
            default: {}
        }
    }

    return true;
}

MouseButton Input::GetButton(const sf::Event& event) {
    return kNoneButton;
}

Key Input::GetKey(const sf::Event& event) {
    return kNoneKey;
}
