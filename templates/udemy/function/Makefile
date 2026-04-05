# Specify the compiler
CXX = g++

# Compilation flags
# -Wall: enables all compiler's warning messages
# -g: adds debugging information to the executable
CXXFLAGS = -Wall -g

# The build target (the name of your executable)
TARGET = main

# The default rule to build the program
all: $(TARGET)

$(TARGET): main.cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) main.cpp

# Rule to remove the executable
clean:
	rm -f $(TARGET)