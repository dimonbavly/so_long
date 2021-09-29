
DEBUGFLAGS = -g3 -v

NAME ?= so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LD_PATHS = -LLibft
LDFLAGS = -lft -lmlx -framework OpenGL -framework AppKit
INCLUDE_PATHS = include gnl Libft
INCLUDES = $(foreach inc_p, $(INCLUDE_PATHS),-I$(inc_p))
SRC_PATH = src
SRCS =	$(wildcard $(SRC_PATH)/*.c)
GNL_PATH = gnl
GNL_SRCS = $(wildcard $(GNL_PATH)/*.c)
OBJ_PATH = obj
OBJS =  $(SRCS:$(SRC_PATH)/%.c=$(OBJ_PATH)/%.o) $(GNL_SRCS:$(GNL_PATH)/%.c=$(OBJ_PATH)/%.o)

LIBFT = Libft/libft.a
#test:
all:	$(NAME)

$(NAME):	$(OBJS)	$(LIBFT)
	$(CC) $(OBJS) $(LD_PATHS) $(LDFLAGS) -o $(NAME)
$(OBJ_PATH)/%.o:	$(SRC_PATH)/%.c
	$(CC) $(DEBUGFLAGS) $(CFLAGS) $(INCLUDES) -c $< -o $@
$(OBJ_PATH)/%.o:	$(GNL_PATH)/%.c
	$(CC) $(DEBUGFLAGS) $(CFLAGS) $(INCLUDES) -D BUFFER_SIZE=32 -c $< -o $@
$(LIBFT):
	$(MAKE) --directory=Libft mylibft

clean:
	rm -rf obj/* so_long
debug:	$(NAME)
norm:
	norminette include/* src/*
val:
	valgrind --leak-check=full --show-leak-kinds=all -s -q ./so_long
p:
	$(info $(OBJS))

