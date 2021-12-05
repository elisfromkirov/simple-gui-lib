set(INCROOT ${SGUI_SOURCE_DIR}/include/Application/Tools)
set(SRCROOT ${SGUI_SOURCE_DIR}/src/Application/Tools)

target_sources(SGUI_APPLICATION
    PUBLIC
        ${INCROOT}/IFilter.hpp
        ${INCROOT}/ITool.hpp
        ${INCROOT}/ToolManager.hpp
        ${INCROOT}/Tools.hpp
    PRIVATE
        ${SRCROOT}/ToolManager.cpp
        ${SRCROOT}/Tools.cpp
    )
