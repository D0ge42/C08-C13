#include "ft.h"

void	special_cases(char sign, char *b)
{
  int i = 0;
  char charset[5] = "+-/*%";
  while(charset[i] != sign)
  {
    i++;
    if(charset[i] == '\0')
    {
      ft_putchar('0');
      return;
    }
  }
	if (sign == '/' && b[0] == '0')
	{
		ft_putstr("Stop. division by zero");
		return ;
	}
	else if (sign == '%' && b[0] == '0')
	{
		ft_putstr("Stop. modulo by zero");
		return ;
	}
}

int	main(int ac, char **av)
{
	int	(*p[5])(int a, int b);

	p[0] = ft_add;
	p[1] = ft_sub;
	p[2] = ft_mod;
	p[3] = ft_div;
	p[4] = ft_mult;
	special_cases(av[2][0], (av[3]));
	if (ac == 4)
	{
		if (av[2][0] == '+')
			ft_putnbr(p[0](ft_atoi(av[1]), ft_atoi(av[3])));
		else if (av[2][0] == '-')
			ft_putnbr(p[1](ft_atoi(av[1]), ft_atoi(av[3])));
		else if (av[2][0] == '/' && (av[3][0] != '0'))
			ft_putnbr(p[3](ft_atoi(av[1]), ft_atoi(av[3])));
		else if (av[2][0] == '*')
			ft_putnbr(p[4](ft_atoi(av[1]), ft_atoi(av[3])));
		else if (av[2][0] == '%' && av[3][0] != '0')
			ft_putnbr(p[2](ft_atoi(av[1]), ft_atoi(av[3])));
		ft_putchar('\n');
	}
	else
		return (0);
}
