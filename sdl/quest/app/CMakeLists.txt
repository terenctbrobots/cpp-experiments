# Create the executable
add_executable(quest src/main.cpp)

# Link the internal library. 
# Because of the 'PUBLIC' include in my_lib, my_app can find the headers automatically.
target_link_libraries(quest PRIVATE GameCore)