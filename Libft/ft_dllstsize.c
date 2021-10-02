#include "libft.h"

int	ft_dllstsize(t_dllist *dllst)
{
	int			size;
	t_dllist	*tmp;

	if (!dllst)
		return (0);
	size = 0;
	tmp = dllst;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
		if (tmp == dllst)
			break ;
	}
	return (size);
}
