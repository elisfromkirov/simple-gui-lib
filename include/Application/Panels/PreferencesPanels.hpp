#ifndef __PREFERENCES_PANELS_HPP__
#define __PREFERENCES_PANELS_HPP__

#include <cassert>
#include <cstdint>

#include "Application/Tools/Tools.hpp"
#include "GUI/Widgets/ContainerWidget.hpp"
#include "GUI/Widgets/Slider.hpp"

class PencilPreferencesPanel : public ContainerWidget {
private:
    static const uint32_t kWidth{240};
    static const uint32_t kSliderWidth{30};
    static const uint32_t kIndent{4};

public:
    PencilPreferencesPanel(Pencil* pencil);
    virtual ~PencilPreferencesPanel() override;

public:
    void UpdateThickness (float value);
    void UpdateRedColor  (float value);
    void UpdateGreenColor(float value);
    void UpdateBlueColor (float value);

protected:
    Pencil* pencil_;

    HorizontalSlider* thickness_slider_;
    HorizontalSlider* red_slider_;
    HorizontalSlider* green_slider_;
    HorizontalSlider* blue_slider_;
};

#endif // __PREFERENCES_PANELS_HPP__