#ifndef __PLUGIN_TOOL_HPP__
#define __PLUGIN_TOOL_HPP__

#include <cassert>
#include <cstdint>

#include "Application/Tools/ITool.hpp"
#include "Application/Plugins/Plugin.hpp"

class PluginTool : public ITool {
public:
    PluginTool(plugin::ITool* tool);
    virtual ~PluginTool() override;

    virtual void BeginDraw(RenderTexture* canvas, const Vector2i& position) override;

    virtual void Draw(RenderTexture* canvas, const Vector2i& position, const Vector2i& old_position) override;

    virtual void EndDraw(RenderTexture* canvas, const Vector2i& position) override;

    virtual const char* GetIconFileName() const override;

    virtual const char* GetName() const override;

    virtual Widget* GetPreferencesPanel() override;

private:
    plugin::ITool* tool_;
    
    const char* icon_;
    char* name_;

    Widget* preferences_panel_;
};

#endif // __PLUGIN_TOOL_HPP__