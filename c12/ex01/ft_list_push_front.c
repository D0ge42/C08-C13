#include "ft_create_elem.c"
#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*new;

	if (*begin_list)
	{
		new = ft_create_elem(data);
		new->next = *begin_list;
		*begin_list = new;
	}
	else
		*begin_list = ft_create_elem(data);
}

// #include <stdio.h>
// void print_list(t_list *list)
// {
//   while(list != NULL)
//   {
//     printf("%s\n", (char *)list->data);
//     list = list->next;
//   }
// }

// //Since we're pushing the list from the beginning the 2 numbers should appear
// //in the correct order.

// int main()
// {
//   t_list *my_list;
//   ft_list_push_front(&my_list, "4");
//   ft_list_push_front(&my_list, "3");
//   ft_list_push_front(&my_list, "2");
//   ft_list_push_front(&my_list, "1");

//   print_list(my_list);
// }
