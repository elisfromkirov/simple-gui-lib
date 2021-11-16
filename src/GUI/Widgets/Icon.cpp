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

    renderer->RenderImage(image_);
}

bool Icon::OnMoveEvent(const MoveEvent* event) {
    assert(event != nullptr);

    position_ = event->GetNewPosition();

    image_.SetPosition(position_);

    return true;
}

bool Icon::OnResizeEvent(const ResizeEvent* event) {
    assert(event != nullptr);

    return true;
}
