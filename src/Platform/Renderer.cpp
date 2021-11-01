#include "Renderer.hpp"

Renderer::Renderer(Window* window) 
    : native_window_{nullptr} {
    assert(window != nullptr);

    native_window_ = window->GetNativeWindow();
    assert(native_window_ != nullptr);
}

Renderer::~Renderer() {}

void Renderer::Clear(const Color& color) {
    assert(native_window_ != nullptr);

    sf::Color native_color{static_cast<sf::Uint8>(color.red   * 255.f),
                           static_cast<sf::Uint8>(color.green * 255.f),
                           static_cast<sf::Uint8>(color.blue  * 255.f),
                           static_cast<sf::Uint8>(color.alpha * 255.f)};

    native_window_->clear(native_color);
}

void Renderer::Present() {
    assert(native_window_ != nullptr);

    native_window_->display();
}

void Renderer::RenderText(Text* text, const Vector2u& position) {
    assert(native_window_ != nullptr);
    assert(text           != nullptr);

    text->SetPosition(position);
    native_window_->draw(text->GetNativeText());
}

void Renderer::RenderSprite(Sprite* sprite, const Vector2u& position) {
    assert(native_window_ != nullptr);
    assert(sprite         != nullptr);

    sprite->SetPosition(position);
    native_window_->draw(sprite->GetNativeSprite());
}

void Renderer::RenderRectangle(const Vector2u& position, const Vector2u& size, const Color& color) {
    assert(native_window_ != nullptr);

    static sf::RectangleShape native_shape;

    native_shape.setSize     (sf::Vector2f(size.x,     size.y    ));
    native_shape.setPosition (sf::Vector2f(position.x, position.y));
    native_shape.setFillColor(sf::Color(static_cast<sf::Uint8>(color.red   * 255.f),
                                        static_cast<sf::Uint8>(color.green * 255.f),
                                        static_cast<sf::Uint8>(color.blue  * 255.f),
                                        static_cast<sf::Uint8>(color.alpha * 255.f)));

    native_window_->draw(native_shape);
}
