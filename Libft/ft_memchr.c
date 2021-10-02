#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	ch;
	unsigned char	*str;

	ch = (unsigned char) c;
	str = (unsigned char *) s;
	while (n)
	{
		if (*str == ch)
			return (str);
		str++;
		n--;
	}
	return (NULL);
}
