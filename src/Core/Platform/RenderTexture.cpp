#include "Core/Platform/Color.hpp"
#include "Core/Platform/Image.hpp"
#include "Core/Platform/Rectangle.hpp"
#include "Core/Platform/RenderTexture.hpp"
#include "Core/Platform/Text.hpp"

RenderTexture::RenderTexture(const Vector2u& size)
    : texture_{},
      sprite_{} {
    texture_.create(size.x, size.y);
}

RenderTexture::~RenderTexture() {}

void RenderTexture::Clear(const Color& color) {
    texture_.clear(NativeColorFromColor(color));
}

void RenderTexture::Display() {
    texture_.display();
}

void RenderTexture::RenderText(const Text& text) {
    texture_.draw(text.GetNativeText());
}

void RenderTexture::RenderImage(const Image& image) {
    texture_.draw(image.GetNativeImage());
}
    
void RenderTexture::RenderRectangle(const Rectangle& rectangle) {
    texture_.draw(rectangle.GetNativeRectangle());
}

const NativeImage& RenderTexture::GetImage() {
    sprite_.setTexture(texture_.getTexture());

    return sprite_;
}

Vector2u RenderTexture::GetSize() {
    sf::Vector2u size{texture_.getSize()};

    return Vector2u{size.x, size.y};
}