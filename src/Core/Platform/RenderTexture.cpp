#include "Core/Platform/RenderTexture.hpp"

RenderTexture::RenderTexture(const Vector2u& size)
    : texture_{},
      size_{size} {
    texture_.create(size.x, size.y);
}

RenderTexture::~RenderTexture() {}

void RenderTexture::Clear(const Color& color) {
    texture_.clear(sf::Color{static_cast<uint8_t>(color.red   * 255.f),
                             static_cast<uint8_t>(color.green * 255.f),
                             static_cast<uint8_t>(color.blue  * 255.f),
                             static_cast<uint8_t>(color.alpha * 255.f)});
}

void RenderTexture::Display() {
    texture_.display();
}

NativeRenderTarget* RenderTexture::GetNativeRenderTarget() {
    return &texture_;
}

void RenderTexture::SetSize(const Vector2u& size) {
    texture_.~RenderTexture();
    new(&texture_) sf::RenderTexture();
    texture_.create(size.x, size.y);

    size_ = size;
}

const Vector2u& RenderTexture::GetSize() const {
    return size_;
}

const NativeImage& RenderTexture::GetCapture() {
    capture_.setTexture(texture_.getTexture());
    
    return capture_;
}