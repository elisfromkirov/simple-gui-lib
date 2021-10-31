#include "Renderer.hpp"

Renderer::Renderer(Window* window) 
    : native_window_{nullptr} {
    assert(window != nullptr);

    native_window_ = window->GetNativeWindow();
    assert(native_window_ != nullptr);
}

Renderer::~Renderer() {}

void Renderer::Clear() {
    assert(native_window_ != nullptr);
    
    native_window_->clear();
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
