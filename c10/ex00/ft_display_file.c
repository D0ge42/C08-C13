#include <fcntl.h>
#include <unistd.h>

void	ft_putstr(char *str, int fd)
{
	while (*str)
		write(fd, str++, 1);
}

int	main(int ac, char **av)
{
	char	c[4097];
	int		fd;
	int		sz;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			return (0);
		// How to get size of file.
		sz = read(fd, c, 4097);
		if (sz == -1)
			ft_putstr("Cannot read file\n", 2);
		c[sz] = '\0';
		ft_putstr(c, 1);
	}
	else if (ac == 1)
		ft_putstr("File name missing\n", 2);
	else if (ac > 2)
		ft_putstr("Too many arguments.\n", 2);
	return (0);
}
