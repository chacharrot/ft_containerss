NAME = Containers
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC =	Containers.cpp

INC =	vector.hpp\
		map.hpp\
		AVLTree.hpp\
		map_iterator.hpp\
		enable_if.hpp\
		iteratorTraits.hpp\
		iterator.hpp\
		pair.hpp\
		reverseiterator.hpp\
		utils.hpp\

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ) $(INC)
	@$(CC) -I. $(OBJ) -o $(NAME)

%.o: %.cpp $(INC)
	@$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
