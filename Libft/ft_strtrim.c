#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	cnt;

	cnt = 0;
	while (s1[cnt] && ft_strchr(set, s1[cnt]))
		cnt++;
	s1 = s1 + cnt;
	cnt = ft_strlen(s1);
	while (cnt && ft_strchr(set, s1[cnt]))
		cnt--;
	return (ft_substr(s1, 0, cnt + 1));
}
