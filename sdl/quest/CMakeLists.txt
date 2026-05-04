cmake_minimum_required(VERSION 3.15)
project(Quest LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

#find_package(Catch2 REQUIRED)
find_package(SDL3_image REQUIRED)
find_package(SDL3 REQUIRED)
find_package(spdlog REQUIRED)
find_package(imgui REQUIRED)
find_package(nlohmann_json REQUIRED)
find_package(gaia REQUIRED)

#enable_testing() # Required to run 'ctest'

add_subdirectory(lib)
add_subdirectory(app)
#add_subdirectory(tests)