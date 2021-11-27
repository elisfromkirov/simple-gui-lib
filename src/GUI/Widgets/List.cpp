#include "GUI/Widgets/List.hpp"
#include "GUI/Styles/FilledStyle.hpp"

HorizontalList::HorizontalList(const Vector2u& size, const Vector2i& position) 
    : CompositeWidget{size, position} {}

HorizontalList::~HorizontalList() {}

bool HorizontalList::InsertItem(Widget* widget) {
    assert(widget != nullptr);

    if (widget->GetParent() != nullptr) {
        return false;
    }

    Vector2i position{position_};
    if (!children_.empty()) {
        position.x = children_.back()->GetPosition().x +
                     static_cast<int32_t>(children_.back()->GetSize().x);
    }

    widget->SetParent(this);
    widget->Move(position);

    children_.push_back(widget);

    return true;
}

bool HorizontalList::RemoveItem(Widget* widget) {
    assert(widget != nullptr);

    return false;
}

VerticalList::VerticalList(const Vector2u& size, const Vector2i& position)
    : CompositeWidget{size, position} {}

VerticalList::~VerticalList() {}

bool VerticalList::InsertItem(Widget* widget) {
    assert(widget != nullptr);

    if (widget->GetParent() != nullptr) {
        return false;
    }

    Vector2i position{position_};
    if (!children_.empty()) {
        position.y = children_.back()->GetPosition().y + 
                     static_cast<int32_t>(children_.back()->GetSize().y);
    }

    widget->SetParent(this);
    widget->Move(position);

    children_.push_back(widget);

    return true;
}

bool VerticalList::RemoveItem(Widget* widget) {
    assert(widget != nullptr);

    return false;
}

DropDownList::DropDownList(const Vector2u& size, const Vector2i position)
    : CompositeWidget{size, position},
      hide_button_{nullptr},
      hide_{false},
      list_{nullptr} {
    // ApplyStyle(new FilledStyle(Color(0.f, 0.f, 1.f, 1.f)));

    hide_button_ = new Button(Vector2u{24, 24}, position + Vector2i{12, 12});
    hide_button_->ApplyStyle(new FilledStyle(Color(0.f, 1.f, 0.f, 1.f), Color(1.f, 0.f, 0.f, 1.f), Color(1.f, 0.f, 0.f, 1.f)));
    hide_button_->Clicked.Connect<DropDownList>(this, &DropDownList::HideList);

    Attach(hide_button_);

    list_ = new VerticalList(size - Vector2u{24, 48}, position + Vector2i{12, 48});
    list_->ApplyStyle(new FilledStyle(Color(1.f, 1.f, 1.f, 1.f)));

    Attach(list_);
}

DropDownList::~DropDownList() {}

bool DropDownList::InsertItem(Widget* widget) {
    assert(list_ != nullptr);
    
    return list_->InsertItem(widget);
}

bool DropDownList::RemoveItem(Widget* widget) {
    assert(list_ != nullptr);

    return list_->RemoveItem(widget);
}

void DropDownList::HideList() {
    hide_ = !hide_;
}

void DropDownList::RenderChildren(Renderer* renderer) {
    assert(renderer != nullptr);

    if (hide_) {
        hide_button_->OnRender(renderer);
    } else {
        for (auto iter = children_.begin(); iter != children_.end(); ++iter) {
            Widget* child = *iter;

            child->OnRender(renderer);
        }
    }
}
