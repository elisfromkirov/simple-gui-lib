#include "Window.hpp"

const Vector2<uint32_t> Window::kDefaultPosition{0, 0};

const Vector2<uint32_t> Window::kDefaultSize{800, 600};

Window::Window(const char* title)
    : Window{title, kDefaultPosition, kDefaultSize} {}

Window::Window(const char* title, uint32_t x_pos, uint32_t y_pos, uint32_t width, uint32_t height)
    : Window{title, Vector2<uint32_t>{x_pos, y_pos}, Vector2<uint32_t>{width, height}} {}

Window::Window(const char* title, Vector2<uint32_t> position, Vector2<uint32_t> size)
    : window_{nullptr}, title_{title}, pos_{position}, size_{size} {
    window_ = SDL_CreateWindow(title, pos_.x, pos_.y, size.y, size.y, SDL_WINDOW_SHOWN);
    assert(window_ != nullptr);
}

Window::~Window() {
    assert(window_ != nullptr);

    SDL_DestroyWindow(window_);
}

void* Window::GetNativeWindow() {
    assert(window_ != nullptr);

    return window_;
}

void* Window::GetRenderTarget() {
    return nullptr;
}
