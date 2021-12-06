#ifndef __SLIDER_STYLES_HPP__
#define __SLIDER_STYLES_HPP__

#include "Core/Platform/Color.hpp"
#include "GUI/Styles/IStyle.hpp"

class HorizontalSliderStyle : public IStyle {
private:
    static const Color kDefaultColor;

public:
    HorizontalSliderStyle();
    HorizontalSliderStyle(const Color& color);
    virtual ~HorizontalSliderStyle() override;

    virtual void Apply(Widget* widget, IRenderTarget* render_target) override;

private:
    Color color_;
};

class VerticalSliderStyle : public IStyle {
private:
    static const Color kDefaultColor;

public:
    VerticalSliderStyle();
    VerticalSliderStyle(const Color& color);
    virtual ~VerticalSliderStyle() override;

    virtual void Apply(Widget* widget, IRenderTarget* render_target) override;

private:
    Color color_;
};

class ProgressHorizontalSliderStyle : public IStyle {
private:
    static const Color kDefaultProgressAreaColor;
    static const Color kDefaultTrackColor;

public:
    ProgressHorizontalSliderStyle();
    ProgressHorizontalSliderStyle(const Color& progress_area_color, const Color& track_color);
    virtual ~ProgressHorizontalSliderStyle() override;

    virtual void Apply(Widget* widget, IRenderTarget* render_target) override;
private:

    Color progress_area_color_;
    Color track_color_;
};

class ProgressVerticalSliderStyle : public IStyle {
private:
    static const Color kDefaultProgressAreaColor;
    static const Color kDefaultTrackColor;

public:
    ProgressVerticalSliderStyle();
    ProgressVerticalSliderStyle(const Color& progress_area_color, const Color& track_color);
    virtual ~ProgressVerticalSliderStyle() override;

    virtual void Apply(Widget* widget, IRenderTarget* render_target) override;

private:
    Color progress_area_color_;
    Color track_color_;
};

#endif // __SLIDER_STYLES_HPP__