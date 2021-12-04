#include "Core/Platform/RenderTexture.hpp"
#include "GUI/Widgets/Icon.hpp"

Icon::Icon(const Texture& texture)
    : Widget{},
      image_{texture} {
    rect_.size     = image_.GetSize();
}

Icon::~Icon() {}

void Icon::OnRender(RenderTexture* texture) {
    assert(texture != nullptr);
  
    image_.SetPosition(MapPositionToParent());
    texture->RenderImage(image_);
}