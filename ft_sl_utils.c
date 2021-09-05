#include "ft_so_long.h"

/*
** \file ft_sl_utils.c
*/
static t_map ft_sl_init_map(char *path);
static void ft_sl_init_hero(t_hero *hero, t_map map);
void ft_sl_check_map(t_map *map);

void ft_sl_init_res(t_res *res, char *path)
{
	res->map = ft_sl_init_map(path);
	ft_sl_init_hero(&(res->hero), res->map);
	res->exit = (t_exit){ft_get_exit_pos(res->map)};
	res->get_thing_pos(&(res->thing), res->map);
}

static t_map ft_sl_init_map(char *path)
{
	t_map map;
	int fd;
	int ret;
	int i;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		//error file opening
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (1)
	{
		//!!! or use list of strings ???
		ret = get_next_line(fd, map.content + i++);
		if (ret < 0)
			break ;
	}
	map.height = i;
	ft_sl_check_map(map);
	map.width = ft_strlen(map.content);
	map.title = &path[0]; //basename
}

void ft_sl_check_map(t_map *map);
{
	unsigned int i;

	while (1)
}


static void ft_sl_init_hero(t_hero *hero, t_map map)
{
	return ;
}


