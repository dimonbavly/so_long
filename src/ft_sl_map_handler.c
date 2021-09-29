/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sl_map_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 14:53:23 by                   #+#    #+#             */
/*   Updated: 2021/09/29 22:11:58 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_so_long.h"

static char	**ft_list_to_char_arr(t_list *list);

char	**ft_get_map(char *filename)
{
	int		fd;
	char	*str;
	t_list	*list;
	char	**res;

	list = NULL;
	str = NULL;
	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &str) > 0)
	{
		ft_lstadd_back(&list, ft_lstnew(str));
	}
	close(fd);
	free(str);
	res = ft_list_to_char_arr(list);
	ft_lstclear(&list, NULL);
	return (res);
}

static char	**ft_list_to_char_arr(t_list *list)
{
	char	**res;
	int		i;

	res = malloc(sizeof(char *) * ft_lstsize(list) + 1);
	i = 0;
	while (list)
	{
		res[i++] = ft_strdup((char *)(list->content));
		list = list->next;
	}
	res[i] = NULL;
	return (res);
}
