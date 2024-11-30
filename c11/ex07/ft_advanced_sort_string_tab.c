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

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		i;
	int		j;
	char	*temp;
	int		len;

	i = 0;
	j = 0;
	len = 0;
	while (tab[len])
		len++;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (cmp(tab[i], tab[j]) > 0)
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
			j++;
		}
		i++;
	}
	tab[i] = 0;
}
#include <stdio.h>

int	main(void)
{
	char	*tab[] = {"b", "d", "e", "a", "c", 0};
	int		i;

	ft_advanced_sort_string_tab(tab, ft_strcmp);
	i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
}
