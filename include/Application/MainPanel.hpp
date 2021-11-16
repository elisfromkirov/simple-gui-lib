#ifndef __MAIN_PANEL_HPP__
#define __MAIN_PANEL_HPP__

#include "GUI/Widgets/CompositeWidget.hpp"

class MainPanel : public CompositeWidget {
public:
    MainPanel(const Vector2u& size);
    virtual ~MainPanel() override;

    virtual void OnRender(Renderer* renderer) override;
};

#endif // __MAIN_PANEL_HPP__