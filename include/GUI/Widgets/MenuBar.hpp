#ifndef __MENU_BAR_HPP__
#define __MENU_BAR_HPP__

#include <cassert>
#include <cstdint>

class Menu : public CompositeWidget {
public:
    Menu(const std::string& name);
    virtual ~Menu() override;



protected:
    
};

class MenuBar : public CompositeWidget {
public:
    MenuBar(const Vector2u& size, const Vector2i& position);
    virtual ~MenuBar() override;


protected:


};

#endif // __MENU_BAR_HPP__