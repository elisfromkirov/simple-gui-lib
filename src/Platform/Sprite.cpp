#include "Sprite.hpp"

Sprite::Sprite(const std::string& filename) 
    : native_sprite_{}, 
      native_texture_{} {
    native_texture_.loadFromFile(filename);

    native_sprite_.setTexture(native_texture_);
}

Sprite::~Sprite() {}

void Sprite::SetPosition(const Vector2u& position) {
    native_sprite_.setPosition(sf::Vector2f{static_cast<float>(position.x),
                                            static_cast<float>(position.y)});

}

const NativeSprite& Sprite::GetNativeSprite() const {
    return native_sprite_;
}
