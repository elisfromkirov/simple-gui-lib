#include "Application/Tools/Tools.hpp"
#include "Core/Platform/Rectangle.hpp"
#include "Core/Platform/RenderTexture.hpp"
#include "Core/ResourceManager/Resources.hpp"

#include <cstdio>

Pencil::Pencil() {}

Pencil::~Pencil() {}

void Pencil::BeginDraw(RenderTexture* canvas, const Vector2i& position) {
    assert(canvas != nullptr);

    printf("%s\n", __func__);
}

void Pencil::Draw(RenderTexture* canvas, const Vector2i& position, const Vector2i& old_position) {
    assert(canvas != nullptr);

    printf("%s\n", __func__);
}

void Pencil::EndDraw(RenderTexture* canvas, const Vector2i& position) {
    assert(canvas != nullptr);

    printf("%s\n", __func__);
}

const char* Pencil::GetIconFileName() const {
    return kPencilImage;
}