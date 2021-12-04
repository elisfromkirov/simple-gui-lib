#include "Core/Platform/Rectangle.hpp"
#include "Core/Platform/RenderTexture.hpp"
#include "GUI/Styles/SliderStyle.hpp"
#include "GUI/Widgets/Slider.hpp"

const Color HorizontalSliderStyle::kDefaultColor{ColorFromRGBA(0x434343ff)};

HorizontalSliderStyle::HorizontalSliderStyle() 
    : HorizontalSliderStyle{kDefaultColor} {}

HorizontalSliderStyle::HorizontalSliderStyle(const Color& color) 
    : color_{color} {}

HorizontalSliderStyle::~HorizontalSliderStyle() {}

void HorizontalSliderStyle::Apply(Widget* widget, RenderTexture* texture) {
    assert(widget  != nullptr);
    assert(texture != nullptr);

    HorizontalSlider* slider = static_cast<HorizontalSlider*>(widget);

    Rect2 thumb{};

    thumb.size.x     = slider->GetThumbWidth();
    thumb.size.y     = slider->GetSize().y;
    thumb.position.x = static_cast<int32_t>((slider->GetSize().x - thumb.size.x) * slider->GetValue());
    thumb.position.y = 0;

    texture->RenderRectangle(Rectangle(thumb, color_));
}

const Color VerticalSliderStyle::kDefaultColor{ColorFromRGBA(0x434343ff)};

VerticalSliderStyle::VerticalSliderStyle()
    : VerticalSliderStyle{kDefaultColor} {}

VerticalSliderStyle::VerticalSliderStyle(const Color& color)
    : color_{color} {}

VerticalSliderStyle::~VerticalSliderStyle() {}

void VerticalSliderStyle::Apply(Widget* widget, RenderTexture* texture) {
    assert(widget  != nullptr);
    assert(texture != nullptr);

    VerticalSlider* slider = static_cast<VerticalSlider*>(widget);

    Rect2 thumb{};

    thumb.size.x     = slider->GetSize().x;
    thumb.size.y     = slider->GetThumbHeight();
    thumb.position.x = 0;
    thumb.position.y = static_cast<int32_t>((slider->GetSize().y - thumb.size.y) * slider->GetValue());

    texture->RenderRectangle(Rectangle(thumb, color_));
}

const Color ProgressHorizontalSliderStyle::kDefaultProgressAreaColor{ColorFromRGBA(0xe2e2e2ff)};

const Color ProgressHorizontalSliderStyle::kDefaultTrackColor{ColorFromRGBA(0x989898ff)};

ProgressHorizontalSliderStyle::ProgressHorizontalSliderStyle() 
    : ProgressHorizontalSliderStyle{kDefaultProgressAreaColor, kDefaultTrackColor} {}

ProgressHorizontalSliderStyle::ProgressHorizontalSliderStyle(const Color& progress_area_color,
                                                             const Color& track_color)
    : progress_area_color_{progress_area_color},
      track_color_{track_color} {}

ProgressHorizontalSliderStyle::~ProgressHorizontalSliderStyle() {}

void ProgressHorizontalSliderStyle::Apply(Widget* widget, RenderTexture* texture) {
    assert(widget  != nullptr);
    assert(texture != nullptr);

    HorizontalSlider* slider = static_cast<HorizontalSlider*>(widget);

    Rect2 track{};

    track.size.x     = slider->GetSize().x;
    track.size.y     = slider->GetSize().y / 3;
    track.position.x = 0;
    track.position.y = slider->GetSize().y / 3;

    texture->RenderRectangle(Rectangle(track, track_color_));
    
    Rect2 progress_area{};

    progress_area.size.x     = static_cast<int32_t>(slider->GetSize().x * slider->GetValue());
    progress_area.size.y     = slider->GetSize().y / 3;
    progress_area.position.x = 0;
    progress_area.position.y = slider->GetSize().y / 3;

    texture->RenderRectangle(Rectangle(progress_area, progress_area_color_));

    Rect2 thumb{};

    thumb.size.x     = slider->GetThumbWidth();
    thumb.size.y     = slider->GetSize().y;
    thumb.position.x = static_cast<int32_t>((slider->GetSize().x - thumb.size.x) * slider->GetValue());
    thumb.position.y = 0;
    
    texture->RenderRectangle(Rectangle(thumb, progress_area_color_));
}

const Color ProgressVerticalSliderStyle::kDefaultProgressAreaColor{ColorFromRGBA(0xe2e2e2ff)};

const Color ProgressVerticalSliderStyle::kDefaultTrackColor{ColorFromRGBA(0x989898ff)};

ProgressVerticalSliderStyle::ProgressVerticalSliderStyle() 
    : ProgressVerticalSliderStyle{kDefaultProgressAreaColor, kDefaultTrackColor} {}

ProgressVerticalSliderStyle::ProgressVerticalSliderStyle(const Color& progress_area_color, 
                                                         const Color& track_color)
    : progress_area_color_{progress_area_color},
      track_color_{track_color} {}

ProgressVerticalSliderStyle::~ProgressVerticalSliderStyle() {}

void ProgressVerticalSliderStyle::Apply(Widget* widget, RenderTexture* texture) {
    assert(widget  != nullptr);
    assert(texture != nullptr);

    VerticalSlider* slider = static_cast<VerticalSlider*>(widget);

    Rect2 track{};

    track.size.x     = slider->GetSize().x / 3;
    track.size.y     = slider->GetSize().y;
    track.position.x = slider->GetSize().x / 3;
    track.position.y = 0;

    texture->RenderRectangle(Rectangle(track, track_color_));

    Rect2 progress_area{};

    progress_area.size.x     = slider->GetSize().x / 3;
    progress_area.size.y     = static_cast<int32_t>(slider->GetSize().y * slider->GetValue());
    progress_area.position.x = slider->GetSize().x / 3;
    progress_area.position.y = 0;

    texture->RenderRectangle(Rectangle(progress_area, progress_area_color_));

    Rect2 thumb{};

    thumb.size.x     = slider->GetSize().x;
    thumb.size.y     = slider->GetThumbHeight();
    thumb.position.x = 0;
    thumb.position.y = static_cast<int32_t>((slider->GetSize().y - thumb.size.y) * slider->GetValue());

    texture->RenderRectangle(Rectangle(thumb, progress_area_color_));
}