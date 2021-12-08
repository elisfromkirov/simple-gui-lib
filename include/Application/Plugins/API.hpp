#ifndef __API_HPP__
#define __API_HPP__

#include <cassert>
#include <cstdint>

#include "Application/Plugins/Plugin.hpp"

class PluginWidgetFactory;
class PluginTextureFactory;

class PluginAPI : public plugin::IAPI {
public:
    PluginAPI();
    virtual ~PluginAPI() override;

    virtual plugin::IWidgetFactory*  GetWidgetFactory () override;
    virtual plugin::ITextureFactory* GetTextureFactory() override;

protected:
    PluginWidgetFactory*  widget_factory_;
    PluginTextureFactory* texture_factory_;
};

#endif // __API_HPP__