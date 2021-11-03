#include "Core/ResourceManager/ResourceManager.hpp"
#include "GUI/Widgets/ImageWidget.hpp"

ImageWidget::ImageWidget(const char* image_name)
    : Widget{Vector2u()},
      sprite_{nullptr} {
    sprite_ = ResourceManager::GetResourceManager()->LoadSprite(image_name);
    assert(sprite_ != nullptr);

    size_ = sprite_->GetSize();
}

ImageWidget::ImageWidget(Sprite* sprite)
    : Widget{sprite->GetSize()},
      sprite_{sprite} {
    assert(sprite_ != nullptr);
}

ImageWidget::~ImageWidget() {
    assert(sprite_ != nullptr);

    ResourceManager::GetResourceManager()->FreeSprite(sprite_);
}

void ImageWidget::OnRender(Renderer* renderer) const {
    assert(sprite_  != nullptr);
    assert(renderer != nullptr);

    renderer->RenderSprite(sprite_);
}
