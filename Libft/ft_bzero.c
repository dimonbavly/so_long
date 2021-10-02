#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*tmp;

	tmp = (char *) s;
	if (!n)
		return ;
	while (n)
	{
		*tmp = 0;
		tmp++;
		n--;
	}
	return ;
}
