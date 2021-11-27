#include "GUI/Widgets/Icon.hpp"

Icon::Icon(const Texture& texture, const Vector2i& position)
    : Widget{},
      image_{texture} {
    size_ = image_.GetSize();

    position_ = position;
}

Icon::~Icon() {}

void Icon::OnRender(RenderTexture* texture) {
    assert(texture != nullptr);

    RenderStyles(texture);

    image_.SetPosition(MapPositionToParent());
    texture->RenderImage(image_);
}

void Icon::Resize(const Vector2u& size) {}

void Icon::Move(const Vector2i& position) {
    position_ = position;
}