#include "libft.h"

void	ft_dlinsertbefore(t_dllist **dllst, t_dllist *new)
{
	if (dllst == NULL)
		return ;
	if (*dllst == NULL)
	{
		new->next = NULL;
		*dllst = new;
	}
	else
	{
		new->prev = (*dllst)->prev;
		new->next = *dllst;
		if ((*dllst)->prev)
		{
			(*dllst)->prev->next = new;
			(*dllst)->prev = new;
		}
		else
			(*dllst)->prev = new;
	}
	return ;
}
