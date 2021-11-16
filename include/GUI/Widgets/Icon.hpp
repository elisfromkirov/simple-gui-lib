#ifndef __ICON_HPP__
#define __ICON_HPP__

#include <cassert>
#include <cstdint>

#include "Core/Platform/Image.hpp"
#include "GUI/Widgets/Widget.hpp"

class Icon : public Widget {
public:
    Icon(const Texture& texture, const Vector2i& position = Vector2i());
    virtual ~Icon() override;

    virtual void OnRender(Renderer* renderer) override;

    virtual bool OnMoveEvent(const MoveEvent* event) override;

    virtual bool OnResizeEvent(const ResizeEvent* event) override;

protected:
    Image image_;
};

#endif // __ICON_HPP__