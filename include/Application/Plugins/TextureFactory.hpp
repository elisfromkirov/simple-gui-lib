#ifndef __TEXTURE_FACTORY_HPP__
#define __TEXTURE_FACTORY_HPP__

#include <cassert>
#include <cstdint>

#include "Application/Plugins/Plugin.hpp"

using namespace plugin;

class RenderTexture;

class PluginTexture : public ITexture {
public:
    PluginTexture(RenderTexture* texture);
    virtual ~PluginTexture() override;

    virtual int32_t GetWidth() override;
    virtual int32_t GetHieght() override;

    virtual Buffer ReadBuffer() override;
    virtual void ReleaseBuffer(Buffer buffer) override;
    virtual void LoadBuffer(Buffer buffer) override;

    virtual void Clear(color_t color) override;
    virtual void Present() override;

    virtual void DrawLine(int32_t x0, int32_t y0, int32_t x1, int32_t y1, color_t color) override;
    virtual void DrawThickLine(int32_t x0, int32_t y0, int32_t x1, int32_t y1, int32_t thickness, color_t color) override;
    virtual void DrawCircle(int32_t x, int32_t y, int32_t radius, color_t color) override;
    virtual void DrawRect(int32_t x, int32_t y, int32_t width, int32_t height, color_t color) override;

    virtual void CopyTexture(ITexture* texture, int32_t x, int32_t y, int32_t width, int32_t height) override;

    RenderTexture* GetRenderTexture();

protected:
    RenderTexture* texture_;
};

class PluginTextureFactory : public ITextureFactory {
public:
    PluginTextureFactory();
    virtual ~PluginTextureFactory() override;

    virtual ITexture* CreateTexture(const char* filename) override;
    virtual ITexture* CreateTexture(int32_t width, int32_t height) override;
};

#endif // __TEXTURE_FACTORY_HPP__