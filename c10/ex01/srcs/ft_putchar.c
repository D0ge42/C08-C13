#include "../includes/ft.h"

void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}
