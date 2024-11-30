#include "ft_create_elem.c"
#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int	i;

	i = 0;
	while (begin_list)
	{
		i++;
		begin_list = begin_list->next;
	}
	return (i);
}
// #include <stdio.h>

// int	main(void)
// {
// 	t_list	*new;

// 	new = ft_create_elem("1");
// 	new->next = ft_create_elem("2");
// 	new->next->next = ft_create_elem("3");
// 	printf("%i\n", ft_list_size(new));
// }
