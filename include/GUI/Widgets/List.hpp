#ifndef __LIST_HPP__
#define __LIST_HPP__

#include <cassert>
#include <cstdint>

#include "GUI/Widgets/Button.hpp"
#include "GUI/Widgets/CompositeWidget.hpp"

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

class DropDownList : public CompositeWidget {
public:
    DropDownList(const Vector2u& size, const Vector2i position = Vector2i());
    virtual ~DropDownList() override;

    bool InsertItem(Widget* widget);
    bool RemoveItem(Widget* widget);

    void HideList();

protected:
    virtual void RenderChildren(Renderer* renderer) override;

protected:
    Button*       hide_button_;
    bool          hide_;

    VerticalList* list_;
};

#endif // __LIST_HPP__