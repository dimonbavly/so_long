#include "libft.h"
#include <stdlib.h>

t_dllist	*ft_dllstnew(void *content)
{
	t_dllist	*result;

	result = malloc (sizeof(t_dllist));
	if (result == NULL)
		return (NULL);
	result->content = content;
	result->prev = NULL;
	result->next = NULL;
	return (result);
}
