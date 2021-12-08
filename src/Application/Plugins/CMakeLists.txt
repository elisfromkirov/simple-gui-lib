set(INCROOT ${SGUI_SOURCE_DIR}/include/Application/Plugins)
set(SRCROOT ${SGUI_SOURCE_DIR}/src/Application/Plugins)

target_sources(SGUI_APPLICATION
    PUBLIC
        ${INCROOT}/API.hpp
        ${INCROOT}/Plugin.hpp
        ${INCROOT}/PluginManager.hpp
        ${INCROOT}/PluginTool.hpp
        ${INCROOT}/TextureFactory.hpp
        ${INCROOT}/WidgetFactory.hpp
    PRIVATE
        ${SRCROOT}/API.cpp
        ${SRCROOT}/PluginManager.cpp
        ${SRCROOT}/PluginTool.cpp
        ${SRCROOT}/TextureFactory.cpp
        ${SRCROOT}/WidgetFactory.cpp
    )
