#ifndef __IMAGE_WIDGET_HPP__
#define __IMAGE_WIDGET_HPP__

#include <cassert>
#include <cstdint>

#include "Core/Math/Vector2.hpp"
#include "GUI/Widgets/Widget.hpp"
#include "Platform/Renderer.hpp"
#include "Platform/Sprite.hpp"

class ImageWidget : public Widget {
public:
    ImageWidget(const char* image_name);

    ImageWidget(Sprite* sprite);

    virtual ~ImageWidget() override;

    virtual void OnRender(Renderer* renderer) const override;

protected:
    Sprite* sprite_;
};

#endif // __IMAGE_WIDGET_HPP__
