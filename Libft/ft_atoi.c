#include "libft.h"

static int	ft_isspace(int c);

int	ft_atoi(const char *str)
{
	int			cnt;
	long int	result;
	int			plusminus;

	plusminus = 1;
	cnt = 0;
	while (ft_isspace(str[cnt]))
		cnt++;
	if (str[cnt] == '-' || str[cnt] == '+')
	{
		if (str[cnt] == '-')
			plusminus = -1;
		cnt++;
	}
	result = 0;
	while (ft_isdigit(str[cnt]))
	{
		result = result * 10 + plusminus * (str[cnt] - '0');
		if (plusminus == -1 && result < -2147483648)
			return (0);
		else if (plusminus == 1 && result > 2147483647)
			return (-1);
		cnt++;
	}
	return ((int)result);
}

static int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	else
		return (0);
}
