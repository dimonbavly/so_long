/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 15:58:58 by                   #+#    #+#             */
/*   Updated: 2021/09/30 12:34:13 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_so_long.h"

int	main(int argc, char **argv)
{
	t_res	*res;

	(void) argc;
	ft_sl_init_res(&res, argv[1]);
	ft_show_map(res);
	mlx_key_hook (res->win, keyhook, res);
	mlx_hook(res->win, 17, 0L, close_app, res);
	mlx_loop(res->mlx);
}
