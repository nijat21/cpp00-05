.PHONY: all val clean fclean re

CC=c++
CFLAGS=-Wall -Wextra -Werror -std=c++98 -g
VAL=valgrind --leak-check=full

SRCS:=main.cpp Zombie.cpp zombieHorde.cpp
OBJS:=$(SRCS:%.cpp=%.o)
NAME=horde

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

val: $(NAME)
	$(VAL) ./$(NAME) 5 "black holed student"

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
