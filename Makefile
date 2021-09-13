OS = $(shell uname)
CFLAGS = -Wextra -Werror -Wall
CFLAGS += -I/usr/include -Iminilibx_linux -O3
CFLAGS += -I/gnl -D BUFFER_SIZE=32
CFLAGS += -I.
NAME = so_long
LIBFT = libft.a
MINILIBX_REL_PATH = ./minilibx-linux/
MINILIBX_UNAME = libmlx_$(shell uname).a
MLX = $(addprefix $(MINILIBX_REL_PATH), $(MINILIBX_UNAME))
SRCS = $(addsuffix .c, $(NAME))\
	ft_sl_utils.c\
	gnl/get_next_line.c\
	gnl/get_next_line_utils.c\
	ft_sl_logic.c\
	ft_map_check.c\
	ft_sl_utils.c\

OBJS = $(SRCS:.c=.o)
CC = gcc


test:
	@echo -e "\033[38;5;226;48;5;16m $(MAKEFLAGS)\033[0m"
all:	$(NAME)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f so_long

re:

$(NAME):	 $(MLX) $(OBJS)

$(MLX):
	@echo -e "\033[38;5;226;48;5;16m ------------>mlx\033[0m"
	make --directory=$(MINILIBX_REL_PATH)
%.o:	%.c
	@echo -e "\033[38;5;226;48;5;16m------------\>$@\033[0m"
	$(CC) $(CFLAGS) -c $< -o $@
