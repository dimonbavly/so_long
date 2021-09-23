#include "ft_so_long.h"

/*
** \file ft_sl_utils.c
*/
static t_map ft_sl_init_map(char *path);
static void ft_sl_init_hero(t_hero *hero, t_map map);

void ft_sl_init_res(t_res **res, char *path)
{
	if (res == NULL)
		{
			//error_???
			exit(EXIT_FAILURE);
		}
	*res = malloc (sizeof (**res));
	if (*res == NULL)
		{
			//m alloc error
			exit(EXIT_FAILURE);
		}

    ft_memcpy(*res, &((t_res)
    {
        (t_map)
        {
            0, 0,
            (t_hero)
            {
                (t_pos)
                {
                    0, 0
                },
                (t_img)
                {
                    NULL, WIDTH, HEIGHT
                }
            },
            (t_exit)
            {
                (t_pos)
                {
                    0, 0
                },
                (t_img)
                {
                    NULL, WIDTH, HEIGHT
                }
            },
            (t_thing)
            {
                (t_pos)
                {
                    0,0
                },
                (t_img)
                {
                    NULL, WIDTH, HEIGHT
                }
            },
            (t_wall)
            {
                (t_pos)
                {
                    0,0
                },
                (t_img)
                {
                    NULL, WIDTH, HEIGHT
                }
            },
            (t_empty)
            {
                (t_pos)
                {
                    0,0
                    },
                    (t_img)
                    {
                    NULL, WIDTH, HEIGHT
                    }
            },
            NULL,
            NULL
        },
        0
    }),sizeof (t_res));
	(*res)->map = ft_sl_init_map(path);
	ft_sl_init_hero(&((*res)->map.hero), (*res)->map);
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
	if (map.dllst == NULL)
		map.dllst = ft_dllstnew(NULL);
	current = map.dllst;
	map.height = 0;
	while (1)
	{
		tmp = ft_dltail(current);
		ret = get_next_line(fd, (char**)&tmp->content);
		if (ret <= 0)
			break ;
		ft_dlinsertafter(&tmp, ft_dllstnew(NULL));
	}
	ft_sl_check_map(&map);
	map.width = ft_strlen((char*)map.dllst->content);
	map.height = ft_dllstsize(map.dllst);
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
			break ;
		}
		else
		{
		   	if(map.dllst->next != NULL)
				map.dllst = map.dllst->next;
		}
	}
	hero->img = 