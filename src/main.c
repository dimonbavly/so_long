/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 15:58:58 by                   #+#    #+#             */
/*   Updated: 2021/09/28 19:11:36 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_so_long.h"

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	int		width;
	int		height;

	(void) argc;
	(void) argv;
	mlx = mlx_init();
	if (!mlx)
		perror("mlx init");
	mlx_win = mlx_new_window(mlx, 1920, 1080, "so_long");
	if (!mlx_win)
		perror("mlxwin init");
	img = mlx_xpm_file_to_image(mlx, "img/hero.xpm", &width, &height);
	if (!img)
		perror("img from xpm");
	mlx_put_image_to_window(mlx, mlx_win, img, 120, 120);
	mlx_loop(mlx);
	exit(0);
}
