#include "Input.hpp"

Input::Input(Window* window)
    : native_window_{nullptr},
      event_dispatcher_{nullptr},
      position_{},
      button_{MouseButton::kNoneButton},
      button_pressed_{false} {
    assert(window != nullptr);

    native_window_ = window->GetNativeWindow();
    assert(native_window_ != nullptr);

    event_dispatcher_ = EventDispatcher::GetEventDispatcher();
    assert(event_dispatcher_ != nullptr);
}

Input::~Input() {}

bool Input::PumpEvents() {
    assert(native_window_ != nullptr);
    assert(event_dispatcher_ != nullptr);

    bool result = true;

    sf::Event event{};
    while (native_window_->pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed: {
                native_window_->close();
                result = false;
            } break;

            case sf::Event::MouseButtonPressed: {
                SendMouseButtonEvent(event);
            } break;

            case sf::Event::MouseButtonReleased: {
                SendMouseButtonEvent(event);
            } break;

            case sf::Event::MouseMoved: {
                SendMouseMoveEvent(event);
            } break;

            case sf::Event::KeyPressed: {
                SendKeyEvent(event);
            } break;

            case sf::Event::KeyReleased: {
                SendKeyEvent(event);
            } break;

            default: {}
        }
    }

    return result;
}

void Input::SendMouseButtonEvent(const sf::Event& event) {
    assert(event_dispatcher_ != nullptr);

    if (event.mouseButton.x < 0 || event.mouseButton.y < 0) {
        return;
    }

    position_.x = event.mouseButton.x;
    position_.y = event.mouseButton.y;

    button_         = GetButton(event);
    button_pressed_ = event.type == sf::Event::MouseButtonPressed;

    if (button_pressed_) {
        event_dispatcher_->SendEvent<MouseButtonPressEvent>(position_, button_, button_pressed_);
    } else {
        event_dispatcher_->SendEvent<MouseButtonReleaseEvent>(position_, button_, button_pressed_);
    }
}

void Input::SendMouseMoveEvent(const sf::Event& event) {
    assert(event_dispatcher_ != nullptr);

    if (event.mouseMove.x < 0 || event.mouseMove.y < 0) {
        return;
    }

    position_.x = event.mouseMove.x;
    position_.y = event.mouseMove.y;

    event_dispatcher_->SendEvent<MouseMoveEvent>(position_, button_, button_pressed_);
}

void Input::SendKeyEvent(const sf::Event& event) {
    assert(event_dispatcher_ != nullptr);

    Key  key     = GetKey(event);
    bool alt     = event.key.alt; 
    bool control = event.key.control;
    bool shift   = event.key.shift;
    bool system  = event.key.system;

    if (event.type == sf::Event::KeyPressed) {
        event_dispatcher_->SendEvent<KeyPressEvent>(key, alt, control, shift, system);
    } else {
        event_dispatcher_->SendEvent<KeyReleaseEvent>(key, alt, control, shift, system);
    }
}

MouseButton Input::GetButton(const sf::Event& event) {
    switch (event.mouseButton.button) {
        case sf::Mouse::Button::Left:     return MouseButton::kLeftButton;
        case sf::Mouse::Button::Right:    return MouseButton::kRightButton;
        case sf::Mouse::Button::Middle:   return MouseButton::kMiddleButton;
        case sf::Mouse::Button::XButton1: return MouseButton::kX1Button;
        case sf::Mouse::Button::XButton2: return MouseButton::kX2Button;
        default:                          return MouseButton::kNoneButton;
    }
    
    return MouseButton::kNoneButton;
}

Key Input::GetKey(const sf::Event& event) {
    return Key::kNoneKey;
}
