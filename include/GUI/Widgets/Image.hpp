#ifndef __IMAGE_HPP__
#define __IMAGE_HPP__

#include <cassert>
#include <cstdint>

#include "GUI/Widgets/Widget.hpp"

class Image : public Widget {
public:
    Image(const char* imagename, const Vector2i& position = Vector2i());

    virtual ~Image() override;

protected:
    virtual void Render(Renderer* renderer) const override;

    virtual void Resize(const Vector2u& size) override; 

    virtual void Move(const Vector2i& displacement) override;

protected:
    Sprite sprite_;
};

#endif // __IMAGE_HPP__
