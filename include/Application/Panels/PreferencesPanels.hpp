#ifndef __PREFERENCES_PANELS_HPP__
#define __PREFERENCES_PANELS_HPP__

#include <cassert>
#include <cstdint>

#include "Application/Tools/Tools.hpp"
#include "GUI/Widgets/ContainerWidget.hpp"
#include "GUI/Widgets/Slider.hpp"

class PencilPreferencesPanel : public ContainerWidget {
public:
    PencilPreferencesPanel(Pencil* pencil);
    virtual ~PencilPreferencesPanel() override;

public:
    void UpdateThickness(float value);

protected:
    Pencil* pencil_;

    HorizontalSlider* thickness_slider_;
};

#endif // __PREFERENCES_PANELS_HPP__