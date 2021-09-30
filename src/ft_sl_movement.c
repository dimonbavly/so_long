/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sl_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 11:40:46 by                   #+#    #+#             */
/*   Updated: 2021/09/30 11:48:06 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_so_long.h"

void	ft_sl_move(int key, t_res *res)
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
}
