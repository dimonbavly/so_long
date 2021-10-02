#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	tmp;

	tmp = 0;
	if (n == 0)
		return (0);
	while (s1[tmp] == s2[tmp] && tmp + 1 < n && s1[tmp] && s2[tmp])
		tmp++;
	return ((unsigned char)s1[tmp] - (unsigned char)s2[tmp]);
}
