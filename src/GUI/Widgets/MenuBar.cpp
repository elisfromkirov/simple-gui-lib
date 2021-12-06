#include "Core/EventManager/EventManager.hpp"
#include "Core/ResourceManager/Resources.hpp"
#include "Core/ResourceManager/ResourceManager.hpp"
#include "Core/Platform/InputEvent.hpp"
#include "Core/Platform/RenderTexture.hpp"
#include "GUI/Events/WidgetEvent.hpp"
#include "GUI/Styles/ButtonStyle.hpp"
#include "GUI/Styles/FilledStyle.hpp"
#include "GUI/Widgets/MenuBar.hpp"

Menu::Menu(uint32_t width, const std::string& name) 
    : ContainerWidget{},
      name_{name} {
    list_ = new ScrollingVerticalList(Rect2(width, kDefaultHeight * kDefaultItemCount));
    
    rect_.size = list_->GetSize();
    texture_   = new RenderTexture(rect_.size);

    Attach(list_);
}

Menu::~Menu() {}

bool Menu::OnMouseButtonPressEvent(const MouseButtonPressEvent* event) {
    assert(event != nullptr);

    if (!HitTest(event->GetMousePosition())) {
        Hide();
    }
    return true;
}

bool Menu::OnMouseButtonReleaseEvent(const MouseButtonReleaseEvent* event) {
    assert(event != nullptr);

    if (!HitTest(event->GetMousePosition())) {
        Hide();
    }
    return true;
}

bool Menu::OnMouseMoveEvent(const MouseMoveEvent* event) {
    assert(event != nullptr);

    return true;
}

bool Menu::InsertItem(const std::string& name) {
    assert(list_ != nullptr);

    Label* label = new Label(name, ResourceManager::GetInstance()->LoadFont(kMediumFont));
    label->SetTextColor(Color(0.f, 0.f, 0.f, 1.f));

    Button* button = new Button(Rect2(list_->GetSize().x, kDefaultHeight));
    button->ApplyStyle(new MenuButtonStyle());
    button->AttachInLeft(label);

    return list_->InsertItem(button);
}

const std::string& Menu::GetName() const {
    return name_;
}

void Menu::Show() {
    EventManager::GetInstance()->PostEvent<ShowPopUpWidgetEvent>(this);
}

void Menu::Hide() {
    EventManager::GetInstance()->PostEvent<HidePopUpWidgetEvent>(this);
}

MenuBar::MenuBar(Widget* widget)
    : ContainerWidget{Rect2{Vector2u{widget->GetSize().x, kDefaultHeight}, widget->GetPosition()}},  
      list_{nullptr} {
    list_ = new HorizontalList(rect_);
    list_->ApplyStyle(new FilledStyle(FilledStyle::kList));

    Attach(list_);
}

MenuBar::~MenuBar() {}

bool MenuBar::InsertMenu(Menu* menu) {
    assert(list_ != nullptr);
    assert(menu != nullptr);

    Label* label = new Label(menu->GetName(), ResourceManager::GetInstance()->LoadFont(kMediumFont));
    label->SetTextColor(Color(0.f, 0.f, 0.f, 1.f));

    Button* button = new Button(Rect2(label->GetSize().x + kDefaultHeight, kDefaultHeight));
    button->ApplyStyle(new MenuButtonStyle());
    button->Clicked.Connect<Menu>(menu, &Menu::Show);
    button->AttachInMiddle(label);

    list_->InsertItem(button);

    menu->Move(Vector2i(button->GetPosition().x, button->GetPosition().y + button->GetSize().y));

    return true;
}