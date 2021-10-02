#include "libft.h"
#include <stdlib.h>

static int	ft_init_sign(int n);
static char	*ft_itoa_writer(int n, int cnt, int sign);

char	*ft_itoa(int n)
{
	int	cnt;
	int	work_n;
	int	sign;

	sign = ft_init_sign(n);
	if (n >= 0)
		n = -n;
	work_n = n;
	cnt = 0;
	while (work_n / 10)
	{
		cnt++;
		work_n = work_n / 10;
	}
	if (work_n / 10 == 0)
		cnt++;
	if (sign == -1)
		cnt++;
	return (ft_itoa_writer(n, cnt, sign));
}

static int	ft_init_sign(int n)
{
	if (n < 0)
		return (-1);
	else
		return (1);
}

static char	*ft_itoa_writer(int n, int cnt, int sign)
{
	char	*str;

	str = malloc(sizeof(*str) * (cnt + 1));
	if (!str)
		return (NULL);
	str[cnt--] = '\0';
	while (n / 10 )
	{
		str[cnt--] = -(n % 10) + '0';
		n = n / 10;
	}
	if (n / 10 == 0)
		str[cnt] = -(n % 10) + '0';
	if (sign == -1)
		str[--cnt] = '-';
	return (str);
}
