#include <stdlib.h>
#include "libft.h"

void	ft_dllstdelone(t_dllist *dllst, void (*del) (void*))
{
	if (dllst == NULL)
		return ;
	del(dllst->content);
	if (dllst->prev)
	{
		if (dllst->next)
			dllst->next->prev = dllst->prev;
	}
	if (dllst->next)
	{
		if (dllst->prev)
			dllst->prev->next = dllst->next;
	}
	free(dllst);
	return ;
}
