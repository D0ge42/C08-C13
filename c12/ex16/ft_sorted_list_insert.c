#include "ft_create_elem.c"
#include "ft_list.h"
#include <stdio.h>
#include <string.h>

void	print_list(t_list *list)
{
	while (list)
	{
		printf("%s->", (char *)list->data);
		list = list->next;
	}
	printf("\n");
}

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*new;
	void	*tmp;
	t_list	*ptr;

	new = ft_create_elem(data);
	new->next = *begin_list;
	*begin_list = new;
	while (*begin_list)
	{
		ptr = (*begin_list)->next;
		while (ptr)
		{
			if ((cmp)((*begin_list)->data, ptr->data) > 0)
			{
				tmp = (*begin_list)->data;
				(*begin_list)->data = ptr->data;
				ptr->data = tmp;
			}
			ptr = ptr->next;
		}
		(*begin_list) = (*begin_list)->next;
	}
	*begin_list = new;
}

int	main(void)
{
	t_list	*new;

	new = ft_create_elem("1");
	new->next = ft_create_elem("2");
	new->next->next = ft_create_elem("4");
	new->next->next->next = ft_create_elem("5");
	ft_sorted_list_insert(&new, "3", strcmp);
	print_list(new);
}
