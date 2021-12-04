#ifndef __MENU_BAR_HPP__
#define __MENU_BAR_HPP__

#include <cassert>
#include <cstdint>
#include <string>

#include "Core/Math/Vector2.hpp"
#include "GUI/Widgets/Button.hpp"
#include "GUI/Widgets/ContainerWidget.hpp"
#include "GUI/Widgets/Label.hpp"
#include "GUI/Widgets/List.hpp"

class Menu : public ContainerWidget {
protected:
    static const uint32_t kDefaultHeight{30};
    static const uint32_t kDefaultItemCount{5};

public:
    Menu(uint32_t width, const std::string& name);
    virtual ~Menu() override;

    virtual bool OnMouseButtonPressEvent(const MouseButtonPressEvent* event) override;

    virtual bool OnMouseButtonReleaseEvent(const MouseButtonReleaseEvent* event) override;

    virtual bool OnMouseMoveEvent(const MouseMoveEvent* event) override;

    const std::string& GetName() const;

    bool InsertItem(const std::string& name);

    void Show();
    void Hide();

protected:
    std::string            name_;

    ScrollingVerticalList* list_;
};

class MenuBar : public ContainerWidget {
private:
    static const uint32_t kDefaultHeight{48};

public:
    MenuBar(Widget* widget);
    virtual ~MenuBar() override;

    bool InsertMenu(Menu* menu);

protected:
    HorizontalList* list_;
};

#endif // __MENU_BAR_HPP__