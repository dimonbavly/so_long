##---Project>>>--------------------------------
NAME = so_long
CC = clang
RM = rm -f
DEBUG_LEVEL = -g3
CFLAGS = -Wall -Wextra -Werror
LDLIBS =  -lft\
		  -lmlx\
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
OBJS = $(patsubst $(SRC_PATH)%,$(OBJ_PATH)%,$(SRCS:%.c=%.o))

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
GNL_OBJS = $(patsubst $(GNL_PATH)/%.c,$(OBJ_PATH)/%.o, $(GNL_SRCS))
GNL_I_FLAGS = -Ignl
GNL_HEADER = $(GNL_PATH)/get_next_line.h
##---<<<GNL------------------------------------



.PHONY: all clean fclean re test



test:	$(MINILIBX)
		
all:


$(NAME):	$(LIBFT) $(MINILIBX) $(GNL_OBJS) $(OBJS)

## make $(OBJS)
$(OBJS):	$(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) $(I_FLAGS) -c $< -o $@

$(GNL_OBJS):	$(GNL_SRCS) $(GNL_HEADER)
	$(CC) $(CFLAGS) $(GNL_I_FLAGS) -c $< -o $@

$(MINILIBX):
	$(MAKE) --directory=$(MINILIBX_PATH)

$(OBJ_PATH):
	mkdir obj

