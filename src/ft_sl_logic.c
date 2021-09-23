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
	t_mlxres mlxres;

	mlxres.mlx = mlx_init();
	mlxres.mlx_win = mlx_new_window(mlxres.mlx, res->map.width * WIDTH, res->map.height * HEIGHT,\
		   	res->map.title);
    ft_sl_show_map(&mlxres, res);
	mlx_loop(mlxres.mlx);
}
