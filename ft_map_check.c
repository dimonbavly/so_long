#include "ft_so_long.h"

static void	check_characters(t_dllist dllst);
static void	check_num_characters(t_dllist dllst);
static void	check_edges(t_dllist dllst);
static void	check_equality_columns(t_dllist dllst);

void ft_sl_check_map(t_map *map)
{
	check_characters(*(map->dllst));
	check_num_characters(*(map->dllst));
	check_edges(*(map->dllst));
	check_equality_columns(*(map->dllst));
	return ;
}



static void	check_characters(t_dllist dllst)
{
	char *tmp;
	t_dllist *current;

	current = &dllst;
	while (current)
	{
		tmp = (char *)current->content;
		if (tmp == NULL)
		{
			//error_map
			exit(EXIT_FAILURE);
		}
		while (*tmp != '\0')
		{
			if (ft_strchr (MAP_CHARACTERS , *tmp) == NULL)
				//characters_input_error_in_map
				exit(EXIT_FAILURE);
			tmp++;
		}
		current = current->next;
	}
	return ;
}

static void	check_num_characters(t_dllist dllst)
{
	int *num_chars;
	t_dllist *current;
	char *tmp;

	num_chars = (int []){0,0,0,0,0};
	current = &dllst;
	while (current)
	{
		tmp = (char *) current->content;
		if (tmp == NULL)
			//error_map
			exit(EXIT_FAILURE);
		while (*tmp != '\0')
		{
			num_chars[ft_strchr(MAP_CHARACTERS, *tmp)-MAP_CHARACTERS]++;
			if (num_chars[3] > 1)
			{
				//num_players_error;
				exit(EXIT_FAILURE);
			}
			tmp++;
		}
		current = current->next;
	}
	return ;
}

static void	check_edges(t_dllist dllst)
{
	t_dllist *current;
	char *tmp;
	int dlsize;
	int i;

	i = 0;
	dlsize = ft_dllstsize(&dllst);
	current = &dllst;
	while (current)
	{
		tmp = (char *) current->content;
		if (tmp == NULL)
			//error_map
			exit(EXIT_FAILURE);
		if (i == 0 || i == dlsize -1)
		{
			while (*tmp != '\0')
			{
				if (*tmp != MAP_CHARACTERS[0])
				{
					//map_error
					exit(EXIT_FAILURE);
				}
				tmp++;
			}
		}
		else
		{
			if (*tmp != MAP_CHARACTERS[0] ||\
				   	*(tmp + ft_strlen(tmp) - 1) != MAP_CHARACTERS[0])
			{
				//error_map
				exit(EXIT_FAILURE);
			}
		}
		current = current->next;
		i++;
	}
	return ;
}


static void	check_equality_columns(t_dllist dllst)
{
	t_dllist *current;

	current = &dllst;
	while (current && current->next)
	{
		if (current->content == NULL && ft_strlen((char *)current->content) !=\
			   ft_strlen((char *)current->next->content))
		{
			//error_map;
			exit(EXIT_FAILURE);
		}
		current = current->next;
	}
	return ;
}
