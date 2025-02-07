NAME = materia
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g
SRCDIR = src
INCDIR = include
OBJDIR = obj

SRC = $(SRCDIR)/AMateria.cpp \
      $(SRCDIR)/Ice.cpp \
      $(SRCDIR)/Cure.cpp \
      $(SRCDIR)/Character.cpp \
      $(SRCDIR)/MateriaSource.cpp \
      $(SRCDIR)/main.cpp

OBJ = $(SRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

DEP = $(OBJ:.o=.d)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -MMD -MP -I$(INCDIR) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEP)

.PHONY: all clean fclean re
