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

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
		int (*cmp)())
{
	t_list	*beninning;
	void	*tmp;
	t_list	*next;

	beninning = begin_list2;
	while (begin_list2->next)
		begin_list2 = begin_list2->next;
	begin_list2->next = *begin_list1;
	begin_list2 = beninning;
	while (begin_list2)
	{
		next = begin_list2->next;
		while (next)
		{
			if (cmp(begin_list2->data, next->data) > 0)
			{
				tmp = begin_list2->data;
				begin_list2->data = next->data;
				next->data = tmp;
			}
			next = next->next;
		}
		begin_list2 = begin_list2->next;
	}
	begin_list2 = beninning;
}

int	main(void)
{
	t_list	*new1;
	t_list	*new2;

	new1 = ft_create_elem("1");
	new1->next = ft_create_elem("2");
	new1->next->next = ft_create_elem("3");
	new2 = ft_create_elem("4");
	new2->next = ft_create_elem("5");
	new2->next->next = ft_create_elem("6");
	ft_sorted_list_merge(&new1, new2, strcmp);
	print_list(new2);
}
