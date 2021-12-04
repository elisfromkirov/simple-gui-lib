#ifndef __ICON_HPP__
#define __ICON_HPP__

#include <cassert>
#include <cstdint>

#include "Core/Platform/Image.hpp"
#include "GUI/Widgets/Widget.hpp"

class Icon : public Widget {
public:
    Icon(const Texture& texture);
    virtual ~Icon() override;

    virtual void OnRender(RenderTexture* texture) override;

protected:
    Image image_;
};

#endif // __ICON_HPP__