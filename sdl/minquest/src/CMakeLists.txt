
set(HEADER_FILES include/Game.h)

add_executable(${PROJECT_NAME}
        ${HEADER_FILES}
        include/Game.h
        main.cpp
        Game.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE include)

target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3)
