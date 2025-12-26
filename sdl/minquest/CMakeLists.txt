cmake_minimum_required(VERSION 3.15)
project(minquest LANGUAGES CXX)

find_package(SDL3 REQUIRED)
find_package(spdlog REQUIRED)
find_package(imgui REQUIRED)

# Add Source directory
add_subdirectory(src)