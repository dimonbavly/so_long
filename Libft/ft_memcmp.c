#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*f;
	unsigned char	*s;

	f = (unsigned char *)s1;
	s = (unsigned char *)s2;
	while (n)
	{
		if (*f != *s)
			break ;
		f++;
		s++;
		n--;
	}
	if (n == 0)
		return (0);
	else
		return (*f - *s);
}
