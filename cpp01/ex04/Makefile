.PHONY: all clean fclean re

CC=c++
CFLAGS=-Wall -Wextra -Werror -std=c++98 -g
VAL=valgrind --leak-check=full

SRCS:=main.cpp replacer.cpp
OBJS:=$(SRCS:%.cpp=%.o)
NAME=replace
TESTS=./tests

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

val: $(NAME)
	$(VAL) ./$(NAME) inp "hello" "goodbye" && echo "RESULT: " && cat inp.replace
	$(VAL) ./$(NAME) inp "Hello" "goodbye"

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -rf $(TESTS)

re: fclean all
