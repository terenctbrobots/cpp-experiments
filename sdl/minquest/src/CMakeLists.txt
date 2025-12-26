set(HEADER_FILES 
        include/Game.h 
        backend/imgui_impl_opengl3.h 
        backend/imgui_impl_sdl3.h
        backend/imgui_impl_opengl3_loader.h)

add_executable(${PROJECT_NAME}
        ${HEADER_FILES}
        backend/imgui_impl_opengl3.cpp
        backend/imgui_impl_sdl3.cpp
        main.cpp
        Game.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE include backend)

target_link_libraries(${PROJECT_NAME} PRIVATE 
        SDL3::SDL3
        spdlog::spdlog
        imgui::imgui
        )
