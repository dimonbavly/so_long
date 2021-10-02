#include "libft.h"

t_dllist	*ft_dlhead(t_dllist *dllst)
{
	t_dllist	*current;

	current = dllst;
	if (!dllst)
		return (NULL);
	else
	{
		while (current && current->prev)
		{
			current = current->prev;
			if (current == dllst)
				break ;
		}
	}
	return (current);
}
