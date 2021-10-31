#ifndef __SPRITE_HPP__
#define __SPRITE_HPP__

#include <cassert>
#include <cstdint>

#include "SFMLPlatform.hpp"
#include "Vector2.hpp"

class Sprite {
public:
    Sprite(const std::string& filename);
    ~Sprite();

    Vector2u GetSize() const;

    void SetPosition(const Vector2u& position);

    const NativeSprite& GetNativeSprite() const;

private:
    sf::Sprite  native_sprite_;
    sf::Texture native_texture_;
};

#endif // __SPRITE_HPP__
