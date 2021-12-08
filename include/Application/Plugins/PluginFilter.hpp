#ifndef __FLUGIN_FILTER_HPP__
#define __FLUGIN_FILTER_HPP__

#include <cassert>
#include <cstdint>

#include "Application/Tools/IFilter.hpp"
#include "Application/Plugins/Plugin.hpp"

class PluginFilter : public IFilter {
public:
    PluginFilter(plugin::IFilter* filter);
    virtual ~PluginFilter() override;

    virtual void Apply(RenderTexture* canvas) override;

    virtual const char* GetName() const override;

private:
    plugin::IFilter* filter_;
};

#endif // __FLUGIN_FILTER_HPP__