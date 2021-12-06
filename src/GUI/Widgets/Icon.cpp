#include "Core/Platform/RenderTexture.hpp"
#include "GUI/Widgets/Icon.hpp"

Icon::Icon(const Texture& texture)
    : Widget{},
      image_{texture} {
    rect_.size = image_.GetSize();
}

Icon::~Icon() {}

void Icon::OnRender(IRenderTarget* render_target) {
    assert(render_target != nullptr);

    image_.SetPosition(MapPositionToParent());
    render_target->RenderImage(image_);
}