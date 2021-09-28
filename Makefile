
DEBUGFLAGS = -g3 -v

NAME ?= so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -lmlx -framework OpenGL -framework AppKit
INCLUDE_PATH = include
INCLUDES = -I$(INCLUDE_PATH)
SRC_PATH = src
SRCS =	$(wildcard $(SRC_PATH)/*.c)
OBJ_PATH = obj
OBJS =  $(SRCS:$(SRC_PATH)/%.c=$(OBJ_PATH)/%.o)
CFLAGS = -Wall -Wextra -Werror
#-framework OpenGL -framework Appkit

#test:
all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)
$(OBJ_PATH)/%.o:	$(SRC_PATH)/%.c
	$(CC) $(DEBUGFLAGS) $(CFLAGS) $(INCLUDES) -c $< -o $@
clean:
	rm -rf obj/* so_long
debug:	$(NAME)
norm:
	norminette include/* src/*
val:
	valgrind --leak-check=full --show-leak-kinds=all -s -q ./so_long
p:
	$(info $(LDFLAGS))

