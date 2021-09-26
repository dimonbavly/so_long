#include <ft_so_long.h>
static void	ft_sl_init_imgs(t_mlxres *mlxres, t_res *res);

void	ft_sl_show_map(t_mlxres *mlxres, t_res *res)
{
	int		w;
	int		h;
	char	*str;
	char	*occ;
	char	*mc;

	mc = ft_strdup(MAP_CHARACTERS);
	ft_sl_init_imgs(mlxres, res);
	h = 0;
	while (h < res->map.height)
	{
		w = 0;
		str = (char *)res->map.dllst->content;
		while (*str)
		{
			occ = ft_strchr(mc,*str);
			mlx_put_image_to_window(mlxres->mlx, mlxres->mlx_win,
				mlxres->imgs[occ - mc].bin, w
				* WIDTH, h * HEIGHT);
			str++;
			w++;
		}
		res->map.dllst = res->map.dllst->next;
		h++;
	}
	free(mc);
}

static void	ft_sl_init_imgs(t_mlxres *mlxres, t_res *res)
{
	int	i;

	mlxres->imgs = malloc (sizeof (t_img *) * NUM_MAP_CHARACTERS);
	memcpy(mlxres->imgs, &(t_img []){res->map.empty.img, res->map.wall.img, \
	res->map.thing.img, res->map.exit.img, res->map.hero.img}, \
	sizeof (t_img) * NUM_MAP_CHARACTERS);
	i = 0;
	while (i < NUM_MAP_CHARACTERS)
	{
		mlxres->imgs[i].bin = mlx_xpm_file_to_image(mlxres->mlx, \
		mlxres->imgs[i].path, &mlxres->imgs[i].width, &mlxres->imgs[i].height);
		i++;
	}
}
