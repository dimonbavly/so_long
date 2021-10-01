#include "ft_so_long.h"
#include "ft_sl_map_handler_a.h"

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

static void	ft_check_map_name(char *filename)
{
	int	fd;

	if ((ft_strlen(filename) < 5) || ft_strncmp(&filename[ft_strlen(filename) - 4], ".ber", 4))
	{
		printf("Wrong file name");
		exit (EXIT_SUCCESS);
	}
	fd = open(filename, O_RDONLY);
	if (fd < 0 )
	{
		printf("Cannot open file \"%s\": %s", filename, strerror(errno));
		close (fd);
		exit(EXIT_FAILURE);
	}
}

static void	ft_check_map_symbols(int *arr, char **map)
{
	if (arr[0] < 1 || arr[1] < 12 || arr[2] < 1 || arr[3] < 1 || arr[4] != 1)
	{
		printf("Wrong number of characters on the map");
		exit(EXIT_SUCCESS);
	}
}

static void	ft_check_map_dimensions_and_elements_and_borders(char **map)
{
	int		x;
	int		y;
	int		*maparr;
	char	*mapchars;

	mapchars = ft_strdup(MAP_CHARS);
	maparr = malloc(ft_strlen(mapchars));
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
		printf("Wrong map dimensions");
		exit(EXIT_SUCCESS);
	}
	ft_check_map_symbols(maparr);
	free(maparr);
	free(mapchars);
}

static void	ft_check_borders_and_len(char **map)
{
	int		*tmp;
	char	**strs;

	strs = map;
	tmp = (int []){ft_strlen(*map), 0};
	while (++(*map))
	{
		if (ft_strlen(*map) != tmp[0])
		{
			printf ("Different strings length");
			exit(EXIT_SUCCESS);
		}
	}
	while (**strs)
	{
		if (**strs != '1')
		{

		}

	}
}
