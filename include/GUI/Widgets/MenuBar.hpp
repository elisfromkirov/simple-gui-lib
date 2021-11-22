#ifndef __MENU_BAR_HPP__
#define __MENU_BAR_HPP__

#include <cassert>
#include <cstdint>

class MenuItem : public CompositeWidget {
public:
    MenuItem(const std::string& string);



protected:

};

class Menu : public MenuItem {
public:


protected:


};

class MenuBar : public CompositeWidget {
public:
    MenuBar(const Vector2u& size, const Vector2i& position);
    virtual ~MenuBar() override;


protected:


};

#endif // __MENU_BAR_HPP__