#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	res = malloc(sizeof(*res) * (len_s1 + len_s2 + 1));
	if (!res)
		return (0);
	ft_memcpy(res, s1, len_s1 + 1);
	ft_memcpy(res + len_s1, s2, len_s2 + 1);
	return (res);
}
