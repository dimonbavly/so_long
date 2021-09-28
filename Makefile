NAME ?= so_long
SRC_PATH = src
SRCS = main.c
OBJS_PATH = obj
OBJS =  $(SRC:%.c=%.o)
CFLAGS = -Wall -Wextra -Werror
#-framework OpenGL -framework Appkit
test:
	gcc -g -v -Wall -Wextra -Werror -Iinclude  -c $(SRC_PATH)/main.c -o main.o
	gcc main.o -lmlx -framework OpenGL -framework AppKit -o $(NAME)
all:	$(LIBFT) $(GNL_OBJS) $(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) -Iinlude



norm:
	norminette include/* src/*
val:
	valgrind --leak-check=full --show-leak-kinds=all -s -q ./so_long
