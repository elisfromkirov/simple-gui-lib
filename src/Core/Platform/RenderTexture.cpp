#include "Core/Platform/Color.hpp"
#include "Core/Platform/Image.hpp"
#include "Core/Platform/Rectangle.hpp"
#include "Core/Platform/RenderTexture.hpp"
#include "Core/Platform/Text.hpp"

RenderTexture::RenderTexture(const Vector2u& size)
    : texture_{},
      sprite_{} {
    texture_.create(size.x, size.y);
}

RenderTexture::~RenderTexture() {}

void RenderTexture::Clear(const Color& color) {
    texture_.clear(NativeColorFromColor(color));
}

void RenderTexture::Display() {
    texture_.display();
}

void RenderTexture::RenderText(const Text& text) {
    texture_.draw(text.GetNativeText());
}

void RenderTexture::RenderImage(const Image& image) {
    texture_.draw(image.GetNativeImage());
}
    
void RenderTexture::RenderRectangle(const Rectangle& rectangle) {
    texture_.draw(rectangle.GetNativeRectangle());
}

const NativeImage& RenderTexture::GetImage() const {
    sprite_.setTexture(texture_.getTexture());

    return sprite_;
}

uint32_t* RenderTexture::GetBuffer() {
    sf::Vector2u size{texture_.getSize()};
    
    uint32_t* pixels = new uint32_t[size.x * size.y];

    sf::Image image(texture_.getTexture().copyToImage());
    for (uint32_t x = 0; x < size.x; ++x) {
        for (uint32_t y = 0; y < size.y; ++y) {
            sf::Color color(image.getPixel(x, y));

            pixels[x + y * size.x] = (static_cast<uint32_t>(color.r) << 24) + 
                                     (static_cast<uint32_t>(color.g) << 16) + 
                                     (static_cast<uint32_t>(color.b) <<  8) + 
                                     (static_cast<uint32_t>(color.a)      );
        }
    }

    return pixels;
}

void RenderTexture::ReleaseBuffer(uint32_t* pixels) {
    assert(pixels != nullptr);

    delete pixels;
}

void RenderTexture::LoadFromBuffer(uint32_t* pixels) {
    assert(pixels != nullptr);

    sf::Vector2u size{texture_.getSize()};

    sf::Image image{};
    image.create(size.x, size.y);

    for (uint32_t x = 0; x < size.x; ++x) {
        for (uint32_t y = 0; y < size.y; ++y) {
            sf::Color color{};
            color.r = (pixels[x + y * size.x] >> 24) & 255;
            color.g = (pixels[x + y * size.x] >> 16) & 255;
            color.b = (pixels[x + y * size.x] >>  8) & 255;
            color.a = (pixels[x + y * size.x]      ) & 255;

            image.setPixel(x, y, color);
        }
    }

    sf::Texture texture{};
    texture.loadFromImage(image);

    texture_.clear();
    texture_.draw(sf::Sprite(texture));
    texture_.display();
}

Vector2u RenderTexture::GetSize() const {
    sf::Vector2u size{texture_.getSize()};

    return Vector2u{size.x, size.y};
}