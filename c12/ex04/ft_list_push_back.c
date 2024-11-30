#include "ft_create_elem.c"
#include "ft_list.h"
//#include <stdio.h>

//-> has priority over * so when we access begin list
// we're basically trying to deference a pointer to pointer.
// Instead we want to deference the pointer pointing to the structure.
// TO do that, we put parenthesis and give asterisk priority over ->.
//

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*new;
	t_list	*start;

	start = *begin_list;
	new = ft_create_elem(data);
	while ((*begin_list)->next)
		*begin_list = (*begin_list)->next;
	(*begin_list)->next = new;
	*begin_list = start;
}
// void print_list(t_list *list)
// {
//   while(list)
//   {
//     printf("%s\n",(char *)list->data);
//     list = list->next;
//   }
// }

// int main()
// {
//   t_list *node1 = ft_create_elem("ciao");
//   node1->next = ft_create_elem("come");
//   node1->next->next = ft_create_elem("stai");
//   ft_list_push_back(&node1,"?");
//   print_list(node1);
// }
