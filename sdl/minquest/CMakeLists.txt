cmake_minimum_required(VERSION 3.15)
project(minquest LANGUAGES CXX)

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

target_include_directories(${PROJECT_NAME} PRIVATE src/include src/backend)

target_link_libraries(${PROJECT_NAME} PRIVATE 
        SDL3::SDL3
        spdlog::spdlog
        imgui::imgui
        )
