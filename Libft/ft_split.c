#include <stdlib.h>
#include "libft.h"

static void		ft_free_all(char **dest);
static size_t	ft_countwords(const char *str, char c);
static size_t	ft_split_handler(const char *str, char c, \
	   	char **dest, size_t cnt);

char	**ft_split(char const *s, char c)
{
	char	**res;

	res = ft_calloc(sizeof(*res), (ft_countwords(s, c) + 1));
	if (!res)
		return (NULL);
	if (!ft_countwords(s, c))
	{
		res[0] = NULL;
		return (res);
	}
	if (ft_split_handler(s, c, res, 0) < ft_countwords(s, c))
	{
		ft_free_all(res);
		return (NULL);
	}
	return (res);
}

static size_t	ft_countwords(char const *str, char c)
{
	size_t	cnt;
	size_t	occ;

	occ = 0;
	cnt = 0;
	while (str[cnt])
	{
		if (str[cnt] == c)
			cnt++;
		else if (str[cnt + 1] == c || str[cnt + 1] == '\0')
		{
			cnt++;
			occ++;
		}	
		else
			cnt++;
	}
	return (occ);
}

static size_t	ft_split_handler(const char *str, char c, \
		char **dest, size_t cnt)
{
	size_t	occ;
	size_t	start;

	start = cnt;
	occ = 0;
	while (str[cnt])
	{
		if (str[cnt] == c)
		{
			start++;
			cnt++;
		}
		else if (str[cnt + 1] == c || str[cnt + 1] == '\0')
		{	
			dest[occ] = ft_substr(str + start, 0, cnt + 1 - start);
			occ++;
			start = cnt + 1;
			if (str[cnt + 1] == '\0')
				break ;
			cnt++;
		}	
		else
			cnt++;
	}
	return (occ);
}

static void	ft_free_all(char **dest)
{
	int	cnt;

	cnt = 0;
	while (dest[cnt])
	{
		free(dest[cnt]);
		dest[cnt++] = NULL;
	}
	free(dest);
}
