#include <stdlib.h>
#include "libft.h"

void	ft_dlclearall(t_dllist **dllst, void (*del) (void*))
{
	if (!dllst)
		return ;
	ft_dlclearthead(dllst, del);
	ft_dlclearttail(dllst, del);
	if (!(*dllst))
		return ;
	if ((*dllst)->content)
		del((*dllst)->content);
	free(*dllst);
	*dllst = NULL;
	return ;
}
