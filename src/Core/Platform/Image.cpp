#include "Core/Platform/Image.hpp"

Image::Image(const Texture& texture, const Vector2i& position)
    : sprite_{texture.GetNativeTexture()}, 
      size_{texture.GetNativeTexture().getSize().x, texture.GetNativeTexture().getSize().y} {
    sprite_.setPosition(sf::Vector2f(position.x, position.y));    
}

Image::Image(const RenderTexture* texture, const Vector2i& position)
    : sprite_{texture->GetImage()},
      size_{texture->GetSize()} {
    sprite_.setPosition(sf::Vector2f(position.x, position.y));
}

Image::Image(const RenderTexture& texture, const Vector2i& position)
    : sprite_{texture.GetImage()},
      size_{texture.GetSize()} {
    sprite_.setPosition(sf::Vector2f(position.x, position.y));
}

Image::~Image() {}

void Image::SetPosition(const Vector2i& position) {
    sprite_.setPosition(sf::Vector2f(position.x, position.y));
}

Vector2u Image::GetSize() const {
    return size_;
}

const NativeImage& Image::GetNativeImage() const {
    return sprite_;
}