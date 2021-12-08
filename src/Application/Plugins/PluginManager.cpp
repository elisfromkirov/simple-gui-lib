#include <dlfcn.h>

#include "Application/Tools/ToolManager.hpp"
#include "Application/Plugins/API.hpp"
#include "Application/Plugins/PluginFilter.hpp"
#include "Application/Plugins/PluginManager.hpp"
#include "Application/Plugins/PluginTool.hpp"

const char* PluginManager::kDefaultPluginsDir{"../assets/Plugins/"};

PluginManager* PluginManager::singleton{nullptr};

PluginManager::PluginManager()
    : plugin_api_{nullptr},
      plugins_dir_{kDefaultPluginsDir},
      plugins_{} {
    plugin_api_ = new PluginAPI();

    LoadPlugin("Blur.so");
    LoadPlugin("Square.so");
}

PluginManager::~PluginManager() {
    for (auto iter = plugins_.begin(); iter != plugins_.end(); ++iter) {
        iter->destroy_function(iter->plugin);
    }
}

PluginManager* PluginManager::GetInstance() {
    if (singleton == nullptr) {
        singleton = new PluginManager();
    }

    return singleton;
}

void PluginManager::Release() {
    delete this;
}

void PluginManager::LoadPlugin(const std::string& name) {
    size_t size = plugins_dir_.size() + name.size() + 1;
    char buffer[size];
    memset(buffer, 0, size * sizeof(char));
    
    sprintf(buffer, "%s%s", plugins_dir_.c_str(), name.c_str());

    void* lib = dlopen(buffer, RTLD_NOW);
    if (lib == nullptr) {
        printf("Unable to load plugin: cannot open shared object file %s\n", buffer);
    }

    PluginData plugin_data{};

    plugin_data.create_function = (plugin::CreateFunction)dlsym(lib, "Create");
    if (plugin_data.create_function == nullptr) {
        printf("Unable to load plugin: cannot found Create() function\n");
        return;
    }

    plugin_data.destroy_function = (plugin::DestroyFunction)dlsym(lib, "Destroy");
    if (plugin_data.destroy_function == nullptr) {
        printf("Unable to load plugin: cannot found Destroy() function\n");
        return;
    }

    plugin_data.version_function = (plugin::VersionFunction)dlsym(lib, "Version");
    if (plugin_data.version_function == nullptr) {
        printf("Unable to load plugin: cannot found Version() function\n");
        return;
    }

    if (plugin_data.version_function() != plugin::kVersion) {
        printf("Unable to load plugin: given plugin's version not supported\n");
        return;
    }

    plugin_data.plugin = plugin_data.create_function(plugin_api_);

    std::list<plugin::ITool*> tools = plugin_data.plugin->GetTools();
    for (auto iter = tools.begin(); iter != tools.end(); ++iter) {
        ToolManager::GetInstance()->AddTool(new PluginTool(*iter));
    }

    std::list<plugin::IFilter*> filters = plugin_data.plugin->GetFilters();
    for (auto iter = filters.begin(); iter != filters.end(); ++iter) {
        ToolManager::GetInstance()->AddFilter(new PluginFilter(*iter));
    }

    plugins_.push_back(plugin_data);
}