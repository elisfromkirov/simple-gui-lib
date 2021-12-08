#ifndef __WIDGET_FACTORY_HPP__
#define __WIDGET_FACTORY_HPP__

#include <cassert>
#include <cstdint>
#include <string>

#include "Application/Plugins/Plugin.hpp"
#include "Core/Signal/IFunctor.hpp"

using namespace plugin;

class Button;
class ContainerWidget;
class HorizontalSlider;
class Label;
class Widget;

class PluginClickCallback : public IFunctor<void ()> {
public:
    PluginClickCallback(IClickCallback* callback);
    virtual ~PluginClickCallback() override;

    virtual void operator()() override;

private:
    IClickCallback* callback_;
};

class PluginSliderCallback : public IFunctor<void (float)> {
public:
    PluginSliderCallback(ISliderCallback* callback);
    virtual ~PluginSliderCallback() override;

    virtual void operator()(float value) override;

private:
    ISliderCallback* callback_;

    float value_;
};

class IPluginWidget {
public:
    virtual ~IPluginWidget() {}
    
    virtual Widget* GetWidget() = 0;
};

class PluginButton : public IPluginWidget, public IButton {
public:
    PluginButton(Button* button);
    virtual ~PluginButton() override;

    virtual Widget* GetWidget() override;

    virtual int32_t GetWidth() override;
    virtual int32_t GetHieght() override;

    virtual void SetClickCallback(IClickCallback* callback) override;

private:
    Button* button_;
};

class PluginSlider : public IPluginWidget, public ISlider {
public:
    PluginSlider(HorizontalSlider* slider);
    virtual ~PluginSlider() override;

    virtual Widget* GetWidget() override;

    virtual int32_t GetWidth() override;
    virtual int32_t GetHieght() override;

    virtual void SetSliderCallback(ISliderCallback* callback) override;

    virtual float GetValue() override;
    virtual void SetValue(float value) override;

private:
    HorizontalSlider* slider_;
};

class PluginLabel : public IPluginWidget, public ILabel {
public:
    PluginLabel(Label* label);
    virtual ~PluginLabel() override;

    virtual Widget* GetWidget() override;

    virtual int32_t GetWidth() override;
    virtual int32_t GetHieght() override;

    virtual void SetText(const char* text) override;

private:
    Label* label_;
};

class PluginPreferencesPanel : public IPluginWidget, public IPreferencesPanel {
public:
    PluginPreferencesPanel(ContainerWidget* container_widget);
    virtual ~PluginPreferencesPanel() override;

    virtual Widget* GetWidget() override;

    virtual int32_t GetWidth() override;
    virtual int32_t GetHieght() override;

    virtual void Attach(IWidget* widget, int32_t x, int32_t y) override;

private:
    ContainerWidget* container_widget_;
};

class PluginWidgetFactory : public IWidgetFactory {
public:
    PluginWidgetFactory();
    virtual ~PluginWidgetFactory() override;

    virtual IButton* CreateDefaultButtonWithIcon(const char* icon_file_name) override;
    virtual IButton* CreateDefaultButtonWithText(const char* text) override;
    virtual IButton* CreateButtonWithIcon(int32_t width, int32_t height, const char* icon_file_name) override;
    virtual IButton* CreateButtonWithText(int32_t width, int32_t height, const char* text, int32_t char_size) override;

    virtual ISlider* CreateDefaultSlider(float range_min, float range_max) override;
    virtual ISlider* CreateSlider(int32_t width, int32_t height, float range_min, float range_max) override;
    virtual ISlider* CreateSlider(int32_t width, int32_t height, float thumb_width, float thumb_height, float range_min, float range_max) override;

    virtual ILabel* CreateDefaultLabel(const char* text) override;
    virtual ILabel* CreateLabel(int32_t width, int32_t height, const char* text, int32_t char_size) override;

    virtual IPreferencesPanel* CreateDefaultPreferencesPanel() override;
};

#endif // __WIDGET_FACTORY_HPP__