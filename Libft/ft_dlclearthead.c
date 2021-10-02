#include <stdlib.h>
#include "libft.h"

void	ft_dlclearthead(t_dllist **dllst, void (*del) (void*))
{
	t_dllist	*current;
	t_dllist	*tmp;

	tmp = *dllst;
	if (!dllst)
		return ;
	if (!(tmp))
		return ;
	if (!(tmp->prev))
		return ;
	tmp = tmp->prev;
	current = tmp;
	while (1)
	{
		if (current->content)
			del(current->content);
		if (!current->prev)
			break ;
		tmp = current->prev;
		free(current);
		current = tmp;
	}
	return ;
}
