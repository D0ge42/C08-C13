#include <stdlib.h>

// int	plus_one(int n)
// {
// 	return (n += 1);
// }

int	*ft_map(int *tab, int lenght, int (*f)(int))
{
	int	i;
	int	*new;

	i = -1;
	new = (int *)malloc(sizeof(int) * lenght);
	while (++i < lenght)
		new[i] = (f)(tab[i]);
	return (new);
}
// #include <stdio.h>

// int	main(void)
// {
// 	int	array[4] = {0, 1, 2, 3};
// 	int	*new_array;
// 	int	i;

// 	new_array = ft_map(array, 4, plus_one);
// 	i = 0;
// 	while (i < 4)
// 		printf("%i\n", new_array[i++]);
// }
