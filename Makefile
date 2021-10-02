
DEBUGFLAGS =
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
OBJS =  $(SRCS:$(SRC_PATH)/%.c=$(OBJ_PATH)/%.o) \
	$(GNL_SRCS:$(GNL_PATH)/%.c=$(OBJ_PATH)/%.o)

LIBFT = Libft/libft.a

.PHONY: all, re, clean, fclean, debug

all:	$(NAME)

$(NAME):	$(OBJS)	$(LIBFT)
	$(CC) $(OBJS) $(LD_PATHS) $(LDFLAGS) -o $(NAME)

$(OBJ_PATH)/%.o:	$(SRC_PATH)/%.c | $(OBJ_PATH)
	$(CC) $(DEBUGFLAGS) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_PATH)/%.o:	$(GNL_PATH)/%.c	| $(OBJ_PATH)
	$(CC) $(DEBUGFLAGS) $(CFLAGS) $(INCLUDES) -D BUFFER_SIZE=32 -c $< -o $@

$(OBJ_PATH):
	mkdir -p $@
$(LIBFT):
	$(MAKE) --directory=Libft mylibft

clean:
	rm -rf obj

fclean:	clean
	make --directory=Libft fclean
	rm -rf $(NAME)

re:	fclean all

debug:	DEBUGFLAGS = -g3 -v
debug:	$(NAME)

norm:
	norminette include/* src/* Libft/*.c Libft/*.h gnl/*.c gnl/*.h

