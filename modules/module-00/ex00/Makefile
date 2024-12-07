# Compiler
CXX = c++

# Compiler flags
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Source file
SRC = megaphone.cpp

# Object file
OBJ = megaphone.o

# Output executable
TARGET = megaphone

# Default target
all: $(TARGET)

# Ensure the build directory exists
$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $@

# Compile source file to object file
$(OBJ): $(SRC)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up object file
clean:
	rm -f $(OBJ)

# Full clean up including the executable
fclean: clean
	rm -f $(TARGET)

# Rebuild the project
re: fclean all

.PHONY: all clean fclean re
