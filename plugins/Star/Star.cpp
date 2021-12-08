#include "Plugin.hpp"

namespace plugin {

class StarTool : public ITool {
public:
    StarTool(IAPI* api)
        : panel_(nullptr) {
        panel_ = api->GetWidgetFactory()->CreateDefaultPreferencesPanel();
        shape_ = api->GetTextureFactory()->CreateTexture("StarBrush.bmp");
    }

    virtual ~StarTool() override {}

    virtual void ActionBegin(ITexture* canvas, int x, int y) override {
        assert(canvas != nullptr);

        canvas->CopyTexture(shape_, x - shape_->GetWidth() / 2, y - shape_->GetHieght() / 2, shape_->GetWidth(), shape_->GetHieght());
    }

    virtual void Action(ITexture* canvas, int x, int y, int dx, int dy) override {
        assert(canvas != nullptr);

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
            canvas->CopyTexture(shape_, x0 - shape_->GetWidth() / 2, y0 - shape_->GetHieght() / 2, shape_->GetWidth(), shape_->GetHieght());

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

    }

    virtual void ActionEnd(ITexture* canvas, int x, int y) override {}

    virtual const char* GetIconFileName() const override {
        return "Star.bmp";
    }

    virtual IPreferencesPanel* GetPreferencesPanel() const override {
        return panel_;
    }

private:
    IPreferencesPanel* panel_;
    ITexture*          shape_;
};

class Plugin : public IPlugin {
public:
    Plugin(IAPI* api)
        : star_tool_{nullptr} {
        star_tool_ = new StarTool(api);
    }

    ~Plugin() {}

    virtual std::list<IFilter*> GetFilters() const override {
        return std::list<IFilter*>{};
    }

    virtual std::list<ITool*>   GetTools  () const override {
        return std::list<ITool*>{star_tool_};
    }

private:
    StarTool* star_tool_;
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

}