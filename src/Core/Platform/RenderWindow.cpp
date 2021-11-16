#include "Core/Platform/RenderWindow.hpp"

RenderWindow::RenderWindow(const std::string& title, const Vector2u& size)
    : window_{sf::VideoMode(size.x, size.y), title},
      size_{size} {}

RenderWindow::~RenderWindow() {}

void RenderWindow::Clear(const Color& color) {
    window_.clear(sf::Color{static_cast<uint8_t>(color.red   * 255.f),
                            static_cast<uint8_t>(color.green * 255.f),
                            static_cast<uint8_t>(color.blue  * 255.f),
                            static_cast<uint8_t>(color.alpha * 255.f)});
}

void RenderWindow::Display() {
    window_.display();
}

NativeRenderTarget* RenderWindow::GetNativeRenderTarget() {
    return &window_;
}

bool RenderWindow::IsOpen() const {
    return window_.isOpen();
}

void RenderWindow::Close() {
    window_.close();
}

NativeWindow* RenderWindow::GetNativeWindow() {
    return &window_;
}
