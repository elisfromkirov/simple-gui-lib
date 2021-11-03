#include "GUI/Widgets/TextVeiw.hpp"

TextVeiw::TextVeiw(Text* text, const Vector2u& size, const Vector2u& position)
    : Widget{size, position},
      text_{text} {
    assert(text_ != nullptr);
}

TextVeiw::~TextVeiw() {}

void TextVeiw::OnRender(Renderer* renderer) const {
    assert(text_    != nullptr);
    assert(renderer != nullptr);
}
