#include "TextWidget.hpp"

TextWidget::TextWidget(Text* text, const Vector2u& size, const Vector2u& position)
    : Widget{size, position},
      text_{text} {
    assert(text_ != nullptr);
}

TextWidget::~TextWidget() {}

void TextWidget::OnRender(Renderer* renderer) {
    assert(text_    != nullptr);
    assert(renderer != nullptr);

    renderer->RenderText(text_, position_);
}
