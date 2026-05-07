
if(UNIX)
set(IMGUI_BACKEND
        backend/imgui_impl_opengl3.h 
        backend/imgui_impl_sdl3.h
        backend/imgui_impl_opengl3_loader.h
        backend/imgui_impl_opengl3.cpp
        backend/imgui_impl_sdl3.cpp)
endif()

add_library(GameCore
    ${IMGUI_BACKEND}
    src/Game.cpp
    src/TextureManager.cpp 
)

# PUBLIC means anyone linking to this library also gets these include paths
target_include_directories(GameCore PUBLIC include backend)

# Link the Conan dependency to the library
target_link_libraries(GameCore PRIVATE
        SDL3_image::SDL3_image
        SDL3::SDL3
        spdlog::spdlog
        imgui::imgui
        nlohmann_json::nlohmann_json
        gaia::gaia
)