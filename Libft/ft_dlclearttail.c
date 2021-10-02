#include <stdlib.h>
#include "libft.h"

void	ft_dlclearttail(t_dllist **dllst, void (*del) (void*))
{
	t_dllist	*current;
	t_dllist	*tmp;

	tmp = *dllst;
	if (!dllst)
		return ;
	if (!tmp)
		return ;
	if (!(tmp->next))
		return ;
	tmp = tmp->next;
	current = tmp;
	while (1)
	{
		if (current->content)
			del(current->content);
		if (!(current->next))
			break ;
		tmp = current->next;
		free(current);
		current = tmp;
	}
	return ;
}
