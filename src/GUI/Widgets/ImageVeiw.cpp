#include "GUI/Widgets/ImageVeiw.hpp"

ImageVeiw::ImageVeiw(Sprite* sprite, const Vector2u& position)
    : Widget{sprite->GetSize(), position},
      sprite_{sprite} {
    assert(sprite_ != nullptr);

    sprite_->SetPosition(position);
}

ImageVeiw::~ImageVeiw() {
    delete sprite_;
}

void ImageVeiw::OnRender(Renderer* renderer) const {
    assert(sprite_  != nullptr);
    assert(renderer != nullptr);

    renderer->RenderSprite(sprite_);
}
