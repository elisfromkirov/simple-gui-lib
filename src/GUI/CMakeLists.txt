add_library(SGUI_GUI)

target_include_directories(SGUI_GUI
    PUBLIC
        ${SGUI_SOURCE_DIR}/include
    )

add_subdirectory(Events)
add_subdirectory(Styles)
add_subdirectory(Widgets)

target_link_libraries(SGUI_GUI
    PUBLIC
        SGUI_CORE
    )
