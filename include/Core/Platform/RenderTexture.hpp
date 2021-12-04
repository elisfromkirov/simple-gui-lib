#ifndef __RENDER_TEXTURE_HPP__
#define __RENDER_TEXTURE_HPP__

#include <cassert>
#include <cstdint>

#include "Core/Math/Vector2.hpp"
#include "Core/Platform/NativePlatform.hpp"
#include "Core/Platform/IRenderTarget.hpp"

class RenderTexture : public IRenderTarget {
public:
    RenderTexture(const Vector2u& size);
    virtual ~RenderTexture() override;

    virtual void Clear(const Color& color) override;
    virtual void Display() override;

    virtual void RenderText(const Text& text) override;
    virtual void RenderImage(const Image& image) override;
    virtual void RenderRectangle(const Rectangle& rectangle) override;

    Vector2u GetSize() const;
    const NativeImage& GetImage() const;

private:
    sf::RenderTexture  texture_;
    mutable sf::Sprite sprite_;
};

#endif // __RENDER_TEXTURE_HPP__