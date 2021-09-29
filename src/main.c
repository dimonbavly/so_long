/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 15:58:58 by                   #+#    #+#             */
/*   Updated: 2021/09/29 19:40:15 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_so_long.h"

int	main(int argc, char **argv)
{
	t_res	*res;

	(void) argc;
	res = malloc(sizeof (t_res));
	res->map->content = ft_get_map(argv[1]);
	res->mlx = mlx_init();
	if (!res->mlx)
		perror("mlx init");
	res->win = mlx_new_window(res->mlx, 1920, 1080, "so_long");
	if (!res->win)
		perror("mlxwin init");
	ft_show_map(res);
	mlx_key_hook (res->win, keyhook, res);
	mlx_loop(res->mlx);
}
