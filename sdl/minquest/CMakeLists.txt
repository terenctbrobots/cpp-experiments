cmake_minimum_required(VERSION 3.28.3)

project(minquest CXX)

#Find SDL3 package
find_package(SDL3 CONFIG REQUIRED)

set(CMAKE_CXX_STANDARD 17)


add_executable(minquest main.cpp)
target_link_libraries(minquest PRIVATE SDL3::SDL3)
