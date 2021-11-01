#ifndef __MAIN_PANEL_HPP__
#define __MAIN_PANEL_HPP__

#include "IEventListener.hpp"
#include "KeyEvent.hpp"
#include "MouseEvent.hpp"
#include "Title.hpp"
#include "RectWidget.hpp"
#include "Widget.hpp"
#include "Window.hpp"

class MainPanel : public Widget, public IEventListener {
public:
    MainPanel(const Window& window);

    virtual ~MainPanel() override;

    virtual bool OnEvent(const IEvent* event) override;
};

#endif // __MAIN_PANEL_HPP__
