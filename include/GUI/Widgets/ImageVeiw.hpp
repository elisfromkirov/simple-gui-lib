#ifndef __IMAGE_VEIW_HPP__
#define __IMAGE_VEIW_HPP__

#include <cassert>
#include <cstdint>

#include "Core/Math/Vector2.hpp"
#include "GUI/Widgets/Widget.hpp"
#include "Platform/Renderer.hpp"
#include "Platform/Sprite.hpp"

class ImageVeiw : public Widget {
public:
    ImageVeiw(Sprite* sprite, const Vector2u& position = Vector2u());

    virtual ~ImageVeiw() override;

    virtual void OnRender(Renderer* renderer) const override;

protected:
    Sprite* sprite_;
};

#endif // __IMAGE_WIDGET_HPP__
