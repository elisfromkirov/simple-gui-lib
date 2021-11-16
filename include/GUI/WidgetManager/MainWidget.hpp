#ifndef __MAIN_WIDGET_HPP__
#define __MAIN_WIDGET_HPP__

#include "Core/EventManager/IEventListener.hpp"


class WidgetManager : public IEventListener {
    static WidgetManager* singleton;

private:
    WidgetManager();

public:
    virtual ~ WidgetManager() override;

    virtual void OnEvent(const Event* event) override;

    Widget* GetRootWidget();
    void SetRootWidget(Widget* widget);

    static  WidgetManager* GetWidgetManager();

private:
    CompositeWidget* root_;



};
    
    
    RenderWindow     window_;
    Renderer         renderer_;
    Input            input_;

#endif // __MAIN_WIDGET_HPP__