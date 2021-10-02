#include "libft.h"
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;

	if (dest == NULL && src == NULL)
		return (dest);
	if (dest < src)
	{
		d = (char *)dest;
		s = (char *)src;
		n++;
		while (--n)
			*d++ = *s++;
	}
	else
	{
		d = (char *)dest + (n - 1);
		s = (char *)src + (n - 1);
		while (n)
		{
			*d-- = *s--;
			n--;
		}
	}
	return (dest);
}
