add_library(GameCore
    src/TextureManager.cpp 
)

# PUBLIC means anyone linking to this library also gets these include paths
target_include_directories(GameCore PUBLIC include)

# Link the Conan dependency to the library
target_link_libraries(GameCore PRIVATE
        SDL3_image::SDL3_image
        SDL3::SDL3
        spdlog::spdlog
        imgui::imgui
        nlohmann_json::nlohmann_json
        gaia::gaia
)