#ifndef __LIST_HPP__
#define __LIST_HPP__

#include <cassert>
#include <cstdint>

#include "GUI/Widgets/ContainerWidget.hpp"
#include "GUI/Widgets/ScrollBar.hpp"

class HorizontalList : public ContainerWidget {
public:
    HorizontalList(const Rect2& rect);
    virtual ~HorizontalList() override;

    virtual bool OnHorizontalScrollEvent(const HorizontalScrollEvent* event) override;

    bool InsertItem(Widget* widget);
    bool RemoveItem(Widget* widget);

    uint32_t GetWidth() const;

protected:   
    uint32_t width_;
};

class VerticalList : public ContainerWidget {
public:
    VerticalList(const Rect2& rect);
    virtual ~VerticalList() override;

    virtual bool OnVerticalScrollEvent(const VerticalScrollEvent* event) override;

    bool InsertItem(Widget* widget);
    bool RemoveItem(Widget* widget);

    uint32_t GetHeight() const;

protected:   
    uint32_t height_;
};

class ScrollingHorizontalList : public ContainerWidget {
public:
    ScrollingHorizontalList(const Rect2& rect);
    virtual ~ScrollingHorizontalList() override;

    bool InsertItem(Widget* widget);
    bool RemoveItem(Widget* widget);

public:
    void SliderValueChangeResponse(float value);

protected:
    float                scroll_value_;

    HorizontalScrollBar* scroll_bar_;
    HorizontalList*      list_;
};

class ScrollingVerticalList : public ContainerWidget {
public:
    ScrollingVerticalList(const Rect2& rect);
    virtual ~ScrollingVerticalList() override;

    bool InsertItem(Widget* widget);
    bool RemoveItem(Widget* widget);

public:
    void SliderValueChangeResponse(float value);

protected:
    float              scroll_value_;

    VerticalScrollBar* scroll_bar_;
    VerticalList*      list_;
};

#endif // __LIST_HPP__