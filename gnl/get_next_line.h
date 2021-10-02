#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>

char	*ft_gnl_strchr(char *s, char delimiter);
int		get_next_line(int fd, char **line);
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_gnl_substr(char const *s, unsigned int start, size_t len);
char	*ft_gnl_substrdup(char *src, size_t start, size_t end);

#endif
