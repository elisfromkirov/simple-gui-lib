#include "Application/Panels/ToolPanel.hpp"
#include "Application/Plugins/WidgetFactory.hpp"
#include "Core/ResourceManager/Resources.hpp"
#include "Core/ResourceManager/ResourceManager.hpp"
#include "GUI/Widgets/Button.hpp"
#include "GUI/Widgets/ContainerWidget.hpp"
#include "GUI/Widgets/Label.hpp"
#include "GUI/Widgets/Slider.hpp"
#include "GUI/Styles/ButtonStyle.hpp"
#include "GUI/Styles/FilledStyle.hpp"
#include "GUI/Styles/SliderStyle.hpp"

PluginClickCallback::PluginClickCallback(IClickCallback* callback)
    : callback_{callback} {
    assert(callback_ != nullptr);
}

PluginClickCallback::~PluginClickCallback() {    
    assert(callback_ != nullptr);

    delete callback_;
}

void PluginClickCallback::operator()() {
    assert(callback_ != nullptr);
    
    callback_->RespondOnClick();
}

PluginSliderCallback::PluginSliderCallback(ISliderCallback* callback)
    : callback_{callback},
      value_{0.f} {
    assert(callback_ != nullptr);
}

PluginSliderCallback::~PluginSliderCallback() {
    assert(callback_ != nullptr);

    delete callback_;
}

void PluginSliderCallback::operator()(float value) {
    assert(callback_ != nullptr);
    
    callback_->RespondOnSlide(value_, value);

    value_ = value;
}

PluginButton::PluginButton(Button* button)
    : button_{button} {
    assert(button_ != nullptr);
}

PluginButton::~PluginButton() {}

Widget* PluginButton::GetWidget() {
    assert(button_ != nullptr);
    
    return button_;
}

int32_t PluginButton::GetWidth() {
    assert(button_ != nullptr);
    
    return button_->GetSize().x;
}

int32_t PluginButton::GetHieght() {
    assert(button_ != nullptr);
    
    return button_->GetSize().y;
}

void PluginButton::SetClickCallback(IClickCallback* callback) {
    assert(button_ != nullptr);

    button_->Clicked.Connect(new PluginClickCallback(callback));
}

PluginSlider::PluginSlider(HorizontalSlider* slider)
    : slider_{slider} {
    assert(slider_ != nullptr);
}

PluginSlider::~PluginSlider() {}

Widget* PluginSlider::GetWidget() {
    assert(slider_ != nullptr);

    return slider_;
}

int32_t PluginSlider::GetWidth() {
    assert(slider_ != nullptr);

    return slider_->GetSize().x;
}

int32_t PluginSlider::GetHieght() {
    assert(slider_ != nullptr);

    return slider_->GetSize().y;
}

void PluginSlider::SetSliderCallback(ISliderCallback* callback) {    
    assert(slider_ != nullptr);

    slider_->ValueChanged.Connect(new PluginSliderCallback(callback));
}

float PluginSlider::GetValue() {
    assert(slider_ != nullptr);
    
    return slider_->GetValue();
}
    
void PluginSlider::SetValue(float value) {
    assert(slider_ != nullptr);
    
    slider_->SetValue(value);    
}

PluginLabel::PluginLabel(Label* label)
    : label_{label} {
    assert(label_ != nullptr);
}

PluginLabel::~PluginLabel() {}

Widget* PluginLabel::GetWidget()  {
    assert(label_ != nullptr);

    return label_;
}

int32_t PluginLabel::GetWidth() {
    assert(label_ != nullptr);

    return label_->GetSize().x;
}

int32_t PluginLabel::GetHieght() {
    assert(label_ != nullptr);

    return label_->GetSize().y;
}

void PluginLabel::SetText(const char* text) {
    assert(label_ != nullptr);

    return label_->SetString(text);
}

PluginPreferencesPanel::PluginPreferencesPanel(ContainerWidget* container_widget)
    : container_widget_{container_widget} {
    assert(container_widget_ != nullptr);
}

PluginPreferencesPanel::~PluginPreferencesPanel() {}

Widget* PluginPreferencesPanel::GetWidget() {
    assert(container_widget_ != nullptr);

    return container_widget_;
}

int32_t PluginPreferencesPanel::GetWidth() {
    assert(container_widget_ != nullptr);

    return container_widget_->GetSize().x;
}

int32_t PluginPreferencesPanel::GetHieght() {
    assert(container_widget_ != nullptr);

    return container_widget_->GetSize().y;
}

void PluginPreferencesPanel::Attach(IWidget* widget, int32_t x, int32_t y) {
    assert(container_widget_ != nullptr);

    Vector2i position(container_widget_->GetPosition().x + x, container_widget_->GetPosition().y + y);

    IPluginWidget* plugin_widget = dynamic_cast<IPluginWidget*>(widget);

    plugin_widget->GetWidget()->Move(position);
    container_widget_->Attach(plugin_widget->GetWidget());
}

PluginWidgetFactory::PluginWidgetFactory() {}

PluginWidgetFactory::~PluginWidgetFactory() {}

IButton* PluginWidgetFactory::CreateDefaultButtonWithIcon(const char* icon_file_name) {
    assert(icon_file_name != nullptr);

    Button* button = new Button(Rect2(ToolPanel::kToolButtonWidth, ToolPanel::kToolButtonHeight));
    button->ApplyStyle(new ButtonStyle(icon_file_name));

    return new PluginButton(button);
}

IButton* PluginWidgetFactory::CreateDefaultButtonWithText(const char* text) {
    assert(text != nullptr);

    Label* label = new Label(text, ResourceManager::GetInstance()->LoadFont(kMediumFont));
    label->SetTextColor(Color(0.f, 0.f, 0.f, 1.f));

    Button* button = new Button(Rect2(label->GetSize()));
    button->ApplyStyle(new MenuButtonStyle());
    button->AttachInMiddle(label);

    return new PluginButton(button);
}

IButton* PluginWidgetFactory::CreateButtonWithIcon(int32_t width, int32_t height, const char* icon_file_name) {
    assert(icon_file_name != nullptr);

    Button* button = new Button(Rect2(width, height));
    button->ApplyStyle(new ButtonStyle(icon_file_name));

    return new PluginButton(button);
}

IButton* PluginWidgetFactory::CreateButtonWithText(int32_t width, int32_t height, const char* text, int32_t char_size) {
    assert(text != nullptr);

    Label* label = new Label(text, ResourceManager::GetInstance()->LoadFont(kMediumFont));
    label->SetTextColor(Color(0.f, 0.f, 0.f, 1.f));

    Button* button = new Button(Rect2(width, height));
    button->ApplyStyle(new MenuButtonStyle());
    button->AttachInMiddle(label);

    return new PluginButton(button);
}

ISlider* PluginWidgetFactory::CreateDefaultSlider(float range_min, float range_max) {
    HorizontalSlider* slider = new HorizontalSlider(Rect2(ToolPanel::kSliderWidth - ToolPanel::kIndent * 2, ToolPanel::kSliderHeight), 
                                                    ToolPanel::kSliderHeight / 3);
    slider->ApplyStyle(new ProgressHorizontalSliderStyle());

    return new PluginSlider(slider);
}

ISlider* PluginWidgetFactory::CreateSlider(int32_t width, int32_t height, float range_min, float range_max) {
    HorizontalSlider* slider = new HorizontalSlider(Rect2(width, height), height / 3);
    slider->ApplyStyle(new ProgressHorizontalSliderStyle());

    return new PluginSlider(slider);
}

ISlider* PluginWidgetFactory::CreateSlider(int32_t width, int32_t height, float thumb_width, float thumb_height, float range_min, float range_max) {
    HorizontalSlider* slider = new HorizontalSlider(Rect2(width, height), height / 3);
    slider->ApplyStyle(new ProgressHorizontalSliderStyle());

    return new PluginSlider(slider);
}

ILabel* PluginWidgetFactory::CreateDefaultLabel(const char* text) {
    Label* label = new Label(text, ResourceManager::GetInstance()->LoadFont(kMediumFont));
    label->SetTextColor(Color(0.f, 0.f, 0.f, 1.f));

    return new PluginLabel(label);
}

ILabel* PluginWidgetFactory::CreateLabel(int32_t width, int32_t height, const char* text, int32_t char_size) {
    Label* label = new Label(text, ResourceManager::GetInstance()->LoadFont(kMediumFont));
    label->SetTextColor(Color(0.f, 0.f, 0.f, 1.f));
    label->SetCharSize(char_size);

    return new PluginLabel(label);
}

IPreferencesPanel* PluginWidgetFactory::CreateDefaultPreferencesPanel() {
    ContainerWidget* container_widget = new ContainerWidget(Rect2(ToolPanel::kPreferencesPanelWidth, 
                                                                  ToolPanel::kPreferencesPanelHeight));

    return new PluginPreferencesPanel(container_widget);
}