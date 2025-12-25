cmake_minimum_required(VERSION 3.15)
project(minquest LANGUAGES CXX)

find_package(SDL3 REQUIRED)

set(HEADER_FILES src/include/Game.h)

add_executable(${PROJECT_NAME}
        ${HEADER_FILES}
        src/main.cpp
        src/Game.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE src/include)

target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3)
