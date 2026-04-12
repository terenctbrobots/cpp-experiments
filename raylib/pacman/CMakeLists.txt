cmake_minimum_required(VERSION 3.15)
project(pacman LANGUAGES CXX)

# configure_file(
#     "${CMAKE_CURRENT_SOURCE_DIR}/src/include/Config.h"
#     "${CMAKE_CURRENT_BINARY_DIR}/Config.h"
# )

find_package(raylib CONFIG REQUIRED)
find_package(spdlog REQUIRED)
find_package(nlohmann_json REQUIRED)

# add_library(GameCore STATIC
#         lib/include/Image.h
#         lib/include/Resources.h
#         lib/include/Resource.h
#         lib/include/Sprite.h
#         lib/Image.cpp
#         lib/Resources.cpp
#         lib/Resource.cpp
#         lib/Sprite.cpp
# )

# target_include_directories(GameCore PRIVATE
#         lib/include
# )

set(HEADER_FILES 
        lesson1/include/Game.h) 
#         src/backend/imgui_impl_opengl3.h 
#         src/backend/imgui_impl_sdl3.h
#         src/backend/imgui_impl_opengl3_loader.h)

add_executable(${PROJECT_NAME}
        ${HEADER_FILES}
        lesson1/main.cpp
        lesson1/Game.cpp
 
)

target_include_directories(${PROJECT_NAME} PRIVATE 
        ${CMAKE_CURRENT_BINARY_DIR} 
        lesson1/include
) 

target_link_libraries(${PROJECT_NAME} PRIVATE 
        raylib::raylib
        spdlog::spdlog
        nlohmann_json::nlohmann_json
        )

# Define the source and destination directories
# set(ASSETS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/assets")
# set(DEST_DIR "$<TARGET_FILE_DIR:${PROJECT_NAME}>/assets")

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
# add_custom_command(
#         TARGET ${PROJECT_NAME}
#         PRE_BUILD
#         COMMAND ${CMAKE_COMMAND} -E create_symlink
#             "${ASSETS_DIR}"
#             "${DEST_DIR}"
# )