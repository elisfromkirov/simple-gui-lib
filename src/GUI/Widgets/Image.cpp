#include "GUI/Widgets/Image.hpp"

Image::Image(const char* imagename, const Vector2i& position)
    : sprite_{imagename} {
    size_ = sprite_.GetSize();
    position_ = position;
}

Image::~Image() {}

void Image::Render(Renderer* renderer) const {
    assert(renderer != nullptr);

    renderer->RenderSprite(sprite_);
}

void Image::Resize(const Vector2u& size) {}

void Image::Move(const Vector2i& displacement) {
    position_ += displacement;
    
    sprite_.SetPosition(position_);
}
