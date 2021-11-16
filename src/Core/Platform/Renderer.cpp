#include "Core/Platform/Text.hpp"
#include "Core/Platform/Image.hpp"
#include "Core/Platform/Renderer.hpp"
#include "Core/Platform/RenderTexture.hpp"
#include "Core/Platform/RenderWindow.hpp"

Renderer::Renderer(RenderWindow* window)
    : render_target_{nullptr} {
    assert(window != nullptr);

    render_target_ = window;
    assert(render_target_ != nullptr);
}

Renderer::~Renderer() {}

void Renderer::Clear(const Color& color) {
    assert(render_target_ != nullptr);

    render_target_->Clear(color);
}

void Renderer::Display() {
    assert(render_target_ != nullptr);

    render_target_->Display();
}

void Renderer::CopyTexture(RenderTexture* render_texture, const Vector2i& position) {
    assert(render_target_ != nullptr);
    assert(render_texture != nullptr);

    sf::RenderTarget* native_target = render_target_->GetNativeRenderTarget();
    assert(native_target  != nullptr);

    sf::Sprite sprite(render_texture->GetCapture());
    sprite.setPosition(position.x, position.y);

    native_target->draw(sprite);
}

void Renderer::RenderText(const Text& text) {
    assert(render_target_ != nullptr);

    sf::RenderTarget* native_target = render_target_->GetNativeRenderTarget();
    assert(native_target  != nullptr);

    native_target->draw(text.GetNativeText());
}

void Renderer::RenderImage(const Image& image) {
    assert(render_target_ != nullptr);

    sf::RenderTarget* native_target = render_target_->GetNativeRenderTarget();
    assert(native_target  != nullptr);

    native_target->draw(image.GetNativeImage());
}

void Renderer::RenderRectangle(const Vector2i& position, const Vector2u& size, const Color& color) {
    assert(render_target_ != nullptr);

    sf::RectangleShape shape(sf::Vector2f(size.x, size.y));
    shape.setPosition(sf::Vector2f(position.x, position.y));
    shape.setFillColor(sf::Color(static_cast<uint8_t>(color.red   * 255.f),
                                 static_cast<uint8_t>(color.green * 255.f),
                                 static_cast<uint8_t>(color.blue  * 255.f),
                                 static_cast<uint8_t>(color.alpha * 255.f)));

    sf::RenderTarget* native_target = render_target_->GetNativeRenderTarget();
    assert(native_target  != nullptr);

    native_target->draw(shape);
}

IRenderTarget* Renderer::GetRenderTarget() {
    assert(render_target_ != nullptr);

    return render_target_;
}

void Renderer::SetRenderTarget(IRenderTarget* render_target) {
    assert(render_target_ != nullptr);
    assert(render_target  != nullptr);

    render_target_ = render_target;
}
