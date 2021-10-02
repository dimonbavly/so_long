#include "libft.h"

void	ft_dlinsertafter(t_dllist **dllst, t_dllist *new)
{
	if (dllst == NULL)
		return ;
	if (*dllst == NULL)
	{
		new->prev = NULL;
		*dllst = new;
	}
	else
	{
		new->prev = *dllst;
		new->next = (*dllst)->next;
		if ((*dllst)->next)
		{
			(*dllst)->next->prev = new;
			(*dllst)->next = new;
		}
		else
			(*dllst)->next = new;
	}
	return ;
}
