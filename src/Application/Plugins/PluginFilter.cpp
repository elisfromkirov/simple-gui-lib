#include "Application/Plugins/PluginFilter.hpp"
#include "Application/Plugins/TextureFactory.hpp"

PluginFilter::PluginFilter(plugin::IFilter* filter)
    : filter_{filter} {
    assert(filter_ != nullptr);
}

PluginFilter::~PluginFilter() {}

void PluginFilter::Apply(RenderTexture* canvas) {
    assert(filter_ != nullptr);

    PluginTexture texture(canvas);
    filter_->Apply(&texture);
}

const char* PluginFilter::GetName() const {
    assert(filter_ != nullptr);

    return filter_->GetName();
}