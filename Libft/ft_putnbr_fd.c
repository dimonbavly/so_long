#include "libft.h"

static int	ft_init_sign(int n);
static void	ft_putnbr_writer(char *buf, int cnt, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	int		cnt;
	int		work_n;
	int		sign;
	char	buf[12];

	sign = ft_init_sign(n);
	if (n >= 0)
		n = -n;
	work_n = n;
	cnt = 0;
	while (work_n / 10)
	{
		buf[cnt++] = -(work_n % 10) + '0';
		work_n = work_n / 10;
	}
	if (work_n / 10 == 0)
		buf[cnt++] = -(work_n % 10) + '0';
	if (sign == -1)
		buf[cnt++] = '-';
	buf[cnt] = '\0';
	ft_putnbr_writer(buf, cnt, fd);
}

static int	ft_init_sign(int n)
{
	if (n < 0)
		return (-1);
	else
		return (1);
}

static void	ft_putnbr_writer(char *buf, int cnt, int fd)
{
	while (--cnt >= 0)
		ft_putchar_fd(buf[cnt], fd);
	return ;
}
