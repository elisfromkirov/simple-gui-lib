#ifndef __SPRITE_HPP__
#define __SPRITE_HPP__

#include <cassert>
#include <cstdint>

#include "Core/Math/Vector2.hpp"
#include "Platform/Platform.hpp"

class Sprite {
public:
    Sprite(const char* filename);
    ~Sprite();

    Vector2u GetSize() const;

    void SetPosition(const Vector2u& position);

    const NativeSprite& GetNativeSprite() const;

private:
    sf::Sprite  native_sprite_;
    sf::Texture native_texture_;
};

#endif // __SPRITE_HPP__
