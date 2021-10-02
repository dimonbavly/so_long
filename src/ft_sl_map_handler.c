/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sl_map_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 14:53:23 by                   #+#    #+#             */
/*   Updated: 2021/10/02 13:28:54 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_so_long.h"
#include "get_next_line.h"
#include "ft_sl_map_handler_a.h"

char	**ft_get_map(char *filename)
{
	int		fd;
	char	*str;
	t_list	*list;
	char	**res;

	list = NULL;
	str = NULL;
	fd = open(filename, O_RDONLY);
	ft_check_map_name(filename);
	while (get_next_line(fd, &str) >= 0)
	{
		ft_lstadd_back(&list, ft_lstnew(str));
		if (*(char *)ft_lstlast(list)->content == '\0')
			break ;
	}
	close(fd);
	free(str);
	res = ft_list_to_char_arr(list);
	ft_check_map_dimensions_and_elements(res);
	ft_check_borders_and_len(res);
	ft_lstclear(&list, NULL);
	return (res);
}
