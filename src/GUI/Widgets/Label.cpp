#include "GUI/Widgets/Label.hpp"

Label::Label(const std::string& string, const Font& font, const Vector2i& position)
    : Widget{},
      text_{string, font} {
    size_ = text_.GetSize();

    position_ = position;
    text_.SetPosition(position_);
}

Label::~Label() {}

void Label::OnRender(Renderer* renderer) {
    assert(renderer != nullptr);

    ApplyStyles(renderer);

    renderer->RenderText(text_);    
}

void Label::Move(const Vector2i& position) {
    position_ = position;
    text_.SetPosition(MapPositionToParent());
}

void Label::Resize(const Vector2u& size) {}

void Label::SetCharacterSize(uint32_t char_size) {
    text_.SetCharacterSize(char_size);
    size_ = text_.GetSize();
}

void Label::SetString(const std::string& string) {
    text_.SetString(string);
    size_ = text_.GetSize();
}

void Label::SetTextColor(const Color& color) {
    text_.SetFillColor(color);
    size_ = text_.GetSize();
}
