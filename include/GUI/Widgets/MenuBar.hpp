#ifndef __MENU_BAR_HPP__
#define __MENU_BAR_HPP__

#include <cassert>
#include <cstdint>

#include "Core/Math/Vector2u.hpp"
#include "Core/Signal/Signal.hpp"
#include "GUI/Widgets/ContainerWidget.hpp"

class MenuItem : public Button {
public:
    Menu(const std::string& name);
    virtual ~Menu() override;

    const std::string& GetName() const;

protected:
    std::string name_;
};

class Menu : public MenuItem {
public:
    Menu(const std::string& name);
    virtual ~Menu() override;

    bool InsertMenu(Menu* menu);

    const std::string& GetName() const;

protected:
    std::string name_;

    
};

class MenuBar : public ContainerWidget {
public:
    MenuBar(const Vector2u& size, const Vector2i& position);
    virtual ~MenuBar() override;

    bool InsertMenu(Menu* menu);

protected:
    HorizontalList* list_;
};

#endif // __MENU_BAR_HPP__