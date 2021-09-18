#include "ft_so_long.h"

/*
** \file ft_sl_utils.c
*/
static t_map ft_sl_init_map(char *path);
static void ft_sl_init_hero(t_hero *hero, t_map map);

void ft_sl_init_res(t_res *res, char *path)
{
	*res = (t_res){(t_hero){(t_pos){0, NULL}}, (t_exit){(t_pos){0, NULL}},\
		(t_thing){(t_pos){0,NULL}}, NULL,\
			(t_map){0, 0, NULL, NULL},0};
	res->map = ft_sl_init_map(path);
	ft_sl_init_hero(&(res->hero), res->map);
}

static t_map ft_sl_init_map(char *path)
{
	t_map map;
	t_dllist *current;
	t_dllist *tmp;
	int fd;
	int ret;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		//error file opening
		exit(EXIT_FAILURE);
	}
	ret = -1;
	current = map.dllst;
	map.height = 0;
	while (1)
	{
		//!!! or use list of strings ???
		tmp = ft_dltail(current);
		ft_dlinsertafter(&tmp, ft_dllstnew(NULL));
		ret = get_next_line(fd, (char**)&(ft_dltail(current)->content));
		if (ret < 0)
			break ;
		current = current->next;
	}
	ft_sl_check_map(&map);
	map.width = ft_strlen((char*)map.dllst->content);
	map.title = &path[0]; //basename
	return (map);
}

static void ft_sl_init_hero(t_hero *hero, t_map map)
{
	char *occ;

	while (map.dllst)
	{
		occ = ft_strchr((const char *)map.dllst->content, 'P');
		if (occ)
		{
			hero->pos = (t_pos){occ - (char *)map.dllst->content, map.dllst};
		}
		else
		{
		   	if(map.dllst->next != NULL)
				map.dllst = map.dllst->next;
		}
	}
	return ;
}

