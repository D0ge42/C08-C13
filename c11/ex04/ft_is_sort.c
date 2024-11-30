#include <stdio.h>

int	ft_is_sort(int *tab, int lenght, int (*f)(int, int))
{
	int	i;
	int	j;

	i = 0;
	while (i < lenght)
	{
		j = i + 1;
		while (j < lenght)
		{
			if ((f)(tab[i], tab[j]) == 1)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

// int	compare(int a, int b)
// {
// 	if (a < b)
// 		return (-1);
//   else if (a > b)
//     return (1);
//   else
// 		return (0);
// }
// int	main(void)
// {
// 	int	tab[5] = {-2, -1, 3, 4, 5};
// 	int	result;

// 	result = ft_is_sort(tab, 5, compare);
// 	printf("%i\n", result);
// }
