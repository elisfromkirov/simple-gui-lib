add_library(SGUI_CORE)

target_include_directories(SGUI_CORE
    PUBLIC
        ${SGUI_SOURCE_DIR}/include
    )

add_subdirectory(Application)
add_subdirectory(EventManager)
add_subdirectory(Math)
add_subdirectory(LogManager)

target_link_libraries(SGUI_CORE
    PRIVATE
        m
    )
