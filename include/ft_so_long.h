/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 15:58:54 by                   #+#    #+#             */
/*   Updated: 2021/09/28 21:25:32 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_SO_LONG_H
# define FT_SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>

typedef struct s_resources
{
	void	*mlx;
	void	*win;
}t_res;

int	keyhook(int key, t_res *res);

#endif /*SO_LONG_FT_SO_LONG_H*/
