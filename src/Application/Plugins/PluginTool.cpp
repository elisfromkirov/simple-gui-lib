#include "Application/Plugins/PluginTool.hpp"
#include "Application/Plugins/TextureFactory.hpp"
#include "Application/Plugins/WidgetFactory.hpp"
#include "GUI/Widgets/ContainerWidget.hpp"

PluginTool::PluginTool(plugin::ITool* tool)
    : tool_{tool},
      icon_{tool->GetIconFileName()},
      name_{nullptr},
      preferences_panel_{nullptr} {
    assert(tool_ != nullptr);

    size_t size = strlen(icon_);
    name_ = new char[size - 4];
    for (size_t i = 0; i < size - 4; ++i) {
        name_[i] = icon_[i];
    }
 
    plugin::IPreferencesPanel* preferences_panel = tool->GetPreferencesPanel();
    assert(preferences_panel != nullptr);

    PluginPreferencesPanel* plugin_preferences_panel = dynamic_cast<PluginPreferencesPanel*>(preferences_panel);

    preferences_panel_ = plugin_preferences_panel->GetWidget();
    assert(preferences_panel_ != nullptr);
}

PluginTool::~PluginTool() {
    delete name_;
}

void PluginTool::BeginDraw(RenderTexture* canvas, const Vector2i& position) {
    assert(tool_  != nullptr);
    assert(canvas != nullptr);

    PluginTexture texture(canvas);
    tool_->ActionBegin(&texture, position.x, position.y);
}

void PluginTool::Draw(RenderTexture* canvas, const Vector2i& position, const Vector2i& old_position) {
    assert(tool_  != nullptr);
    assert(canvas != nullptr);

    PluginTexture texture(canvas);
    tool_->Action(&texture, old_position.x, old_position.y, position.x, position.y);
}

void PluginTool::EndDraw(RenderTexture* canvas, const Vector2i& position) {
    assert(tool_  != nullptr);
    assert(canvas != nullptr);

    PluginTexture texture(canvas);
    tool_->ActionEnd(&texture, position.x, position.y);
}

const char* PluginTool::GetIconFileName() const {
    assert(icon_  != nullptr);

    return icon_;
}

const char* PluginTool::GetName() const {
    assert(name_  != nullptr);

    return name_;
}

Widget* PluginTool::GetPreferencesPanel() {
    assert(preferences_panel_  != nullptr);
    
    return preferences_panel_;
}