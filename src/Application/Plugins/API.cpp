#include "Application/Plugins/API.hpp"
#include "Application/Plugins/TextureFactory.hpp"
#include "Application/Plugins/WidgetFactory.hpp"

PluginAPI::PluginAPI() 
    : widget_factory_{nullptr},
      texture_factory_{nullptr} {
    widget_factory_  = new PluginWidgetFactory();
    texture_factory_ = new PluginTextureFactory();
}

PluginAPI::~PluginAPI() {}

plugin::IWidgetFactory* PluginAPI::GetWidgetFactory () {
    assert(widget_factory_ != nullptr);
    
    return widget_factory_;
}

plugin::ITextureFactory* PluginAPI::GetTextureFactory() {
    assert(texture_factory_ != nullptr);

    return texture_factory_;
}
