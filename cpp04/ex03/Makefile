.PHONY: all clean fclean re

CC=c++
CFLAGS=-Wall -Wextra -Werror -std=c++98 -g #-Wno-shadow #-Wshadow 
VAL=valgrind --leak-check=full

SRCS:=main.cpp AMateria.cpp Cure.cpp Ice.cpp Character.cpp MateriaSource.cpp utils.cpp 
OBJS:=$(SRCS:%.cpp=%.o)
NAME=mat

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

val: $(NAME)
	$(VAL) ./$(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
