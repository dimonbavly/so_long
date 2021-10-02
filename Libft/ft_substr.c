#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	len_of_s;

	len_of_s = ft_strlen(s);
	if ((size_t)start >= len_of_s)
	{
		res = malloc(sizeof(*res));
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
