#include <ft_so_long.h>
void ft_sl_show_map(t_mlxres *mlxres, t_res *res)
{
	int i;
	t_img *imgs;
	char *tmp;

	imgs = (t_img []){
	    (t_img){res->map.empty.img.path, res->map.empty.img.bin, res->map.empty.img.width, res->map.empty.img.height},
	    (t_img){res->map.wall.img.path, res->map.wall.img.bin, res->map.wall.img.width, res->map.wall.img.height},
	    (t_img){res->map.thing.img.path, res->map.thing.img.bin, res->map.thing.img.width, res->map.thing.img.height},
	    (t_img){res->map.exit.img.path, res->map.exit.img.bin, res->map.exit.img.width, res->map.exit.img.height},
	    (t_img){res->map.hero.img.path, res->map.hero.img.bin, res->map.hero.img.width, res->map.hero.img.height}
	};
	i = 0;
	while (i < NUM_MAP_CHARACTERS)
	{
	    imgs[i].bin = mlx_xpm_file_to_image(mlxres->mlx, imgs[i].path,\
	    &imgs[i].width, &imgs[i].height);
        mlx_put_image_to_window(mlxres->mlx, mlxres->mlx_win, imgs[i].bin,WIDTH * i, HEIGHT * i);
	    i++;
	}
	i = 0;
    while (i < res->map.height)
    {
        tmp = res->map.dllst->content;
        i++;
    }




}