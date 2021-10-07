/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sl_inits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 22:31:26 by                   #+#    #+#             */
/*   Updated: 2021/10/07 09:56:04 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_so_long.h"

void	ft_sl_init_map(t_map **map, char *argv);
void	ft_sl_init_gdata(t_res *res);

void	ft_sl_init_res(t_res **res, char *argv)
{
	*res = check_null_ptr(malloc(sizeof(t_res)));
	ft_sl_init_map(&((*res)->map), argv);
	ft_sl_init_gdata(*res);
	(*res)->mlx = mlx_init();
	(*res)->win = mlx_new_window((*res)->mlx, \
	(*res)->map->width * TILE, (*res)->map->height * TILE, "so_long");
}

void	ft_sl_init_map(t_map **map, char *argv)
{
	int		h;
	int		w;
	char	**tmp;

	*map = check_null_ptr(malloc(sizeof (t_map)));
	(*map)->argv = argv;
	(*map)->content = ft_get_map(argv);
	tmp = (*map)->content;
	h = 0;
	while (tmp[h])
	{
		w = 0;
		while (tmp[h][w])
			w++;
		h++;
	}
	(*map)->height = h;
	(*map)->width = w;
}

void	ft_sl_init_gdata(t_res *res)
{
	int	x_w;
	int	y_h;

	(void) res;
	res->gdata = check_null_ptr(malloc(sizeof(t_gdata)));
	res->gdata->things = 0;
	y_h = 0;
	while (res->map->content[y_h])
	{
		x_w = 0;
		while (res->map->content[y_h][x_w])
		{
			if (res->map->content[y_h][x_w] == 'C')
				(res->gdata->things)++;
			else if (res->map->content[y_h][x_w] == 'P')
			{
				res->gdata->x_w = x_w;
				res->gdata->y_h = y_h;
			}
			x_w++;
		}
		y_h++;
	}
	res->gdata->end_game = 0;
	res->gdata->way = 0;
}
