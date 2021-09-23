#ifndef FT_SO_LONG_H
# define FT_SO_LONG_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h> 
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <libft.h>
# include <get_next_line.h>
# include <mlx.h>

# define PIXEL 16
# define MAP_CHARACTERS "01CEP"
# define NUM_MAP_CHARACTERS 5

typedef struct s_coordinates
{
	int x;
	void *y;
}t_pos;

typedef struct s_image
{
	char *path;
	int width;
	int height;
}t_img;

typedef struct s_wall
{
	t_pos pos;
	t_img img;
}t_wall;

typedef struct s_empty_field
{
	t_pos pos;
	t_img img;
}t_empty;

typedef struct s_hero
{
	t_pos pos;
	t_img img;
}t_hero;

typedef struct s_collectible_thing
{
	t_pos pos;
	t_img img;
}t_thing;

typedef struct s_exit
{
	t_pos pos;
	t_img img;
}t_exit;


typedef struct s_map
{
	int width;
	int height;
	t_hero hero;
	t_exit exit;
	t_thing thing;
	t_wall wall;
	t_empty empty;
	char *title;
	t_dllist *dllst;
}t_map;

typedef struct s_resources
{
	void *mlx;
	void *mlx_win;
	t_map map;
	int way;
}t_res;


void ft_sl_run(char *path);
void ft_sl_game(t_res *res);
void ft_sl_check_map(t_map *map);
void ft_sl_init_res(t_res **res, char *path);
void ft_sl_show_map(void *mlx_ptr, void *win_ptr, t_res *res);
#endif
