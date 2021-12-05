#include "Core/EventManager/EventManager.hpp"
#include "Core/Platform/RenderTexture.hpp"
#include "GUI/Events/WidgetEvent.hpp"
#include "GUI/Styles/FilledStyle.hpp"
#include "GUI/Widgets/List.hpp"

HorizontalList::HorizontalList(const Rect2& rect) 
    : ContainerWidget{rect},
      width_{0} {}

HorizontalList::~HorizontalList() {}

bool HorizontalList::InsertItem(Widget* widget) {
    assert(widget != nullptr);

    if (widget->GetParent() != nullptr) {
        return false;
    }

    Vector2i position(rect_.position.x + width_, rect_.position.y);
    width_ += widget->GetSize().x;

    widget->SetParent(this);
    widget->Move(position);

    children_.push_back(widget);

    return true;
}

bool HorizontalList::OnHorizontalScrollEvent(const HorizontalScrollEvent* event) {
    assert(event != nullptr);

    if (width_ < rect_.size.x) {
        return true;
    }

    Vector2i old_position(children_.front()->GetPosition());
    Vector2i     position(rect_.position.x - (static_cast<float>(width_ - rect_.size.x) * event->GetValue()), 
                          rect_.position.y);

    Vector2i offset = position - old_position;
    for (auto iter = children_.begin(); iter != children_.end(); ++iter) {
        (*iter)->Move((*iter)->GetPosition() + offset);
    }

    return true;
}

bool HorizontalList::RemoveItem(Widget* widget) {
    assert(widget != nullptr);

    return false;
}

uint32_t HorizontalList::GetWidth() const {
    return width_;
}


VerticalList::VerticalList(const Rect2& rect)
    : ContainerWidget{rect},
      height_{0} {}

VerticalList::~VerticalList() {}

bool VerticalList::OnVerticalScrollEvent(const VerticalScrollEvent* event) {
    assert(event != nullptr);

    if (height_ < rect_.size.y) {
        return true;
    }

    Vector2i old_position(children_.front()->GetPosition());
    Vector2i     position(rect_.position.x,
                          rect_.position.y - (static_cast<float>(height_ - rect_.size.y) * event->GetValue()));

    Vector2i offset = position - old_position;
    for (auto iter = children_.begin(); iter != children_.end(); ++iter) {
        (*iter)->Move((*iter)->GetPosition() + offset);
    }

    return true;
}

bool VerticalList::InsertItem(Widget* widget) {
    assert(widget != nullptr);

    if (widget->GetParent() != nullptr) {
        return false;
    }

    Vector2i position(rect_.position.x, rect_.position.y + height_);
    height_ += widget->GetSize().y;

    widget->SetParent(this);
    widget->Move(position);

    children_.push_back(widget);

    return true;
}

bool VerticalList::RemoveItem(Widget* widget) {
    assert(widget != nullptr);

    return false;
}

uint32_t VerticalList::GetHeight() const {
    return height_;
}

ScrollingHorizontalList::ScrollingHorizontalList(const Rect2& rect)
    : ContainerWidget{},
      scroll_value_{0.f},
      list_{nullptr},
      scroll_bar_{nullptr} {
    list_       = new HorizontalList(rect);
    scroll_bar_ = new HorizontalScrollBar(rect.size.x, 0.05);

    rect_.size     = Vector2u(rect.size.x, rect.size.y + scroll_bar_->GetSize().y);
    rect_.position = rect.position;

    texture_ = new RenderTexture(rect_.size);

    AttachInTop(list_);
    
    scroll_bar_->ValueChanged.Connect<ScrollingHorizontalList>(this, &ScrollingHorizontalList::SliderValueChangeResponse);
    AttachInBottom(scroll_bar_);

    ApplyStyle(new FilledStyle(FilledStyle::kList));
}

ScrollingHorizontalList::~ScrollingHorizontalList() {}

bool ScrollingHorizontalList::InsertItem(Widget* widget) {
    assert(scroll_bar_ != nullptr);
    assert(list_       != nullptr);
    assert(widget      != nullptr);

    return list_->InsertItem(widget);
}

bool ScrollingHorizontalList::RemoveItem(Widget* widget) {
    assert(widget != nullptr);

    return list_->RemoveItem(widget);
}

void ScrollingHorizontalList::SliderValueChangeResponse(float value) {
    assert(scroll_bar_ != nullptr);
    assert(list_       != nullptr);

    EventManager::GetInstance()->PostEvent<HorizontalScrollEvent>(list_, value, scroll_value_);

    scroll_value_ = value;
}

ScrollingVerticalList::ScrollingVerticalList(const Rect2& rect)
    : ContainerWidget{rect},
      scroll_value_{0.f},
      list_{nullptr},
      scroll_bar_{nullptr} {
    scroll_bar_ = new VerticalScrollBar(rect_.size.y, 0.05);
    AttachInRight(scroll_bar_);

    list_ = new VerticalList(Rect2{rect_.size.x - scroll_bar_->GetSize().x, rect_.size.y});
    AttachInLeft(list_);

    scroll_bar_->ValueChanged.Connect<ScrollingVerticalList>(this, &ScrollingVerticalList::SliderValueChangeResponse);

    ApplyStyle(new FilledStyle(FilledStyle::kList));
}

ScrollingVerticalList::~ScrollingVerticalList() {}

bool ScrollingVerticalList::InsertItem(Widget* widget) {
    assert(scroll_bar_ != nullptr);
    assert(list_       != nullptr);
    assert(widget      != nullptr);

    return list_->InsertItem(widget);
}

bool ScrollingVerticalList::RemoveItem(Widget* widget) {
    assert(widget != nullptr);

    return list_->RemoveItem(widget);
}

void ScrollingVerticalList::SliderValueChangeResponse(float value) {
    assert(scroll_bar_ != nullptr);
    assert(list_       != nullptr);

    EventManager::GetInstance()->PostEvent<VerticalScrollEvent>(list_, value, scroll_value_);

    scroll_value_ = value;
}