CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g
SRC = main.cpp Animal.cpp Dog.cpp Cat.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = Polymorphism

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(OBJ) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(EXEC)

re: fclean all

.PHONY: all clean fclean re