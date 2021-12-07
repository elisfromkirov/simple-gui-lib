#ifndef __PREFERENCES_PANELS_HPP__
#define __PREFERENCES_PANELS_HPP__

#include <cassert>
#include <cstdint>

#include "Application/Tools/Tools.hpp"
#include "Application/Panels/Palette.hpp"
#include "GUI/Widgets/ContainerWidget.hpp"
#include "GUI/Widgets/Slider.hpp"

class PencilPreferencesPanel : public ContainerWidget {
public:
    PencilPreferencesPanel(Pencil* pencil);
    virtual ~PencilPreferencesPanel() override;

    void ChangeColorResponse(const Color& color);

protected:
    Pencil*  pencil_;

    Palette* palette_;
};

class EraserPreferencesPanel : public ContainerWidget {
public:
    EraserPreferencesPanel(Eraser* eraser, uint32_t max_thickness);
    virtual ~EraserPreferencesPanel() override;

    void ChangeThicknessResponse(uint32_t thickness);

protected:
    Eraser* eraser_;

    ThicknessSlider* thickness_slider_;
};

class BrushPreferencesPanel : public ContainerWidget {
public:
    BrushPreferencesPanel(Brush* brush, uint32_t max_thickness);
    virtual ~BrushPreferencesPanel() override;

    void ChangeColorResponse(const Color& color);
    void ChangeThicknessResponse(uint32_t thickness);

protected:
    Brush* brush_;

    Palette*         palette_;
    ThicknessSlider* thickness_slider_;
};

#endif // __PREFERENCES_PANELS_HPP__