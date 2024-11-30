#include "ft_create_elem.c"
#include "ft_list.h"
#include <stdio.h>
#include <string.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
		void (*free_fct)(void *))
{
	t_list	*start;
	t_list	*ptr;

	start = *begin_list;
	ptr = *begin_list;
	while (*begin_list && (*begin_list)->next)
	{
		if (cmp((*begin_list)->next->data, data_ref) == 0)
		{
			ptr = (*begin_list)->next;
			(*begin_list)->next = (*begin_list)->next->next;
			free_fct(ptr->data);
			free(ptr);
		}
		(*begin_list) = (*begin_list)->next;
	}
	*begin_list = start;
	if (*begin_list && cmp((*begin_list)->data, data_ref) == 0)
	{
		*begin_list = (*begin_list)->next;
		(free_fct)(ptr->data);
		free(ptr);
	}
}

// void	print_list(t_list *list)
// {
// 	while (list)
// 	{
// 		printf("%s->", (char *)list->data);
// 		list = list->next;
// 	}
// 	printf("\n");
// }

// int	main(int ac, char **av)
// {
// 	t_list	*new;

// 	new = ft_create_elem(strdup("ciao"));
// 	new->next = ft_create_elem(strdup("come"));
// 	new->next->next = ft_create_elem(strdup("stai"));
// 	new->next->next->next = ft_create_elem(strdup("tutto bene?"));
// 	ft_list_remove_if(&new, av[1], strcmp, free);
// 	print_list(new);
// }
