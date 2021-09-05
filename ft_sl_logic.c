#include "ft_so_long.h"

/*
** \file ft_sl_logic.c
*/

void ft_sl_start(t_res *res);

void ft_sl_run(char *path)
{
	t_res *res;

	ft_sl_init_res(res, path);
	ft_sl_game(res);
}

void ft_sl_game(t_res *res)
{
	void *mlx;
	void *mlx_window;

	mlx = mlx_init();
	mlx = mlx_new_window(mlx, res->map.w * PIXEL, res->map.h * PIXEL,\
		   	res->map.title);
	mlx_loop(mlx);
}
