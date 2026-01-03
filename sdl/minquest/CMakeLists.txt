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

find_package(SDL3_image)
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
        SDL3_image::SDL3_image
        SDL3::SDL3
        spdlog::spdlog
        imgui::imgui
        )

# Define the source and destination directories
set(ASSETS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/assets")
set(DEST_DIR "$<TARGET_FILE_DIR:${PROJECT_NAME}>/assets")

# Add a custom command to run after 'minquest' is built
# add_custom_command(
#     TARGET ${PROJECT_NAME}
#     POST_BUILD
#     COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different
#             "${ASSETS_DIR}"
#             "${DEST_DIR}"
#     COMMENT "Copying assets to build directory for minquest"
# )

# Create a symlink, which is faster
add_custom_command(
        TARGET ${PROJECT_NAME}
        PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E create_symlink
            "${ASSETS_DIR}"
            "${DEST_DIR}"
)