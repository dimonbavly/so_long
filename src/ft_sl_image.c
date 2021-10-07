/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sl_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 20:31:32 by                   #+#    #+#             */
/*   Updated: 2021/10/07 09:53:47 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_so_long.h"
void	ft_init_imgs(t_img **imgs, t_res *res);
void	ft_sl_put_image(t_res *res, int x_w, int y_h);
void	*ft_sl_image_chooser(t_gdata *gdata, t_img *imgs, int i);

void	ft_show_map(t_res *res)
{
	ft_init_imgs(&(res->imgs), res);
	ft_sl_update_picture(res);
}

void	ft_init_imgs(t_img **imgs, t_res *res)
{
	t_elem	*elems;
	char	**paths;
	int		i;

	paths = (char *[]){"img/empty.xpm", "img/wall.xpm", "img/thing.xpm", \
	"img/exit_open.xpm", "img/exit_closed.xpm", "img/hero.xpm", \
	"img/hero_end_game.xpm", NULL};
	elems = (t_elem []){EMPTY, WALL, THING, EXIT_OPEN, EXIT_CLOSED, \
	HERO, HERO_END_GAME, END_ENUM_LIST};
	i = 0;
	while (elems[i] != END_ENUM_LIST)
		i++;
	*imgs = check_null_ptr(malloc(sizeof (t_img) * (i + 1)));
	i = 0;
	while (paths[i])
	{
		(*imgs)[i] = (t_img){(elems[i]), paths[i], NULL, 32, 32};
		(*imgs)[i].bin = mlx_xpm_file_to_image(res->mlx, paths[i], \
		&((*imgs)[i].width), &((*imgs)[i].height));
		i++;
	}
}

void	ft_sl_put_image(t_res *res, int x_w, int y_h)
{
	char	*tmp;
	char	*mapchars;
	int		i;

	mapchars = NULL;
	mapchars = ft_strdup(MAP_CHARS);
	tmp = ft_strchr(mapchars, res->map->content[y_h][x_w]);
	i = tmp - mapchars;
	if (*tmp == '1' || *tmp == '0')
	{
		mlx_put_image_to_window(res->mlx, res->win, \
		res->imgs[i].bin, x_w * TILE, y_h * TILE);
	}
	else
	{
		mlx_put_image_to_window(res->mlx, res->win, \
		res->imgs[EMPTY].bin, x_w * TILE, y_h * TILE);
		mlx_put_image_to_window(res->mlx, res->win, ft_sl_image_chooser(\
		res->gdata, res->imgs, i), x_w * TILE, y_h * TILE);
	}
	free(mapchars);
}

void	ft_sl_update_picture(t_res *res)
{
	int		x_w;
	int		y_h;

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
	printf("%d\n", res->gdata->way);
	mlx_string_put(res->mlx, res->win, TILE / 2, TILE / 2, \
	0x00000000, ft_itoa(res->gdata->way));
	if (res->gdata->end_game == 1)
		mlx_string_put(res->mlx, res->win, res->gdata->x_w * TILE, \
	   res->gdata->y_h * TILE, 0x00000000, "END");
}

void	*ft_sl_image_chooser(t_gdata *gdata, t_img *imgs, int i)
{
	if (i == 3)
	{
		if (gdata->things <= 0)
			return (imgs[EXIT_OPEN].bin);
		else
			return (imgs[EXIT_CLOSED].bin);
	}
	else if (i == 4)
	{
		if (gdata->end_game == 1)
			return (imgs[HERO_END_GAME].bin);
		else
			return (imgs[HERO].bin);
	}
	else
		return (imgs[i].bin);
}
