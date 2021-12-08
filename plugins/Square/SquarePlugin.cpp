#include <cassert>

#include "Plugin.hpp"

namespace plugin
{

const uint32_t kDefaultThickness = 10;
const uint32_t kMaxThickness = 100;

IAPI* api = nullptr;

class SquareTool : public ITool
{
public:
    SquareTool();
    ~SquareTool();

    virtual void ActionBegin(ITexture* canvas, int x, int y) override;
    virtual void Action     (ITexture* canvas, int x, int y, int dx, int dy) override;
    virtual void ActionEnd  (ITexture* canvas, int x, int y) override;

    virtual const char* GetIconFileName() const override;
    virtual IPreferencesPanel* GetPreferencesPanel() const override;

    Color GetThickness() const { return thickness_; }

    void SetThickness(uint32_t thickness) { thickness_ = thickness; }

private:
    IPreferencesPanel* panel_;

    uint32_t thickness_;
};

class ThicknessSliderCallback : public ISliderCallback
{
public:
    ThicknessSliderCallback(SquareTool* tool) : tool_(tool) {}

    virtual void RespondOnSlide(float old_value, float current_value) override
    {
        tool_->SetThickness(static_cast<uint32_t>(current_value * kMaxThickness));
    }

private:
    SquareTool* tool_;
};

SquareTool::SquareTool()
    : panel_(nullptr), thickness_(kDefaultThickness)
{
    if (api == nullptr)
    {
        return;
    }

    IWidgetFactory* factory = api->GetWidgetFactory();
    panel_ = factory->CreateDefaultPreferencesPanel();

    ILabel* label = factory->CreateDefaultLabel("Thickness");
    panel_->Attach(label, 4, 4);

    ISlider* thickness_slider = factory->CreateDefaultSlider(0, 1);
    thickness_slider->SetSliderCallback(new ThicknessSliderCallback(this));

    panel_->Attach(thickness_slider, 4, label->GetHieght() + 10);
}

SquareTool::~SquareTool()
{
    if (panel_ != nullptr)
    {
        delete panel_;
    }
}

void SquareTool::ActionBegin(ITexture* canvas, int x, int y)
{
    assert(canvas);

    canvas->DrawRect(x,     y,     thickness_ + 2, thickness_ + 2, 0x000000ff);
    canvas->DrawRect(x + 1, y + 1, thickness_,     thickness_,     0xffffffff);
}

void SquareTool::Action(ITexture* canvas, int x, int y, int dx, int dy)
{
    assert(canvas);

    canvas->DrawRect(x,     y,     thickness_ + 2, thickness_ + 2, 0x000000ff);
    canvas->DrawRect(x + 1, y + 1, thickness_,     thickness_,     0xffffffff);
}

void SquareTool::ActionEnd(ITexture* canvas, int x, int y)
{
    assert(canvas);

    canvas->DrawRect(x,     y,     thickness_ + 2, thickness_ + 2, 0x000000ff);
    canvas->DrawRect(x + 1, y + 1, thickness_,     thickness_,     0xffffffff);
}

const char* SquareTool::GetIconFileName() const
{
    return "Square.bmp";
}

IPreferencesPanel* SquareTool::GetPreferencesPanel() const
{
    return panel_;
}

class Plugin : public IPlugin
{
public:
    Plugin(SquareTool* square_tool)
        : square_tool_(square_tool) {}

    ~Plugin();

    virtual std::list<IFilter*> GetFilters() const override;
    virtual std::list<ITool*>   GetTools  () const override;

private:
    SquareTool* square_tool_;
};

Plugin::~Plugin()
{
    delete square_tool_;
}

std::list<IFilter*> Plugin::GetFilters() const
{
    return std::list<IFilter*>();
}

std::list<ITool*> Plugin::GetTools() const
{
    std::list<ITool*> list;
    list.push_back(square_tool_);

    return list;
}

extern "C" IPlugin* Create(IAPI* api)
{
    plugin::api = api;
    return new Plugin(new SquareTool);
}

extern "C" void Destroy(IPlugin* plugin)
{
    delete plugin;
}

extern "C" uint32_t Version()
{
    return kVersion;
}

}