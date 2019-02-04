NAME = ft_gkrellm
CC = clang++
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -std=c98 -lncurses
SRC = $(wildcard src/*.cpp)

OBJECT = $(SRC:.cpp=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJECT)
	$(CC) $(CFLAGS) $(OBJECT) -o $@

all: $(NAME)

clean:
	@/bin/rm -f $(OBJECT)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
