# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Source files
SRC = tests.cpp Account.cpp

# Object files
OBJ = $(SRC:.cpp=.o)

# Output executable
EXEC = Account

# Default target
all: $(EXEC)

# Ensure the build directory exists
$(EXEC): $(OBJ)
	$(CXX) $(OBJ) -o $(EXEC)

# Compile source file to object file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up object files
clean:
	rm -f $(OBJ)

# Full clean up including the executable
fclean: clean
	rm -f $(EXEC)

# Rebuild the project
re: fclean all

.PHONY: all clean fclean re
