#include "ImageWidget.hpp"

ImageWidget::ImageWidget(Sprite* sprite, const Vector2u& position)
    : Widget{sprite->GetSize(), position},
      sprite_{sprite} {
    assert(sprite_ != nullptr);
}

ImageWidget::~ImageWidget() {}

void ImageWidget::OnRender(Renderer* renderer) {
    assert(sprite_  != nullptr);
    assert(renderer != nullptr);
    
    renderer->RenderSprite(sprite_, position_);
}
