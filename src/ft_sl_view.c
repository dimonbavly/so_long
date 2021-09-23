#include <ft_so_long.h>

void ft_sl_show_map(void *mlx_ptr, void *win_ptr, t_res *res)
{
	void *img;
	int i;

	img = mlx_xpm_file_to_image(mlx, res->map.hero.img.path,\
			&res->map.hero.img.width, &res->map.hero.img.height);
	i = 0;
	while (i < res->map.height)
	{

	mlx_put_image_to_window(res->mlx, res->mlx_win, );
	}

}
