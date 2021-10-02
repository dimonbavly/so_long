#include "libft.h"

/* 
** not to change *lst!  - use it as const int this case
*/

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	current = *lst;
	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		while (current->next != NULL)
			current = current->next;
		current->next = new;
		current->next->next = NULL;
	}
	return ;
}
