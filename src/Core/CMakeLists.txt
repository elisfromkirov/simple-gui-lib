add_library(SGUI_CORE)

find_package(SFML COMPONENTS graphics REQUIRED)

target_include_directories(SGUI_CORE
    PUBLIC
        ${SGUI_SOURCE_DIR}/include
    )

add_subdirectory(EventManager)
add_subdirectory(LogManager)
add_subdirectory(Math)
add_subdirectory(Platform)
add_subdirectory(ResourceManager)

target_link_libraries(SGUI_CORE
    PUBLIC
        m
        sfml-graphics
    )
