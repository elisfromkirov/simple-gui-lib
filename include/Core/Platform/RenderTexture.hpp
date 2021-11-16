#ifndef __RENDER_TEXTURE_HPP__
#define __RENDER_TEXTURE_HPP__

#include <cassert>
#include <cstdint>

#include <SFML/Graphics.hpp>

#include "Core/Math/Vector2.hpp"
#include "Core/Platform/Image.hpp"
#include "Core/Platform/IRenderTarget.hpp"

class RenderTexture : public IRenderTarget {
public:
    RenderTexture(const Vector2u& size);
    virtual ~RenderTexture() override;

    virtual void Clear(const Color& color) override;

    virtual void Display() override;

    virtual NativeRenderTarget* GetNativeRenderTarget() override;

    void SetSize(const Vector2u& size); 
    const Vector2u& GetSize() const;

    const NativeImage& GetCapture();

private:
    sf::RenderTexture texture_;
    sf::Sprite        capture_;

    Vector2u          size_;
};

#endif // __RENDER_TEXTURE_HPP__