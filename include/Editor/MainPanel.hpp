#ifndef __MAIN_PANEL_HPP__
#define __MAIN_PANEL_HPP__

#include "GUI/Widgets/ButtonBase.hpp"
#include "GUI/Widgets/Image.hpp"
#include "GUI/Widgets/Label.hpp"
#include "GUI/Widgets/Widget.hpp"

class MainPanel : public Widget {
public:
    MainPanel(const Vector2u& size);

    virtual ~MainPanel() override;
};

#endif // __MAIN_PANEL_HPP__
