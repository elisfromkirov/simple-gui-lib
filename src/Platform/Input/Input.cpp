#include "EventDispatcher.hpp"
#include "Input.hpp"
#include "KeyboardEvent.hpp"
#include "MouseEvent.hpp"
#include "QuitEvent.hpp"

Vector2<int32_t> GetMouseCoordinates(const SDL_Event& event) {
    return Vector2<int32_t>{event.button.x, event.button.y};
}

uint32_t GetPressedButton(const SDL_Event& event) {
    switch (event.button.button) {
        case SDL_BUTTON_LEFT:   return kButtonLeft;
        case SDL_BUTTON_RIGHT:  return kButtonRight;
        case SDL_BUTTON_MIDDLE: return kButtonMiddle;
        case SDL_BUTTON_X1:     return kButtonX1;
        case SDL_BUTTON_X2:     return kButtonX2;
    }

    return kNoneButon;
}

bool GetMouseButtonState(const SDL_Event& event) {
    return event.button.state == SDL_PRESSED;
}

void SendMouseButtonEvent(const SDL_Event& event) {
    EventDispatcher* dispatcher = EventDispatcher::GetEventDispatcher();
    assert(dispatcher != nullptr);

    dispatcher->SendEvent<MouseButtonEvent>(GetMouseCoordinates(event), 
                                            GetPressedButton(event),
                                            GetMouseButtonState(event));
}

void SendMouseMoveEvent(const SDL_Event& event) {
    EventDispatcher* dispatcher = EventDispatcher::GetEventDispatcher();
    assert(dispatcher != nullptr);

    dispatcher->SendEvent<MouseButtonEvent>(GetMouseCoordinates(event), 
                                            GetPressedButton(event),
                                            GetMouseButtonState(event));
}

uint32_t GetKey(const SDL_Event& event) {
    return static_cast<uint32_t>(event.key.keysym.sym);
}

bool GetKeyState(const SDL_Event& event) {
    return event.key.state == SDL_PRESSED;
}

void SendKeyboardEvent(const SDL_Event& event) {
    EventDispatcher* dispatcher = EventDispatcher::GetEventDispatcher();
    assert(dispatcher != nullptr);

    dispatcher->SendEvent<KeyboardEvent>(GetKey(event), GetKeyState(event));
}

void SendQuitEvent(const SDL_Event& event) {
    EventDispatcher* dispatcher = EventDispatcher::GetEventDispatcher();
    assert(dispatcher);

    dispatcher->SendEvent<QuitEvent>();
}

void PumpEvents() {
    SDL_Event event{};
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_MOUSEBUTTONUP:   SendMouseButtonEvent(event); break;
            case SDL_MOUSEBUTTONDOWN: SendMouseButtonEvent(event); break;
            case SDL_MOUSEMOTION:     SendMouseMoveEvent  (event); break;
            case SDL_KEYUP:           SendKeyboardEvent   (event); break;
            case SDL_KEYDOWN:         SendKeyboardEvent   (event); break;
            case SDL_QUIT:            SendQuitEvent       (event); break;
        }
    }
}
