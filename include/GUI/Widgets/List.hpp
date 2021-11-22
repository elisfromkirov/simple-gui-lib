#ifndef __LIST_HPP__
#define __LIST_HPP__

#include <cassert>
#include <cstdint>

#include "CompositeWidget.hpp"

class HorizontalList : public CompositeWidget {
public:
    HorizontalList(const Vector2u& size, const Vector2i& position = Vector2i());
    virtual ~HorizontalList() override;

    bool InsertItem(Widget* widget);
    bool RemoveItem(Widget* widget);
};

class VerticalList : public CompositeWidget {
public:
    VerticalList(const Vector2u& size, const Vector2i& position = Vector2i());
    virtual ~VerticalList() override;

    bool InsertItem(Widget* widget);
    bool RemoveItem(Widget* widget);
};

#endif // __LIST_HPP__ 