cmake_minimum_required(VERSION 3.15)
project(minquest LANGUAGES CXX)

find_package(SDL3 REQUIRED)

add_executable(${PROJECT_NAME}
        src/main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3)
