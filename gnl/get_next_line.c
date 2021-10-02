#include "get_next_line.h"

static int		ft_gnl_main(char **rem, char **l, ssize_t ret, char *tmp);
static ssize_t	ft_update_remainder(int fd, char **remainder);
static void		write_remainder(char **rem, char *tmp, char *buf, ssize_t ret);

int	get_next_line(int fd, char **line)
{
	static char	*remainder;
	char		*tmp;
	ssize_t		ret;

	if (fd < 0 || line == NULL || BUFFER_SIZE < 1)
		return (-1);
	if (remainder == NULL)
		remainder = ft_gnl_substr("", 0, 0);
	ret = 1;
	tmp = ft_gnl_strchr(remainder, '\n');
	while (tmp == NULL && ret > 0)
	{
		ret = ft_update_remainder(fd, &remainder);
		tmp = ft_gnl_strchr(remainder, '\n');
	}
	return (ft_gnl_main(&remainder, line, ret, tmp));
}

static int	ft_gnl_main(char **rem, char **l, ssize_t ret, char *tmp)
{
	if (ret == 0)
	{	
		if (**rem == '\0')
			*l = ft_gnl_substr("", 0, 0);
		else if (*(*rem + ft_strlen(*rem) - 1) == '\n')
			*l = ft_gnl_substr(*rem, 0, ft_strlen(*rem) - 1);
		else
			*l = ft_gnl_substr(*rem, 0, ft_strlen(*rem));
		free(*rem);
		*rem = NULL;
		return (0);
	}
	else if (ret > 0)
	{
		*l = ft_gnl_substr(*rem, 0, tmp - *rem);
		if (*l == NULL)
			return (-1);
		tmp = ft_gnl_substr(tmp, 1, ft_strlen(tmp) - 1);
		free(*rem);
		*rem = tmp;
		return (1);
	}
	free(*rem);
	return (-1);
}

static ssize_t	ft_update_remainder(int fd, char **remainder)
{	
	ssize_t			ret;
	char			*buf;
	char			*tmp;

	if (fd < 0 || remainder == NULL || *remainder == NULL)
		return (-1);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	ret = read(fd, buf, BUFFER_SIZE);
	if (ret < 0)
		free(buf);
	if (ret < 0)
		return (ret);
	buf[ret] = '\0';
	tmp = *remainder;
	*remainder = malloc(sizeof(char) * (ft_strlen(*remainder) + ret + 1));
	if (*remainder == NULL)
		return (-1);
	write_remainder(remainder, tmp, buf, ret);
	free(tmp);
	free(buf);
	return (ret);
}

static void	write_remainder(char **rem, char *tmp, char *buf, ssize_t ret)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (*(tmp + i))
	{
		*(*rem + i) = *(tmp + i);
		i++;
	}
	j = 0;
	while (j <= ret)
	{
		*(*rem + i + j) = buf[j];
		j++;
	}
	return ;
}
