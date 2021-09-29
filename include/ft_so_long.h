/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 15:58:54 by                   #+#    #+#             */
/*   Updated: 2021/09/29 20:00:42 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_SO_LONG_H
# define FT_SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include "get_next_line.h"
# include "libft.h"

# define TILE 32
# define MAP_CHARS "01CEP"

typedef struct s_image
{
	char	*path;
	void	*bin;
	int		width;
	int		height;
}t_img;

typedef struct s_map
{
	char	**content;
	int		width;
	int		height;
};

typedef struct s_resources
{
	void	*mlx;
	void	*win;
	char	**map;
	t_img	*imgs;
}t_res;

int		keyhook(int key, t_res *res);
char	**ft_get_map(char *filename);

#endif /*FT_SO_LONG_H*/
