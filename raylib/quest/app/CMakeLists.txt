
# Create the executable
add_executable(quest 
    src/main.cpp
    src/Player.cpp
    src/Game.cpp
    src/Animation.cpp
    src/Systems/MovementSystem.cpp
    src/Systems/RenderSystem.cpp
    )

target_include_directories(quest PUBLIC include)

# Link the internal library. 
# Because of the 'PUBLIC' include in my_lib, my_app can find the headers automatically.
target_link_libraries(quest PRIVATE
    raylib
    spdlog::spdlog
    nlohmann_json::nlohmann_json
    gaia::gaia
    )

# Define the source and destination directories
set(ASSETS_DIR "${CMAKE_SOURCE_DIR}/assets")
set(DEST_DIR "$<TARGET_FILE_DIR:quest>/assets")

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
        TARGET quest
        PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E create_symlink
            "${ASSETS_DIR}"
            "${DEST_DIR}"
)    