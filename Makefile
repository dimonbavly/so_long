##---Project>>>--------------------------------
NAME = so_long
CC = clang
RM = rm -f
DEBUG_LEVEL = -g3
CFLAGS = -Wall -Wextra -Werror
LDLIBS =  -lft\
		  -lmlx_Linux\
		  -lXext\
		  -lX11\
		  -lm\
		  -lz
LDFLAGS = -L.\
		  -L$(MINILIBX_PATH)
HEADERS = $(filter-out $(MINILIBX_PATH)/mlx_int.h,\
		  $(foreach i_p, $(INCLUDE_PATHS),$(wildcard $(i_p)/*.h)))
INCLUDE_PATHS = include\
			   $(GNL_PATH)\
			   $(MINILIBX_PATH)\
			   $(LIBFT_PATH)
I_FLAGS = $(foreach i_p, $(INCLUDE_PATHS),-I$(i_p))
SRC_PATH = src
OBJ_PATH = obj
DEBUG_PATH = debug
SRCS = $(wildcard $(SRC_PATH)/*.c)
OBJS = $(SRCS:%.c=%.o)

##---<<<Project--------------------------------

##---Libft>>>----------------------------------
LIBFT_PATH = Libft
LIBFT = libft.a
##---<<<Libft----------------------------------

##---Minilibx>>>-------------------------------
MINILIBX_PATH = minilibx-linux
MINILIBX = libmlx_Linux.a
##---<<<Minilibx-------------------------------

##---GNL>>>------------------------------------
GNL_PATH = gnl
GNL_SRCS = $(wildcard $(GNL_PATH)/*.c)
GNL_OBJS = $(patsubst %.c, %.o, $(GNL_SRCS))
##---<<<GNL------------------------------------



.PHONY: all clean fclean re



test:	$(OBJS)
	
all:


$(NAME):	$(LIBFT) $(MLX) $(GNL_OBJS) $(OBJS)


$(OBJS):	$(SRCS)	$(HEADERS)
	$(CC) $(I_FLAGS) -c $(SRCS) -o $@



