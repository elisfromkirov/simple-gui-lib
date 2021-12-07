#ifndef __TAB_BAR_HPP__
#define __TAB_BAR_HPP__

#include <cassert>
#include <cstdint>
#include <list>

#include "GUI/Widgets/Button.hpp"
#include "GUI/Widgets/ContainerWidget.hpp"
#include "GUI/Widgets/List.hpp"

class TabBar;

class TabActivateFunctor : public IFunctor<void()> {
public:
    TabActivateFunctor(TabBar* tab_bar, Widget* tab, Button* tab_button);
    virtual ~TabActivateFunctor();

    virtual void operator()() override;

protected:
    TabBar* tab_bar_;
    Widget* tab_;
    Button* tab_button_;
};

class TabBar : public ContainerWidget {
public:
    TabBar(const Vector2u& tab_size, const Vector2u& tab_button_size);
    virtual ~TabBar() override;

    virtual bool OnEvent(const Event* event) override;

    virtual void OnRender(IRenderTarget* render_target) override;

    Button* InsertTab(Widget* tab, const std::string& image_file);

    void SetActiveTab(Widget* tab, Button* tab_button);

protected:
    Vector2u           tab_button_size_;

    VerticalList*      buttons_;

    Widget*            active_tab_;
    Button*            active_button_;
};

#endif // __TAB_BAR_HPP__