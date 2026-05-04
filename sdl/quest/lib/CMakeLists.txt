add_library(GameCore
    src/TextureManager.cpp 
)

# PUBLIC means anyone linking to this library also gets these include paths
target_include_directories(GameCore PUBLIC include)

# Link the Conan dependency to the library
target_link_libraries(GameCore PRIVATE fmt::fmt)