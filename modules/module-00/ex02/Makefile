CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = tests.cpp Account.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = Accounts
all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(OBJ) -o $(EXEC)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(EXEC)

re: fclean all

.PHONY: all clean fclean re
