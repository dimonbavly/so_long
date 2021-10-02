#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	cnt;
	size_t	needlesize;
	size_t	haystacksize;

	haystacksize = ft_strlen(haystack);
	needlesize = ft_strlen(needle);
	if (*needle == '\0')
		return ((char *)haystack);
	else if (len == 0)
		return (NULL);
	else if (*haystack == '\0')
		return (NULL);
	cnt = 0;
	while ((cnt + needlesize <= haystacksize) && \
		   	ft_strncmp(&haystack[cnt], needle, needlesize) && \
		   	(cnt + needlesize <= len))
	{
		cnt++;
	}
	if ((cnt + needlesize > haystacksize) || (cnt + needlesize > len))
		return (NULL);
	return ((char *)haystack + cnt);
}
