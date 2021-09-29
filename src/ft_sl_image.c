#include "ft_so_long.h"
void	ft_init_imgs(t_img **imgs, t_res *res);
void	ft_sl_put_image(t_res *res, int x_w, int y_h);

void	ft_show_map(t_res *res)
{
	int		x_w;
	int		y_h;

	res->imgs = NULL;
	ft_init_imgs(&res->imgs, res);
	y_h = 0;
	while (res->map->content[y_h])
	{
		x_w = 0;
		while (res->map->content[y_h][x_w])
		{
			ft_sl_put_image(res, x_w, y_h);
			x_w++;
		}
		y_h++;
	}
}

void	ft_init_imgs(t_img **imgs, t_res *res)
{
	t_elem	*elems;
	char	**paths;

	paths = (char* []){"map/empty.xpm", "map/wall.xpm", "map/thing.xpm", \
	"map/exit.xpm", "map/hero.xpm", NULL};
	elems = (t_elem []){EMPTY, WALL, THING, EXIT, HERO, END_ENUM_LIST};
	*imgs = malloc(sizeof (t_img) * (ft_strlen(MAP_CHARS) + 1));
	while (*paths)
	{
		(**imgs) = (t_img){*elems, *paths, \
		mlx_xpm_file_to_image(res->mlx, *paths, \
		&(*imgs)->width, &(*imgs)->height), 32, 32};
		(*imgs)++;
		paths++;
		elems++;
	}
}

void	ft_sl_put_image(t_res *res, int x_w, int y_h)
{
	char	*tmp;
	char	*mapchars;
	int i;

	mapchars = NULL;
	ft_memcpy(mapchars, MAP_CHARS, ft_strlen(MAP_CHARS));
	tmp = ft_strchr(mapchars, res->map->content[y_h][x_w]);
	i = tmp - mapchars;
	if (*tmp == '1' || *tmp == '0')
	{
		mlx_put_image_to_window(res->mlx, res->win, res->imgs[i].bin, x_w * TILE, y_h * TILE);
	}
	else
	{
		mlx_put_image_to_window(res->mlx, res->win, res->imgs[EMPTY].bin, x_w * TILE, y_h * TILE);
		mlx_put_image_to_window(res->mlx, res->win, res->imgs[i].bin, x_w * TILE, y_h * TILE);
	}
}