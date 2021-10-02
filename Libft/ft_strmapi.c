#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*mapi;
	size_t	len;
	size_t	cnt;

	len = ft_strlen (s);
	mapi = malloc(sizeof(*mapi) * len + 1 );
	if (!mapi)
		return (NULL);
	cnt = 0;
	while (cnt < len)
	{
		mapi[cnt] = (*f)(cnt, s[cnt]);
		cnt++;
	}
	mapi[cnt] = '\0';
	return (mapi);
}
