#include "Application/Plugins/TextureFactory.hpp"
#include "Core/Platform/Image.hpp"
#include "Core/Platform/Rectangle.hpp"
#include "Core/Platform/RenderTexture.hpp"
#include "Core/Platform/Texture.hpp"
#include "Core/ResourceManager/ResourceManager.hpp"

PluginTexture::PluginTexture(RenderTexture* texture)
    : texture_{texture} {}

PluginTexture::~PluginTexture() {}

int32_t PluginTexture::GetWidth() {
    assert(texture_ != nullptr);

    return texture_->GetSize().x;
}

int32_t PluginTexture::GetHieght() {
    assert(texture_ != nullptr);

    return texture_->GetSize().y;
}

Buffer PluginTexture::ReadBuffer() {
    assert(texture_ != nullptr);

    uint32_t* pixels = texture_->GetBuffer();
    assert(pixels != nullptr);

    return Buffer{pixels, this};
}

void PluginTexture::ReleaseBuffer(Buffer buffer) {
    assert(texture_ != nullptr);
    
    if (buffer.texture == this) {
        texture_->ReleaseBuffer(buffer.pixels);
    }
}

void PluginTexture::LoadBuffer(Buffer buffer) {
    assert(texture_ != nullptr);

    if (buffer.texture == this) {
        texture_->LoadFromBuffer(buffer.pixels);
    }
}

void PluginTexture::Clear(color_t color) {
    assert(texture_ != nullptr);

    texture_->Clear(ColorFromRGBA(color));
}

void PluginTexture::Present() {
    assert(texture_ != nullptr);

    texture_->Display();
}

void PluginTexture::DrawLine(int32_t x0, int32_t y0, int32_t x1, int32_t y1, color_t color) {
    DrawThickLine(x0, y0, x1, y1, 1, color);
}

void PluginTexture::DrawThickLine(int32_t x0, int32_t y0, int32_t x1, int32_t y1, int32_t thickness, color_t color) {
    assert(texture_ != nullptr);

    Rectangle rectangle(Rect2(thickness, thickness), ColorFromRGBA(color));

    Vector2i delta(abs(x1 - x0), abs(y1 - y0));
    Vector2i sign((x1 > x0 ? 1 : -1), (y1 > y0 ? 1 : -1)); 

    int32_t error = delta.x - delta.y;

    rectangle.SetPosition(Vector2i(x1, y1));
    texture_->RenderRectangle(rectangle);
    while(x0 != x1 || y0 != y1) {    
        rectangle.SetPosition(Vector2i(x0, y0));
        texture_->RenderRectangle(rectangle);
    
        int32_t error2 = error * 2;
        if(error2 > -delta.y) {
            error -= delta.y;
            x0    += sign.x;
        }
        if(error2 < delta.x) {
            error += delta.x;
            y0    += sign.y;
        }
    }
}

void PluginTexture::DrawCircle(int32_t x, int32_t y, int32_t radius, color_t color) {
    assert(texture_ != nullptr);
}

void PluginTexture::DrawRect(int32_t x, int32_t y, int32_t width, int32_t height, color_t color) {
    assert(texture_ != nullptr);

    texture_->RenderRectangle(Rectangle(Rect2(width, height, x, y), ColorFromRGBA(color)));
}

RenderTexture* PluginTexture::GetRenderTexture() {
    assert(texture_ != nullptr);
    
    return texture_;
}

void PluginTexture::CopyTexture(ITexture* texture, int32_t x, int32_t y, int32_t width, int32_t height) {
    assert(texture_ != nullptr);
    assert(texture  != nullptr);

    PluginTexture* plugin_texture = dynamic_cast<PluginTexture*>(texture);
    texture_->RenderImage(Image(plugin_texture->GetRenderTexture(), Vector2i(x, y)));
}

PluginTextureFactory::PluginTextureFactory() {}

PluginTextureFactory::~PluginTextureFactory() {}

ITexture* PluginTextureFactory::CreateTexture(const char* filename) {
    assert(filename != nullptr);

    Image   image(ResourceManager::GetInstance()->LoadTexture(filename));

    RenderTexture* render_texture = new RenderTexture(image.GetSize());
    render_texture->Clear();
    render_texture->RenderImage(image);
    render_texture->Display();

    return new PluginTexture(render_texture);
}

ITexture* PluginTextureFactory::CreateTexture(int32_t width, int32_t height) {
    RenderTexture* render_texture = new RenderTexture(Vector2u(width, height));

    return new PluginTexture(render_texture);
}