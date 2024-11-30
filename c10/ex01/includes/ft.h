#ifndef FT_H
# define FT_H

# define BUFF 30000

# include <errno.h>
# include <fcntl.h>
# include <string.h>
# include <unistd.h>

void	ft_putstr(char *str, int fd);
int		ft_strlen(char *str);
void	ft_putstr_buf(char *str, int buff);
void	ft_putchar(char c, int fd);

#endif
