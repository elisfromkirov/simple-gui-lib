#include "Core/Platform/Texture.hpp"

Texture::Texture(const std::string& path)
    : texture_{} {
    texture_.loadFromFile(path);
} 

Texture::~Texture() {}

const NativeTexture& Texture::GetNativeTexture() const {
    return texture_;
}