#include "ft_so_long.h"

/*
** \file ft_sl_utils.c
*/

static void ft_sl_init_hero(t_hero *hero, t_map map);

void ft_sl_init_res(t_res *res, char *path)
{
	res->map = ft_sl_init_map(path);
	ft_sl_init_hero(&(res->hero), res->map);
	res->exit = (t_exit){ft_get_exit_pos(res->map)};
	res->get_thing_pos(&(res->thing), res->map);
}

