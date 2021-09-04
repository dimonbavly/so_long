OS = $(shell uname)
CFLAGS = -Wextra -Werror -Wall
CFLAGS += -I/usr/include -Iminilibx_linux -O3
NAME = so_long
LIBFT = libft.a
MINILIBX_REL_PATH = ./minilibx-linux/
MINILIBX_UNAME = libmlx_$(shell uname).a
MLX = $(addprefix $(MINILIBX_REL_PATH), $(MINILIBX_UNAME))
SRCS = $(addsuffix .c, $(NAME))
OBJS = $(SRCS:.c=.o)
CC = gcc


test:
	@echo $(MLX)
all:	$(NAME)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f so_long

re:

$(NAME):	 $(MLX)

$(MLX):
	make --directory=$(MINILIBX_REL_PATH)
%.o:	%.c
	$(CC) $(CFLAGS) -c $< -o $@
