#include "GUI/Styles/ButtonStyle.hpp"
#include "GUI/Styles/FilledStyle.hpp"
#include "GUI/Widgets/TabBar.hpp"

TabActivateFunctor::TabActivateFunctor(TabBar* tab_bar, Widget* tab, Button* tab_button)
    : tab_bar_{tab_bar},
      tab_{tab},
      tab_button_{tab_button} {
    assert(tab_bar_    != nullptr);
    assert(tab_        != nullptr);
    assert(tab_button_ != nullptr);
}

TabActivateFunctor::~TabActivateFunctor() {}

void TabActivateFunctor::operator()() {
    assert(tab_bar_    != nullptr);
    assert(tab_        != nullptr);
    assert(tab_button_ != nullptr);

    tab_bar_->SetActiveTab(tab_, tab_button_);
}

TabBar::TabBar(const Vector2u& tab_size, const Vector2u& tab_button_size)
    : ContainerWidget{Rect2{tab_button_size.x + tab_size.x, tab_size.y}},
      tab_button_size_{tab_button_size},
      buttons_{nullptr},
      active_tab_{nullptr},
      active_button_{nullptr} {
    buttons_ = new VerticalList(Rect2(tab_button_size.x, tab_size.y));
    buttons_->ApplyStyle(new FilledStyle(FilledStyle::kMediumPanel));

    AttachInLeft(buttons_);
}

TabBar::~TabBar() {}

bool TabBar::OnEvent(const Event* event) {
    assert(event != nullptr);

    FilterEvent(event);

    bool handled = buttons_->OnEvent(event);
    if (handled) {
        return true;
    }

    if (active_tab_ != nullptr) {
        bool handled = active_tab_->OnEvent(event);
        if (handled) {
            return true;
        }
    }

    return HandleEvent(event);
}

void TabBar::OnRender(IRenderTarget* render_target) {
    assert(texture_      != nullptr);
    assert(buttons_      != nullptr);
    assert(render_target != nullptr);

    texture_->Clear();

    for (auto iter = styles_.begin(); iter != styles_.end(); ++iter) {
        (*iter)->Apply(this, texture_);
    }

    buttons_->OnRender(texture_);
    if (active_tab_ != nullptr) {
        active_tab_->OnRender(texture_);
    }

    texture_->Display();

    render_target->RenderImage(Image(texture_, MapPositionToParent()));
}

Button* TabBar::InsertTab(Widget* tab, const std::string& image_file) {
    assert(buttons_   != nullptr);
    assert(tab        != nullptr);

    Button* tab_button = new Button(Rect2(tab_button_size_.x, tab_button_size_.y), false);
    tab_button->ApplyStyle(new ButtonStyle(image_file));
    tab_button->Clicked.Connect(new TabActivateFunctor(this, tab, tab_button));

    buttons_->InsertItem(tab_button);

    tab->Move(Vector2i(rect_.position.x + tab_button_size_.x, rect_.position.y));
    Attach(tab);

    return tab_button;
}

void TabBar::SetActiveTab(Widget* tab, Button* tab_button) {
    assert(buttons_   != nullptr);
    assert(tab        != nullptr);
    assert(tab_button != nullptr);

    if (active_button_ != nullptr) {
        active_button_->SetPressed(false);
    }
    tab_button->SetPressed(true);

    active_tab_    = tab; 
    active_button_ = tab_button;
}