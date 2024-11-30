#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}

void	ft_sort_string_tab(char **tab)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		j = i + 1;
		while (tab[j])
		{
			if (ft_strcmp(tab[i], tab[j]) > 0)
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
			j++;
		}
		i++;
	}
	tab[i] = NULL;
}

// int	main(int ac, char **av)
// {
// 	char	*tab[] = {"3", "5", "3", "2", 0};
// 	int		i;

// 	ft_sort_string_tab(tab);
// 	i = 0;
// 	while (tab[i] != 0)
// 	{
// 		printf("%s\n", tab[i]);
// 		i++;
// 	}
// }
