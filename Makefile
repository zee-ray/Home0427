# Compiler
CXX = g++
CXXFLAGS = -Wall -g

# Source files
SRCS = main.cpp Matrix.cpp
OBJS = $(SRCS:.cpp=.o)

# Output executable
TARGET = my_program

# Default rule
all: $(TARGET)

# Link object files into executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile .cpp to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

# Clean build files
clean:
	rm -f $(OBJS) $(TARGET)
