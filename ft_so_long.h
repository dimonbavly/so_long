#ifndef FT_SO_LONG_H
# define FT_SO_LONG_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h> 
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "Libft/libft.h"

# define PIXEL 16
# define MAP_CHARACTERS "01CEP" //wall walk
# define NUM_MAP_CHARACTERS 5

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
	t_dllist *dllst;
	
}t_map;

typedef struct s_resources
{
	t_hero hero;
	t_exit exit;
	t_thing thing;
	void (*get_thing_pos) (t_thing *thing, char **map_content);
	t_map map;
	int way;
}t_res;


void ft_sl_run(char *path);
void ft_sl_game(t_res *res);

#endif
