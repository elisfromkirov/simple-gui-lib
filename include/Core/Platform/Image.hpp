#ifndef __IMAGE_HPP__
#define __IMAGE_HPP__

#include <cassert>
#include <cstdint>

#include <SFML/Graphics.hpp>

typedef sf::Sprite NativeImage;

#include "Core/Math/Vector2.hpp"
#include "Core/Platform/Texture.hpp"

class Image {
public:
    Image(const Texture& texture);
    ~Image();

    void SetPosition(const Vector2i& position);

    const Vector2u& GetSize() const;

    const NativeImage& GetNativeImage() const;

private:
    sf::Sprite sprite_;

    Vector2u size_;
};

#endif // __IMAGE_HPP__