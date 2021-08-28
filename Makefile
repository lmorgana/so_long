CC = gcc

NAME = so_long

CFLAGS = -Wall -Wextra -Werror

HEADERS = so_long.h

SRC = 	so_long.c utils.c map/get_next_line.c \
		map/ft_get_map.c 	map/get_next_line_utils.c map/ft_check_map.c \
		hero/ft_go_utils.c hero/ft_cell.c

OBJECTS = $(patsubst %.c, %.o, $(SRC))

LIBFT_LIB = libft/libft.a

all: $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(LIBFT_LIB): 
	$(MAKE) -C libft bonus

$(NAME): $(OBJECTS) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT_LIB) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) -lmx
clean:
	 $(MAKE) -C libft clean
	-rm -f $(OBJECTS)

fclean:
	$(MAKE) -C libft fclean
	-rm -f $(OBJECTS)
	-rm -f $(NAME)

re: fclean all