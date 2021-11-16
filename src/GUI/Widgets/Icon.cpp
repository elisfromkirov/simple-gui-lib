#include "GUI/Widgets/Icon.hpp"

Icon::Icon(const Texture& texture, const Vector2i& position)
    : Widget{},
      image_{texture} {
    size_ = image_.GetSize();

    position_ = position;
    image_.SetPosition(position_);
}

Icon::~Icon() {}

void Icon::OnRender(Renderer* renderer) {
    assert(renderer != nullptr);

    ApplyStyles(renderer);

    renderer->RenderImage(image_);
}

void Icon::Resize(const Vector2u& size) {}

void Icon::Move(const Vector2i& position) {
    position_ = position;
    image_.SetPosition(position);
}