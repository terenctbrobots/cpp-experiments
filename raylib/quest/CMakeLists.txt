cmake_minimum_required(VERSION 3.15)
project(Quest LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRE ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#find_package(Catch2 REQUIRED)
find_package(raylib CONFIG REQUIRED)
find_package(spdlog REQUIRED)
find_package(nlohmann_json REQUIRED)
find_package(gaia REQUIRED)

#enable_testing() # Required to run 'ctest'

add_subdirectory(app)
#add_subdirectory(tests)
