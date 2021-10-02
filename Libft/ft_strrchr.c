#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	cnt_last;

	cnt_last = ft_strlen(s);
	while (s[cnt_last] != (char)c)
	{
		if (cnt_last == 0)
			return (NULL);
		cnt_last--;
	}
	return ((char *)(s + cnt_last));
}
