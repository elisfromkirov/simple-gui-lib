#include "Plugin.hpp"

namespace plugin {

class BlurTool : public ITool {
public:
    BlurTool(plugin::IAPI* api)
        : panel_{nullptr} {
        panel_ = api->GetWidgetFactory()->CreateDefaultPreferencesPanel();
    }

    ~BlurTool() {}

    virtual void ActionBegin(ITexture* canvas, int x, int y) override {}

    virtual void Action(ITexture* canvas, int x, int y, int dx, int dy) override {
        assert(canvas != nullptr);

        int32_t width = canvas->GetWidth();
        int32_t height = canvas->GetWidth();

        Buffer old_buffer = canvas->ReadBuffer();
        Buffer buffer     = canvas->ReadBuffer();

        int32_t x0 = x;
        int32_t y0 = y;
        int32_t x1 = x0 + dx;
        int32_t y1 = y0 + dy;

        int32_t delta_x = abs(x1 - x0);
        int32_t delta_y = abs(y1 - y0);

        int32_t sign_x = x1 > x0 ? 1 : -1;
        int32_t sign_y = y1 > y0 ? 1 : -1;

        int32_t error = delta_x - delta_y;

        while(x0 != x1 || y0 != y1) {
            if (0 < x0 && x0 < width && 0 < y0 && y0 < height) {
                uint32_t r_sum = GetR(old_buffer.pixels[x - 1 + (y + 1) * width])+
                                 GetR(old_buffer.pixels[x + 0 + (y + 1) * width])+
                                 GetR(old_buffer.pixels[x + 1 + (y + 1) * width])+
                                 GetR(old_buffer.pixels[x - 1 + (y + 0) * width])+
                                 GetR(old_buffer.pixels[x + 0 + (y + 0) * width])+
                                 GetR(old_buffer.pixels[x + 1 + (y + 0) * width])+
                                 GetR(old_buffer.pixels[x - 1 + (y - 1) * width])+
                                 GetR(old_buffer.pixels[x + 0 + (y - 1) * width])+
                                 GetR(old_buffer.pixels[x + 1 + (y - 1) * width]);

                uint32_t g_sum = GetG(old_buffer.pixels[x - 1 + (y + 1) * width]) +
                                 GetG(old_buffer.pixels[x + 0 + (y + 1) * width]) +
                                 GetG(old_buffer.pixels[x + 1 + (y + 1) * width]) +
                                 GetG(old_buffer.pixels[x - 1 + (y + 0) * width]) +
                                 GetG(old_buffer.pixels[x + 0 + (y + 0) * width]) +
                                 GetG(old_buffer.pixels[x + 1 + (y + 0) * width]) +
                                 GetG(old_buffer.pixels[x - 1 + (y - 1) * width]) +
                                 GetG(old_buffer.pixels[x + 0 + (y - 1) * width]) +
                                 GetG(old_buffer.pixels[x + 1 + (y - 1) * width]);

                uint32_t b_sum = GetB(old_buffer.pixels[x - 1 + (y + 1) * width]) +
                                 GetB(old_buffer.pixels[x + 0 + (y + 1) * width]) +
                                 GetB(old_buffer.pixels[x + 1 + (y + 1) * width]) +
                                 GetB(old_buffer.pixels[x - 1 + (y + 0) * width]) +
                                 GetB(old_buffer.pixels[x + 0 + (y + 0) * width]) +
                                 GetB(old_buffer.pixels[x + 1 + (y + 0) * width]) +
                                 GetB(old_buffer.pixels[x - 1 + (y - 1) * width]) +
                                 GetB(old_buffer.pixels[x + 0 + (y - 1) * width]) +
                                 GetB(old_buffer.pixels[x + 1 + (y - 1) * width]);
                
                uint32_t a_sum = GetA(old_buffer.pixels[x - 1 + (y + 1) * width]) +
                                 GetA(old_buffer.pixels[x + 0 + (y + 1) * width]) +
                                 GetA(old_buffer.pixels[x + 1 + (y + 1) * width]) +
                                 GetA(old_buffer.pixels[x - 1 + (y + 0) * width]) +
                                 GetA(old_buffer.pixels[x + 0 + (y + 0) * width]) +
                                 GetA(old_buffer.pixels[x + 1 + (y + 0) * width]) +
                                 GetA(old_buffer.pixels[x - 1 + (y - 1) * width]) +
                                 GetA(old_buffer.pixels[x + 0 + (y - 1) * width]) +
                                 GetA(old_buffer.pixels[x + 1 + (y - 1) * width]);

                buffer.pixels[x + y * width] = GetRGBA(r_sum / 9, g_sum / 9, b_sum / 9, a_sum / 9);
            }

            int32_t error2 = error * 2;
            if(error2 > -delta_y) {
                error -= delta_y;
                x0    += sign_x;
            }
            if(error2 < delta_x) {
                error += delta_x;
                y0    += sign_y;
            }
        }

        canvas->LoadBuffer(buffer);

        canvas->ReleaseBuffer(buffer);
        canvas->ReleaseBuffer(old_buffer);
    }

    virtual void ActionEnd(ITexture* canvas, int x, int y) override {}

    virtual const char* GetIconFileName() const override {
        return "Blur.bmp";
    }

    virtual IPreferencesPanel* GetPreferencesPanel() const override {
        return panel_;
    }

private:
    uint32_t GetR(uint32_t color) {
        return (color >> 24) & 255;
    }

    uint32_t GetG(uint32_t color) {
        return (color >> 16) & 255;
    }

    uint32_t GetB(uint32_t color) {
        return (color >>  8) & 255;
    }

    uint32_t GetA(uint32_t color) {
        return (color      ) & 255;
    }

    uint32_t GetRGBA(uint32_t r, uint32_t g, uint32_t b, uint32_t a) {
        return (r << 24) + (g << 16) + (b <<  8) + a;
    }

private:
    IPreferencesPanel* panel_;
};

class BlurFilter : public IFilter {
public:
    BlurFilter(plugin::IAPI* api)
        : panel_{nullptr} {
        panel_ = api->GetWidgetFactory()->CreateDefaultPreferencesPanel();
    }

    ~BlurFilter() {}

    virtual void Apply(ITexture* canvas) override {
        assert(canvas != nullptr);

        int32_t width  = canvas->GetWidth();
        int32_t height = canvas->GetHieght();

        Buffer old_buffer = canvas->ReadBuffer();
        Buffer buffer     = canvas->ReadBuffer();

        for (int32_t x = 1; x < width - 1; ++x) {
            for (int32_t y = 1; y < height - 1; ++y) {
                uint32_t r_sum = GetR(old_buffer.pixels[x - 1 + (y + 1) * width])+
                                 GetR(old_buffer.pixels[x + 0 + (y + 1) * width])+
                                 GetR(old_buffer.pixels[x + 1 + (y + 1) * width])+
                                 GetR(old_buffer.pixels[x - 1 + (y + 0) * width])+
                                 GetR(old_buffer.pixels[x + 0 + (y + 0) * width])+
                                 GetR(old_buffer.pixels[x + 1 + (y + 0) * width])+
                                 GetR(old_buffer.pixels[x - 1 + (y - 1) * width])+
                                 GetR(old_buffer.pixels[x + 0 + (y - 1) * width])+
                                 GetR(old_buffer.pixels[x + 1 + (y - 1) * width]);

                uint32_t g_sum = GetG(old_buffer.pixels[x - 1 + (y + 1) * width]) +
                                 GetG(old_buffer.pixels[x + 0 + (y + 1) * width]) +
                                 GetG(old_buffer.pixels[x + 1 + (y + 1) * width]) +
                                 GetG(old_buffer.pixels[x - 1 + (y + 0) * width]) +
                                 GetG(old_buffer.pixels[x + 0 + (y + 0) * width]) +
                                 GetG(old_buffer.pixels[x + 1 + (y + 0) * width]) +
                                 GetG(old_buffer.pixels[x - 1 + (y - 1) * width]) +
                                 GetG(old_buffer.pixels[x + 0 + (y - 1) * width]) +
                                 GetG(old_buffer.pixels[x + 1 + (y - 1) * width]);

                uint32_t b_sum = GetB(old_buffer.pixels[x - 1 + (y + 1) * width]) +
                                 GetB(old_buffer.pixels[x + 0 + (y + 1) * width]) +
                                 GetB(old_buffer.pixels[x + 1 + (y + 1) * width]) +
                                 GetB(old_buffer.pixels[x - 1 + (y + 0) * width]) +
                                 GetB(old_buffer.pixels[x + 0 + (y + 0) * width]) +
                                 GetB(old_buffer.pixels[x + 1 + (y + 0) * width]) +
                                 GetB(old_buffer.pixels[x - 1 + (y - 1) * width]) +
                                 GetB(old_buffer.pixels[x + 0 + (y - 1) * width]) +
                                 GetB(old_buffer.pixels[x + 1 + (y - 1) * width]);
                
                uint32_t a_sum = GetA(old_buffer.pixels[x - 1 + (y + 1) * width]) +
                                 GetA(old_buffer.pixels[x + 0 + (y + 1) * width]) +
                                 GetA(old_buffer.pixels[x + 1 + (y + 1) * width]) +
                                 GetA(old_buffer.pixels[x - 1 + (y + 0) * width]) +
                                 GetA(old_buffer.pixels[x + 0 + (y + 0) * width]) +
                                 GetA(old_buffer.pixels[x + 1 + (y + 0) * width]) +
                                 GetA(old_buffer.pixels[x - 1 + (y - 1) * width]) +
                                 GetA(old_buffer.pixels[x + 0 + (y - 1) * width]) +
                                 GetA(old_buffer.pixels[x + 1 + (y - 1) * width]);

                buffer.pixels[x + y * width] = GetRGBA(r_sum / 9, g_sum / 9, b_sum / 9, a_sum / 9);
            }
        }        

        canvas->LoadBuffer(buffer);

        canvas->ReleaseBuffer(buffer);
        canvas->ReleaseBuffer(old_buffer);
    }

    virtual const char* GetName() const override {
        return "Blur";
    }

    virtual IPreferencesPanel* GetPreferencesPanel() const override {
        return panel_;
    }

public:
    uint32_t GetR(uint32_t color) {
        return (color >> 24) & 255;
    }

    uint32_t GetG(uint32_t color) {
        return (color >> 16) & 255;
    }

    uint32_t GetB(uint32_t color) {
        return (color >>  8) & 255;
    }

    uint32_t GetA(uint32_t color) {
        return (color      ) & 255;
    }

    uint32_t GetRGBA(uint32_t r, uint32_t g, uint32_t b, uint32_t a) {
        return (r << 24) + (g << 16) + (b <<  8) + a;
    }

private:
    IPreferencesPanel* panel_;
};

class Plugin : public IPlugin {
public:
    Plugin(IAPI* api)
        : blur_tool_{nullptr},
          blur_filter_{nullptr} {
        blur_tool_ = new BlurTool(api);
        blur_filter_ = new BlurFilter(api);
    }

    virtual ~Plugin() override {}

    virtual std::list<IFilter*> GetFilters() const override {
        return std::list<IFilter*>{blur_filter_};
    }

    virtual std::list<ITool*> GetTools() const override {
        return std::list<ITool*>{blur_tool_};
    }

private:
    BlurTool* blur_tool_;
    BlurFilter* blur_filter_;
};

extern "C" IPlugin* Create(IAPI* api) {
    return new Plugin(api);
}

extern "C" void Destroy(IPlugin* plugin) {
    delete plugin;
}

extern "C" uint32_t Version() {
    return kVersion;
}

} // namespace plugin