#include "Platform/Window.hpp"

const Vector2u Window::kDefaultSize{1600, 1200};

Window::Window(const char* title)
    : native_window_{sf::VideoMode(kDefaultSize.x, kDefaultSize.y), title, /* sf::Style::None */},
      title_{title},
      size_{kDefaultSize},
      position_{} {
    sf::Vector2i position{native_window_.getPosition()};
    position_.x = position.x;
    position_.y = position.y;
}

Window::Window(const char* title, const Vector2u& size, const Vector2i& position)
    : native_window_{sf::VideoMode(size.x, size.y), title},
      title_{title},
      size_{size},
      position_{position} {
    native_window_.setPosition(sf::Vector2i{position_.x, position_.y});
}

Window::~Window() {}

bool Window::IsOpen() const {
    return native_window_.isOpen();
}

void Window::Close() {
    native_window_.close();
}

NativeWindow* Window::GetNativeWindow() {
    return &native_window_;
}

const Vector2u& Window::GetSize() const {
    return size_;
}
