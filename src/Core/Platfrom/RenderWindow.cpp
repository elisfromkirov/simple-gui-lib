#include "Core/Platform/RenderWindow.hpp"

RenderWindow::RenderWindow(const std::string& title, const Vector2u& size)
    : window_{sf::VideoMode(size.x, size.y), title},
      size_{size} {}

RenderWindow::~RenderWindow() {}

void RenderWindow::Clear(const Color& color) {
    window_.clear(NativeColorFromColor(color));
}

void RenderWindow::Display() {
    window_.display();
}

void RenderWindow::RenderText(const Text& text) {
    window_.draw(text.GetNativeText());
}

void RenderWindow::RenderImage(const Image& image) {
    window_.draw(text.GetNativeImage());
}
    
void RenderWindow::RenderRectangle(const Rectangle& rectangle) {
    window_.draw(text.GetNativeRectangle());
}

void PumpEvents() {
    sf::Event event{};
    while (window_->pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed: {
                window_.close();
            } break;
            case sf::Event::MouseButtonPressed:
            case sf::Event::MouseButtonReleased:
            case sf::Event::MouseMoved: {
                mouse_.Update(event);
            } break;
            case sf::Event::KeyPressed:
            case sf::Event::KeyReleased: {
                keyboard_.Update();
            } break;
            default: {}
        }
    }
}

bool RenderWindow::IsOpen() const {
    return window_.isOpen();
}

void RenderWindow::Close() {
    window_.close();
}