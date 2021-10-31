add_library(SGUI_APPLICAION)

set(INCROOT ${SGUI_SOURCE_DIR}/include/Application)

target_include_directories(SGUI_APPLICAION
    PUBLIC
        ${INCROOT}
    )

target_sources(SGUI_APPLICAION
    PUBLIC
        ${INCROOT}/Application.hpp
    PRIVATE
        Application.cpp
    )

target_link_libraries(SGUI_APPLICAION
    PUBLIC
        SGUI_CORE
        SGUI_GUI
        SGUI_PLATFORM
    )
