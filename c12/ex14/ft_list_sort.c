#include "ft_create_elem.c"
#include "ft_list.h"
#include <stdio.h>
#include <string.h>

// 3->2->0->1->5

// void	print_list(t_list *list)
// {
// 	while (list)
// 	{
// 		printf("%s->", (char *)list->data);
// 		list = list->next;
// 	}
// 	printf("\n");
// }

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*ptr;
	t_list	*tmp;
	void	*data2;

	ptr = *begin_list;
	while (ptr)
	{
		tmp = ptr->next;
		while (tmp)
		{
			if ((cmp)(ptr->data, tmp->data) > 0)
			{
				data2 = ptr->data;
				ptr->data = tmp->data;
				tmp->data = data2;
			}
			tmp = tmp->next;
		}
		ptr = ptr->next;
	}
}

// int	main(void)
// {
// 	t_list	*new;

// 	new = ft_create_elem("0");
// 	new->next = ft_create_elem("2");
// 	new->next->next = ft_create_elem("1");
// 	new->next->next->next = ft_create_elem("5");
// 	new->next->next->next->next = ft_create_elem("9");
// 	ft_list_sort(&new, strcmp);
// 	print_list(new);
// }
