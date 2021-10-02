#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*res;
	size_t	s1_len;

	s1_len = ft_strlen(s1);
	res = malloc(sizeof(*res) * s1_len + 1);
	if (!res)
		return (NULL);
	else
		ft_strlcpy(res, s1, s1_len + 1);
	return (res);
}
