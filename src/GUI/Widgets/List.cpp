#include "GUI/Widgets/List.hpp"

HorizontalList::HorizontalList(const Vector2u& size, const Vector2i& position) 
    : ContainerWidget{size, position} {}

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
    : ContainerWidget{size, position} {}

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
