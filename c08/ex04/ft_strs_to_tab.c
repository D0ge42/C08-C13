#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)malloc(sizeof(char) * ft_strlen(s1));
  if (!str)
    return NULL;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

//We'll use a pointer to structure to navigate the allocated structure.
//We'll have to use ("->") operator to access members instead of using (".") since we're using a pointer.
//Number of arguments will be plus 1 to insert a str pointing to 0 marking the end.

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*new;
  t_stock_str *buffer;

	new = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
  buffer = new;
	if (!new)
		return (NULL);
	while (ac--)
	{
    buffer->size = ft_strlen(*av);
    buffer->str = *av;
    buffer->copy = ft_strdup(*av);
    av++;
    buffer++;
	}
  buffer->str = 0;
	return (new);
}

#include <stdio.h>

int	main(int ac, char **av)
{
  while(ac)
  {
    t_stock_str *new = ft_strs_to_tab(ac,av);
    printf("Lunghezza stringa %i\n", new->size);
    printf("La stringa %s\n",new->str);
    printf("Copia della string %s\n",new->copy);
    av++;
    ac--;
  }
}
