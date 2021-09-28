/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 15:58:58 by                   #+#    #+#             */
/*   Updated: 2021/09/28 21:33:06 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_so_long.h"

int	main(int argc, char **argv)
{
	t_res	*res;
	void	*img;
	int		width;
	int		height;

	(void) argc;
	(void) argv;
	res = malloc(sizeof (t_res));
	res->mlx = mlx_init();
	if (!res->mlx)
		perror("mlx init");
	res->win = mlx_new_window(res->mlx, 1920, 1080, "so_long");
	if (!res->win)
		perror("mlxwin init");
	img = mlx_xpm_file_to_image(res->mlx, "img/hero.xpm", &width, &height);
	if (!img)
		perror("img from xpm");
	mlx_put_image_to_window(res->mlx, res->win, img, 120, 120);
	mlx_key_hook (res->mlx, keyhook, res->win);
	mlx_loop(res->mlx);
}
