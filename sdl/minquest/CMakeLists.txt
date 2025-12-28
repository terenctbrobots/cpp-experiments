cmake_minimum_required(VERSION 3.15)
project(minquest LANGUAGES CXX)

if(WIN32)
        set(PLATFORM_WINDOWS TRUE)
elseif(APPLE)
        set(PLATFORM_APPLE TRUE)
else()
        set(PLATFORM_UNIX TRUE)
endif()

configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/src/include/Config.h.in"
    "${CMAKE_CURRENT_BINARY_DIR}/Config.h"
)

find_package(SDL3 REQUIRED)
find_package(spdlog REQUIRED)
find_package(imgui REQUIRED)

set(HEADER_FILES 
        src/include/Game.h 
        src/backend/imgui_impl_opengl3.h 
        src/backend/imgui_impl_sdl3.h
        src/backend/imgui_impl_opengl3_loader.h)

add_executable(${PROJECT_NAME}
        ${HEADER_FILES}
        src/backend/imgui_impl_opengl3.cpp
        src/backend/imgui_impl_sdl3.cpp
        src/main.cpp
        src/Game.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_BINARY_DIR} src/include src/backend ) 

target_link_libraries(${PROJECT_NAME} PRIVATE 
        SDL3::SDL3
        spdlog::spdlog
        imgui::imgui
        )
