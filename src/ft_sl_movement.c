/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sl_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 11:40:46 by                   #+#    #+#             */
/*   Updated: 2021/09/30 12:58:31 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_so_long.h"

int	ft_sl_check_movement(int key, t_res *res);

void	ft_sl_move(int key, t_res *res)
{
	int	mov;

	mov = ft_sl_check_movement(key, res);
	if (mov)
	{
		res->map->content[res->map->y_h][res->map->x_w] = '0';
		if (key == 13)
			res->map->content[--(res->map->y_h)][res->map->x_w] = 'P';
		else if (key == 0)
			res->map->content[res->map->y_h][--(res->map->x_w)] = 'P';
		else if (key == 1)
			res->map->content[++(res->map->y_h)][res->map->x_w] = 'P';
		else if (key == 2)
			res->map->content[res->map->y_h][++(res->map->x_w)] = 'P';
		(res->map->way)++;
	}
}

int	ft_sl_check_movement(int key, t_res *res)
{
	char	c;

	if (key == 13)
		c = res->map->content[res->map->y_h - 1][res->map->x_w];
	else if (key == 0)
		c = res->map->content[res->map->y_h][res->map->x_w - 1];
	else if (key == 1)
		c = res->map->content[res->map->y_h + 1][res->map->x_w];
	else
		c = res->map->content[res->map->y_h][res->map->x_w + 1];
	if (c == '1')
		return (0);
	else
		return (1);
}