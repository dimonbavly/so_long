/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sl_button_actions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 21:26:24 by                   #+#    #+#             */
/*   Updated: 2021/09/30 11:15:24 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_so_long.h"

int	keyhook(int key, t_res *res)
{
	if (key == 53)
	{
		mlx_destroy_window(res->mlx, res->win);
		exit(0);
	}
	else if (key == 13 || key == 1 || key == 2 || key == 0)
	{
		ft_sl_move(key, res);
		mlx_clear_window(res->mlx, res->win);
		ft_sl_update_picture(res);
	}
	return (0);
}
