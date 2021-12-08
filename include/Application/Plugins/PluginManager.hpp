#ifndef __PLUGIN_MANAGER_HPP__
#define __PLUGIN_MANAGER_HPP__

#include <cassert>
#include <cstdint>
#include <cstring>
#include <list>
#include <string>

#include "Application/Plugins/Plugin.hpp"

class PluginAPI;

class PluginManager {
private:
    static const char* kDefaultPluginsDir;

public:
    static PluginManager* GetInstance();

    void Release();

    void LoadPlugin(const std::string& name);

private:
    PluginManager();
    ~PluginManager();

    PluginManager(const ToolManager& other) = delete;
    PluginManager& operator=(const ToolManager& other) = delete;

    static PluginManager* singleton;

private:
    PluginAPI*          plugin_api_;
    std::string         plugins_dir_;

    struct PluginData {
        plugin::CreateFunction  create_function;
        plugin::DestroyFunction destroy_function;
        plugin::VersionFunction version_function;
        plugin::IPlugin*        plugin;
    };
    std::list<PluginData> plugins_;
};

#endif // __PLUGIN_MANAGER_HPP__