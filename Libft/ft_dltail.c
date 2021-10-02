#include "libft.h"

t_dllist	*ft_dltail(t_dllist *dllst)
{
	t_dllist	*current;

	current = dllst;
	if (!dllst)
		return (NULL);
	else
	{
		while (current && current->next)
		{
			current = current->next;
			if (current == dllst)
				break ;
		}
	}
	return (current);
}
