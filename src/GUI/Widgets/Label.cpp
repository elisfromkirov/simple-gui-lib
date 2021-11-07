#include "GUI/Widgets/Label.hpp"

Label::Label(const std::string& string, const Color& color)
    : text_{string} {
    text_.SetFillColor(color);
    size_ = text_.GetSize();    
}

Label::~Label() {}

void Label::SetCharacterSize(uint32_t char_size) {
    text_.SetCharacterSize(char_size);
    size_ = text_.GetSize();
}

void Label::SetString(const std::string& string) {
    text_.SetString(string);
    size_ = text_.GetSize();
}

void Label::Render(Renderer* renderer) const {
    assert(renderer != nullptr);

    renderer->RenderText(text_);    
}

void Label::Resize(const Vector2u& size) {}

void Label::Move(const Vector2i& displacement) {
    position_ += displacement;

    text_.SetPosition(position_);
}
