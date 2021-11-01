add_library(SGUI_APPLICAION)

set(INCROOT ${SGUI_SOURCE_DIR}/include/Application)
set(SRCROOT ${SGUI_SOURCE_DIR}/src/Application)

target_include_directories(SGUI_APPLICAION
    PUBLIC
        ${INCROOT}
    )

target_sources(SGUI_APPLICAION
    PUBLIC
        ${INCROOT}/Application.hpp
        ${INCROOT}/MainPanel.hpp
    PRIVATE
        ${SRCROOT}/Application.cpp
        ${SRCROOT}/MainPanel.cpp
    )

target_link_libraries(SGUI_APPLICAION
    PUBLIC
        SGUI_CORE
        SGUI_GUI
        SGUI_PLATFORM
    )
