#include "Title.hpp"
#include "ButtonHandler.hpp"

const Font Title::kTitleFont{"assets/Fonts/SourceCodePro/SourceCodeProBold.ttf"};

Title::Title(const std::string& title, Widget* widget)
    : Widget{Vector2u{0, 0}} {
    close_button_sprite_ = new Sprite("assets/Icons/Close.bmp");   
    title_text_          = new Text(title, kTitleFont);

    size_.x = widget->GetSize().x;
    size_.y = close_button_sprite_->GetSize().y;

    Button* close_button = new Button(close_button_sprite_);
    close_button->SetHandler<kMouseButtonPress>(new CloseButtonHandler(widget));
    Attach(close_button, Vector2u{0, 0});

    Attach(new TextWidget(title_text_, 
                          Vector2u{widget->GetSize().x - close_button_sprite_->GetSize().x, 
                                   close_button_sprite_->GetSize().y}),
                          Vector2u{close_button_sprite_->GetSize().x, 0});
}

Title::~Title() {
    delete close_button_sprite_;
    delete title_text_;
}
