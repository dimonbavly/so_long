#include "ft_so_long.h"
#include "ft_sl_map_handler_a.h"

char	**ft_list_to_char_arr(t_list *list)
{
	char	**res;
	int		i;

	res = malloc(sizeof(char *) * ft_lstsize(list) + 1);
	i = 0;
	while (list)
	{
		res[i++] = (char *)(list->content);
		list = list->next;
	}
	res[i] = NULL;
	return (res);
}

void	ft_check_map_name(char *filename)
{
	int	fd;

	if ((ft_strlen(filename) < 5) || ft_strncmp(&filename[ft_strlen(filename) - 4], ".ber", 4))
		error_n_xit("Wrong file name", EXIT_SUCCESS);
	fd = open(filename, O_RDONLY);
	if (fd < 0 )
	{
		printf("Error:\nCannot open file \"%s\": %s", filename, strerror(errno));
		close (fd);
		exit(EXIT_FAILURE);
	}
}

void	ft_check_map_symbols(int *arr)
{
	if (arr[0] < 1 || arr[1] < 12 || arr[2] < 1 || arr[3] < 1 || arr[4] != 1)
		error_n_xit("Wrong number of characters on the map", EXIT_SUCCESS);
}

void	ft_check_map_dimensions_and_elements(char **map)
{
	int		x;
	int		y;
	int		*maparr;
	char	*mapchars;

	mapchars = ft_strdup(MAP_CHARS);
	maparr = (int []){0, 0, 0, 0, 0};
	y = 0;
	while (map[y])
	{
		x = -1;
		while (map[y][++x])
			maparr[ft_strchr(mapchars, map[y][x]) - mapchars]++;
		y++;
	}
	if (y < 3 || x < 3)
	{
		printf("%d, %d\n", y, x);
		error_n_xit("Wrong map dimensions", EXIT_SUCCESS);
	}
	ft_check_map_symbols(maparr);
	free(mapchars);
}
// todo
/*
void	ft_check_borders_and_len_old(char **map)
{
	size_t	*tmp;
	char	***strs;

	strs = (char**[]){map, map, map, map};
	tmp = (size_t []){ft_strlen(*map), 0};
	while (++(*strs[0]))
	{
		printf("%lu\n", ft_strlen(*map));
		if (ft_strlen(*map) != tmp[0])
			error_n_xit("Different strings length", EXIT_SUCCESS);
	}
	while (*strs[1] && *strs[2])
	{
		if (**strs[1] != '1' || **strs[2] != '1')
			error_n_xit("Borders are not closed", EXIT_SUCCESS);
	}
	while (*strs[3])
	{
		if (**strs[3] != '1' || *strs[3][tmp[0]] != '1')
			error_n_xit("Borders are not closed", EXIT_SUCCESS);
	}
}
*/

void	ft_check_borders_and_len(char **map)
{
	size_t		*i;
	size_t		*len;

	i = (size_t []){0, 0};
	len = (size_t []){0, ft_strlen(map[0])};
	while (map[i[1]])
	{
		if (ft_strlen(map[i[1]]) != len[1])
			error_n_xit("Different strings length", EXIT_SUCCESS);
		i[1]++;
	}
	while (map[i[0]])
	{
		len[0] = 0;
		while (map[i[0]][len[0]])
		{
			if (((i[0] == 0 || i[0] == i[1] - 1) && map[i[0]][len[0]] != '1') || \
			((len[0] == 0 || len[0] == len[1] - 1) && map[i[0]][len[0]] != '1'))
				error_n_xit("Borders are not closed", EXIT_SUCCESS);
			len[0]++;
		}
		i[0]++;
	}
}