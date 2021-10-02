#include <stdlib.h>
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;

	if (!lst)
		return ;
	current = *lst;
	while (current)
	{
		if (del)
			del(current->content);
		*lst = current->next;
		free(current);
		current = *lst;
	}
	return ;
}
