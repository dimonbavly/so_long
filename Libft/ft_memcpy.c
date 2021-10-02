#include "libft.h"

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
