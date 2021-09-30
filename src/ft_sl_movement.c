/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sl_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 11:40:46 by                   #+#    #+#             */
/*   Updated: 2021/09/30 22:30:54 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_so_long.h"

int	ft_sl_check_movement(int key, t_res *res);
void	ft_sl_check_tile(t_res *res, char c);

void	ft_sl_move(int key, t_res *res)
{
	int		*keys;
	int		**vec;
	int		i;

	if (res->gdata->end_game)
		return ;
	keys = (int []){13, 0, 1, 2};
	vec = (int *[]){(int []){-1, 0}, (int []){0, -1}, (int []){1, 0}, (int []){0, 1}};
	i = 0;
	while (i < 4)
	{
		if (keys[i] == key)
			break ;
		i++;
	}
	if (res->map->content[res->gdata->y_h + vec[i][0]][res->gdata->x_w + vec[i][1]] != '1')
	{
		ft_sl_check_tile(res, res->map->content[res->gdata->y_h + vec[i][0]][res->gdata->x_w + vec[i][1]]);
		if (res->gdata->things == 0)
			return ;
		res->map->content[res->gdata->y_h][res->gdata->x_w] = '0';
		res->gdata->x_w += vec[i][1];
		res->gdata->y_h += vec[i][0];
		res->map->content[res->gdata->y_h][res->gdata->x_w] = 'P';
		(res->gdata->way)++;
	}
}

//todo rudiment
int	ft_sl_check_movement(int key, t_res *res)
{
	char	c;

	if (key == 13)
		c = res->map->content[res->gdata->y_h - 1][res->gdata->x_w];
	else if (key == 0)
		c = res->map->content[res->gdata->y_h][res->gdata->x_w - 1];
	else if (key == 1)
		c = res->map->content[res->gdata->y_h + 1][res->gdata->x_w];
	else
		c = res->map->content[res->gdata->y_h][res->gdata->x_w + 1];
	if (c == '1')
		return (0);
	else
		return (1);
}

void	ft_sl_check_tile(t_res *res, char c)
{
	if (c == 'C')
		(res->gdata->things)--;// todo fix this - goes to -1
	else if (c == 'E')
	{
		if (res->gdata->things == 0)
			res->gdata->end_game = 1;
	}
}

