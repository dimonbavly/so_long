/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sl_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 11:40:46 by                   #+#    #+#             */
/*   Updated: 2021/10/01 08:44:42 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_so_long.h"

int		*ft_sl_check_tile(t_res *res, char c);
int		*ft_sl_move_pre(int key);

void	ft_sl_move(int key, t_res *res)
{
	int	*vec;
	int	*ret;

	vec = ft_sl_move_pre(key);
	if (res->map->content[res->gdata->y_h + vec[0]][res->gdata->x_w + vec[1]] \
	!= '1')
	{
		ret = ft_sl_check_tile(res, res->map->content \
		[res->gdata->y_h + vec[0]][res->gdata->x_w + vec[1]]);
		if (res->gdata->things == 0)
			return ;
		res->map->content[res->gdata->y_h][res->gdata->x_w] = '0';
		res->gdata->x_w += vec[1];
		res->gdata->y_h += vec[0];
		res->map->content[res->gdata->y_h][res->gdata->x_w] = 'P';
		res->gdata->things += ret[0];
		res->gdata->end_game += ret[1];
		(res->gdata->way)++;
	}
}

int	*ft_sl_check_tile(t_res *res, char c)
{
	int	thing_vec;
	int	end_game_vec;

	thing_vec = 0;
	end_game_vec = 0;
	if (c == 'C')
		thing_vec = -1;
	else if (c == 'E')
	{
		if (res->gdata->things == 0)
			end_game_vec = 1;
	}
	return ((int []){thing_vec, end_game_vec});
}

int	*ft_sl_move_pre(int key)
{
	int		*keys;
	int		**vec;
	int		i;

	keys = (int []){13, 0, 1, 2};
	vec = (int *[]){(int []){-1, 0}, (int []){0, -1}, \
	(int []){1, 0}, (int []){0, 1}};
	i = 0;
	while (i < 4)
	{
		if (keys[i] == key)
			break ;
		i++;
	}
	return (vec[i]);
}