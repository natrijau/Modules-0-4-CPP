# Compiler
CXX = c++

# Compiler flags
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Source file
SRC = megaphone.cpp

# Object file
OBJ = megaphone.o

# Output executable
EXEC = megaphone

# Default target
all: $(EXEC)

# Ensure the build directory exists
$(EXEC): $(OBJ)
	$(CXX) $(OBJ) -o $@

# Compile source file to object file
$(OBJ): $(SRC)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up object file
clean:
	rm -f $(OBJ)

# Full clean up including the executable
fclean: clean
	rm -f $(EXEC)

# Rebuild the project
re: fclean all

.PHONY: all clean fclean re
