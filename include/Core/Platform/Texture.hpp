#ifndef __TEXTURE_HPP__
#define __TEXTURE_HPP__

#include <cassert>
#include <cstdint>

#include <SFML/Graphics.hpp>

typedef sf::Texture NativeTexture;

class Texture {
public:
    Texture(const std::string& path);
    ~Texture();

    const NativeTexture& GetNativeTexture() const;

private:
    sf::Texture texture_;
};

#endif // __TEXTURE_HPP__