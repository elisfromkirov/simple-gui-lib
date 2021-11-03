#include "Core/ResourceManager/ResourceManager.hpp"
#include "GUI/Widgets/TextWidget.hpp"

const char* TextWidget::kDefaultFontName{"SourceCodePro/SourceCodeProRegular.ttf"};

TextWidget::TextWidget(const std::string& string)
    : Widget{Vector2u()},
      text_{nullptr} {
    Font* font = ResourceManager::GetResourceManager()->LoadFont(kDefaultFontName);

    text_ = new Text(string, font);

    ResourceManager::GetResourceManager()->FreeFont(font);
}

TextWidget::~TextWidget() {
    assert(text_ != nullptr);

    delete text_;
}

void TextWidget::OnRender(Renderer* renderer) const {
    assert(text_    != nullptr);
    assert(renderer != nullptr);

    renderer->RenderText(text_);
}

void TextWidget::SetString(const std::string& string) {
    text_->SetString(string);
}
