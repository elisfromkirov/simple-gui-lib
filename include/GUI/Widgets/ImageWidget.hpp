#ifndef __IMAGE_WIDGET_HPP__
#define __IMAGE_WIDGET_HPP__

#include <cassert>
#include <cstdint>

#include "Renderer.hpp"
#include "Sprite.hpp"
#include "Vector2.hpp"
#include "Widget.hpp"

class ImageWidget : public Widget {
public:
    ImageWidget(Sprite* sprite, const Vector2u& position = Vector2u());
    
    virtual ~ImageWidget() override;

    virtual void OnRender(Renderer* renderer) override;

protected:
    Sprite* sprite_;
};

#endif // __IMAGE_WIDGET_HPP__
