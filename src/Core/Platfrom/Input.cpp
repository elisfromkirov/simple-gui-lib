#include "Core/EventManager/EventManager.hpp"
#include "Core/Platform/Input.hpp"
#include "Core/Platform/InputEvent.hpp"

Mouse::Mouse() 
    : position_{0, 0},
      pressed_button_{kNoneButton},
      pressed_{false},

Mouse::~Mouse() {}

void Mouse::Update(const NativeEvent& event) {
    EventManager* event_manager = EventManager::GetInstance();
    assert(event_manager != nullptr);

    switch (event.type) {
        case sf::Event::MouseButtonPressed: {
            Vector2i old_position{position_};

            position_.x = event.mouseButton.x;
            position_.y = event.mouseButton.y;

            pressed_button_ = Mouse::MapButton(event);
            pressed_        = true;

            event_manager->PostEvent<MouseButtonPressEvent>(position_, old_position,
                                                            pressed_button_);
        } break;
        case sf::Event::MouseButtonReleased: {
            Vector2i old_position{position_};

            position_.x = event.mouseButton.x;
            position_.y = event.mouseButton.y;

            pressed_button_ = Input::GetButton(event);
            pressed_        = false;
            
            event_manager->PostEvent<MouseButtonReleaseEvent>(position_, old_position,
                                                              pressed_button_);
        } break;
        case sf::Event::MouseMoved: {
            Vector2i old_position{position_};

            position_.x = event.mouseMove.x;
            position_.y = event.mouseMove.y;
          
            event_manager->PostEvent<MouseMoveEvent>(position_, old_position, pressed_button_,
                                                     pressed_);
        } break;
        default: {}
    }
}

MouseButton Mouse::MapButton(const NativeEvent& event) {
    switch (event.mouseButton.button) {
        case sf::Mouse::Button::Left: {
            return MouseButton::kLeftButton;
        } break;
        case sf::Mouse::Button::Right: {
            return MouseButton::kRightButton;
        } break;
        case sf::Mouse::Button::Middle: {
            return MouseButton::kMiddleButton;
        } break;
        case sf::Mouse::Button::XButton1: {
            return MouseButton::kX1Button;
        } break;
        case sf::Mouse::Button::XButton2: {
            return MouseButton::kX2Button;
        } break;
        default: {}
    }
    
    return MouseButton::kNoneButton;
}

Keyboard::Keyboard()
    : key_{kNoneKey},
      alt_{false},
      control_{false},
      shift_{false},
      system_{false} {}

Keyboard::~Keyboard() {}

void Keyboard::Update(const NativeEvent& event) {
    EventManager* event_manager = EventManager::GetInstance();
    assert(event_manager != nullptr);

    switch (event.type) {
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

Key Keyboard::MapKey(const sf::Event& event) {
    return kNoneKey;
}