.PHONY: all clean fclean re

CC=c++
CFLAGS=-Wall -Wextra -Werror -std=c++98 -fsanitize=address -g

SRCS:=main.cpp replacer.cpp
OBJS:=$(SRCS:%.cpp=%.o)
NAME=replace

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

valgrind:

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all