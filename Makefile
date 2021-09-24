##---Project>>>--------------------------------
NAME ?= so_long
MODE ?=	opengl
OS := $(shell uname)
CC := clang
RM := rm -f
DEBUG_FLAGS := -g -O0
CFLAGS := -Wall -Wextra -Werror
LDLIBS =  -lft
ifeq ($(OS),Darwin)
	LDLIBS += -lmlx\
			  -framework OpenGL\
			  -framework AppKit
else
	LDLIBS += -lmlx_Linux\
			  -lXext\
			  -lX11\
			  -lm\
			  -lz
endif
LDFLAGS = -L$(LIBFT_PATH)\
		  -L$(MINILIBX_PATH)
HEADERS = $(filter-out $(MINILIBX_PATH)/mlx_int.h,\
		  $(foreach i_p, $(INCLUDE_PATHS),$(wildcard $(i_p)/*.h)))
INCLUDE_PATHS = include\
			   $(GNL_PATH)\
			   $(MINILIBX_PATH)\
			   $(LIBFT_PATH)
I_FLAGS = $(foreach i_p, $(INCLUDE_PATHS),-I$(i_p))
SRC_PATH := src
OBJ_PATH := obj
DEBUG_PATH := dbg
SRCS = $(wildcard $(SRC_PATH)/*.c)
OBJS = $(patsubst $(SRC_PATH)%,$(OBJ_PATH)%,$(SRCS:%.c=%.o))

##---<<<Project--------------------------------

##---Libft>>>----------------------------------
LIBFT_PATH = Libft
LIBFT = libft.a
##---<<<Libft----------------------------------

##---Minilibx>>>-------------------------------
ifeq ($(OS),Darwin)
ifneq ($(MODE),mms)
	MINILIBX_PATH = minilibx-darwin
	MINILIBX = libmlx.a
else
	MINILIBX_PATH = minilibx-mms
	MINILIBX = libmlx.dylib
endif
else
	MINILIBX_PATH = minilibx-linux
	MINILIBX = libmlx_Linux.a
endif
##---<<<Minilibx-------------------------------

##---GNL>>>------------------------------------
GNL_PATH = gnl
GNL_SRCS = $(wildcard $(GNL_PATH)/*.c)
GNL_OBJS = $(patsubst $(GNL_PATH)/%.c,$(OBJ_PATH)/%.o, $(GNL_SRCS))
GNL_I_FLAGS = -Ignl
GNL_HEADER = $(GNL_PATH)/get_next_line.h
##---<<<GNL------------------------------------


##---Rules>>>----------------------------------
.PHONY: all clean fclean re test debug

test:
	$(info $(LDLIBS))
all:	$(NAME)


$(NAME):	$(LIBFT_PATH)/$(LIBFT) $(MINILIBX_PATH)/$(MINILIBX)\
   	$(GNL_OBJS) $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) $(GNL_OBJS) $(LDLIBS) -o $(NAME)

## make $(OBJS)
$(OBJ_PATH)/%.o:	$(SRC_PATH)/%.c $(HEADERS) | $(OBJ_PATH)
	$(CC) $(CFLAGS) $(I_FLAGS) -c $< -o $@

$(OBJ_PATH)/%.o:	$(GNL_PATH)/%.c $(GNL_HEADER) | $(OBJ_PATH)
	$(CC) $(CFLAGS) $(GNL_I_FLAGS) -D BUFFER_SIZE=32 -c $< -o $@

#$(GNL_OBJS):	$(GNL_SRCS) $(GNL_HEADER) $(OBJ_PATH)
#	$(CC) $(CFLAGS) $(GNL_I_FLAGS) -D BUFFER_SIZE=32 -c $< -o $@

$(MINILIBX_PATH)/$(MINILIBX):
	$(MAKE) --directory=$(MINILIBX_PATH)

$(LIBFT_PATH)/$(LIBFT):
	$(MAKE) --directory=$(LIBFT_PATH) mylibft

$(OBJ_PATH):
	mkdir $@

clean:
	$(RM)r $(OBJ_PATH)

fclean:	clean
	$(RM)r $(DEBUG_PATH)
	$(RM) $(NAME)
	$(RM) $(DEBUG_PATH)/$(NAME)
	$(MAKE) --directory=$(MINILIBX_PATH) clean
	$(MAKE) --directory=$(LIBFT_PATH) fclean

re: fclean all
debug:	CFLAGS += $(DEBUG_FLAGS)
debug:	$(LIBFT_PATH)/$(LIBFT) $(MINILIBX_PATH)/$(MINILIBX)\
   	$(GNL_OBJS) $(OBJS) | $(DEBUG_PATH)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) $(GNL_OBJS) $(LDLIBS) -o $(DEBUG_PATH)/$(NAME)

$(DEBUG_PATH):
	mkdir -p $@