#include "get_next_line.h"
/*
** works such as original strchr
*/
char	*ft_gnl_strchr(char *s, char delimiter)
{
	if (s == NULL)
		return (NULL);
	while (*s != delimiter && *s)
		s++;
	if (*s == '\0')
		return (NULL);
	else
		return (s);
}

/*
** simple strlen
*/

size_t	ft_strlen(const char *s)
{
	size_t	cnt;

	cnt = 0;
	while (*s++)
		cnt++;
	return (cnt);
}

/*
** works such as original substr
*/

char	*ft_gnl_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	len_of_s;

	len_of_s = ft_strlen(s);
	if ((size_t)start >= len_of_s)
	{
		res = malloc(sizeof(char));
		if (!res)
			return (NULL);
		*res = '\0';
		return (res);
	}
	if (len > len_of_s - start)
		len = len_of_s - start;
	res = malloc(sizeof(*res) * (len + 1));
	if (!res)
		return (NULL);
	ft_memcpy(res, s + start, len);
	res[len] = '\0';
	return (res);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;

	if (dest == NULL && src == NULL)
		return (dest);
	d = (char *)dest;
	s = (char *)src;
	while (n)
	{	
		*d = *s;
		d++;
		s++;
		n--;
	}
	return (dest);
}
