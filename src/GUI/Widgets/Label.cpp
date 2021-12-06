#include "Core/Platform/RenderTexture.hpp"
#include "GUI/Widgets/Label.hpp"

Label::Label(const std::string& string, const Font& font)
    : Widget{},
      text_{string, font} {
    rect_.size     = text_.GetSize();
}

Label::~Label() {}

void Label::OnRender(IRenderTarget* render_target) {
    assert(render_target != nullptr);

    text_.SetPosition(MapPositionToParent()); 
    render_target->RenderText(text_);    
}

void Label::SetCharSize(uint32_t char_size) {
    text_.SetCharSize(char_size);
    rect_.size = text_.GetSize();
}

void Label::SetString(const std::string& string) {
    text_.SetString(string);
    rect_.size = text_.GetSize();
}

void Label::SetTextColor(const Color& color) {
    text_.SetFillColor(color);
    rect_.size = text_.GetSize();
}
