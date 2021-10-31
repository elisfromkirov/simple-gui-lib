add_library(SGUI_GUI)






add_subdirectory(Event)
add_subdirectory(Handler)
add_subdirectory(Widgets)

target_link_libraries(SGUI_GUI
    PUBLIC
        SGUI_CORE
        SGUI_PLATFORM
    )
