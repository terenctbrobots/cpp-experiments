cmake_minimum_required(VERSION 3.15)
project(minquest LANGUAGES CXX)

find_package(SDL3 REQUIRED)

# Add Source directory
add_subdirectory(src)