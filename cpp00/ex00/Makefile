.PHONY: all clean fclean re

CC=c++
CFLAGS=-Wall -Wextra -Werror -std=c++98

SRCS:=megaphone.cpp
OBJS:=$(SRCS:%.cpp=%.o)
NAME=megaphone

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all	
