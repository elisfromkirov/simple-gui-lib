add_library(SGUI_APPLICATION)

set(INCROOT ${SGUI_SOURCE_DIR}/include/Application)
set(SRCROOT ${SGUI_SOURCE_DIR}/src/Application)

target_include_directories(SGUI_APPLICATION
    PUBLIC
        ${SGUI_SOURCE_DIR}/include
    )

target_sources(SGUI_APPLICATION
    PUBLIC
        ${INCROOT}/Application.hpp
    PRIVATE
        ${SRCROOT}/Application.cpp
)

add_subdirectory(Commands)
add_subdirectory(Events)
add_subdirectory(Panels)
add_subdirectory(Plugins)
add_subdirectory(Tools)

target_link_libraries(SGUI_APPLICATION
    PUBLIC
        SGUI_CORE
        SGUI_GUI
    )
