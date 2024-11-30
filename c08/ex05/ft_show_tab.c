#include "ft_stock_str.h"
#include <string.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_putnbr(int nb)
{
	if (nb > 9)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*new;
	t_stock_str	*buffer;

	new = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	buffer = new;
	if (!new)
		return (NULL);
	while (ac--)
	{
		buffer->size = strlen(*av);
		buffer->str = *av;
		buffer->copy = strdup(*av);
		av++;
		buffer++;
	}
	buffer->str = 0;
	return (new);
}

void	ft_show_tab(struct s_stock_str *par)
{
	ft_putnbr(par->size);
	ft_putchar('\n');
	ft_putstr(par->str);
	ft_putchar('\n');
	ft_putstr(par->copy);
	ft_putchar('\n');
}

int	main(int ac, char **av)
{
	t_stock_str	*new;

	while ((ac))
	{
		new = ft_strs_to_tab(ac, av);
		ft_show_tab(new);
		av++;
		ac--;
			// Ac has to be decremented here and not in the while loop condition otherwise we'll pass
		// decremrented ac to the ft_strs_to_tab function causing a seg fault.
	}
}
