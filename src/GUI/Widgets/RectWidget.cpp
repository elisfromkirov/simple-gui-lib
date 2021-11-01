#include "RectWidget.hpp"

RectWidget::RectWidget(const Color& color, const Vector2u& size, const Vector2u& position)
    : Widget{size, position}, color_{color} {}

RectWidget::~RectWidget() {}

void RectWidget::OnRender(Renderer* renderer) {
    assert(renderer != nullptr);

    renderer->RenderRectangle(position_, size_, color_);
}
