NAME = ft_gkrellm
CC = clang++
CFLAGS = -Wall -Wextra -Werror -std=c98 -lncurses
SRC = $(wildcard src/*.cpp)
OBJECT = $(SRC:.cpp=.o)

SDL = -F./frameworks
SDL_FLAGS = -rpath ./frameworks -framework SDL2 -framework SDL2_ttf

%.o: %.c
	$(CC) $(CFLAGS) $(SDL) -c -o $@ $<

$(NAME): $(OBJECT)
	$(CC) $(CFLAGS) $(OBJECT) $(SDL) $(SDL_FLAGS) -o $@

all: $(NAME)

clean:
	@/bin/rm -f $(OBJECT)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
