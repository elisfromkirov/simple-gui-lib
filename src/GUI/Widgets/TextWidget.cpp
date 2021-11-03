#include "Core/ResourceManager/ResourceManager.hpp"
#include "GUI/Widgets/TextWidget.hpp"

TextWidget::TextWidget(const std::string& string)
    : Widget{Vector2u()},
      text_{nullptr} {
}

TextWidget::~TextWidget() {
    assert(text_ != nullptr);
}

void TextWidget::OnRender(Renderer* renderer) const {
    assert(text_    != nullptr);
    assert(renderer != nullptr);
}
