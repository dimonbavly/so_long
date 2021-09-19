#include "ft_so_long.h"

/*
** \file ft_sl_logic.c
*/


void ft_sl_run(char *path)
{
	t_res *res;
	
	res = NULL;
	ft_sl_init_res(&res, path);
	ft_sl_game(res);
}

void ft_sl_game(t_res *res)
{
	void *mlx;
	void *mlx_win;

//	pause();
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, res->map.width * PIXEL, res->map.height * PIXEL,\
		   	res->map.title);
	mlx_loop(mlx);
}
