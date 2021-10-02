#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	result_size;
	size_t	cnt;

	cnt = 0;
	while (dst[cnt] && cnt < dstsize)
		cnt++;
	result_size = cnt;
	cnt = ft_strlcpy(dst + result_size, src, dstsize - result_size);
	return (result_size + cnt);
}
