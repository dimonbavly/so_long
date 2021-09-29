#include "ft_so_long.h"

void	ft_sl_init_res(t_res **res)
{
	*res = malloc(sizeof(t_res));
	(*res)->mlx = mlx_init();
	(*res)->win = mlx_new_window((*res)->mlx, 1920, 1080, "so_long");
	(*res)->map = malloc(sizeof (t_map));
}
