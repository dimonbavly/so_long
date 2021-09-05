#ifndef FT_SO_LONG_H
# define FT_SO_LONG_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h> 
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define PIXEL 16

typedef struct s_coordinates
{
	int x;
	int y;
}t_pos;

typedef struct s_hero
{
	t_pos pos;
}t_hero;

typedef struct s_collectible_thing
{
	t_pos pos;
}t_thing;

typedef struct s_exit
{
	t_pos pos;
}t_exit;

typedef struct s_map
{
	int width;
	int height;
	char *title;
	char **content;
	
}t_map;

typedef struct s_resuorces
{
	t_hero hero;
	t_exit exit;
	t_thing thing;
	void (*get_thing_pos) (t_thing *thing, char **content);
	t_map map;
	int way;
}t_res;

#endif
