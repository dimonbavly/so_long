/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sl_inits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 22:31:26 by                   #+#    #+#             */
/*   Updated: 2021/09/30 11:28:36 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_so_long.h"

void	ft_sl_init_map(t_map **map, char *argv);

void	ft_sl_init_res(t_res **res, char *argv)
{
	*res = malloc(sizeof(t_res));
	(*res)->mlx = mlx_init();
	ft_sl_init_map(&((*res)->map), argv);
	(*res)->win = mlx_new_window((*res)->mlx, \
	(*res)->map->width * TILE, (*res)->map->height * TILE, "so_long");
}

void	ft_sl_init_map(t_map **map, char *argv)
{
	int		h;
	int		w;
	char	**tmp;

	*map = malloc(sizeof (t_map));
	(*map)->argv = argv;
	(*map)->content = ft_get_map(argv);
	tmp = (*map)->content;
	h = 0;
	while (tmp[h])
	{
		w = 0;
		while (tmp[h][w])
		{
			if (tmp[h][w] == 'P')
			{
				(*map)->x_w = w;
				(*map)->y_h = h;
			}
			w++;
		}
		h++;
	}
	(*map)->height = h;
	(*map)->width = w;
	(*map)->way = 0;
}
