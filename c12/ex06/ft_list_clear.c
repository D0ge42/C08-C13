#include "ft_create_elem.c"
#include "ft_list.h"
#include <stdio.h>
#include <string.h>

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*ptr;
  int i = 0;

	while (begin_list)
	{
    ptr = begin_list->next;
    (free_fct)(begin_list->data);
    free(begin_list);
    begin_list = ptr;
	}
}

void	print_list(t_list *list)
{  
	while (list)
	{
		printf("%s\n", (char *)list->data);
		list = list->next;
	}
}
void	free_node(void *data)
{
  printf("%p\n",data);
	free(data);
}

//Make sure to allocate data with malloc aswell or we'll get undefined behaviour by
//trying to free non dinamically allocated memory.
int	main(void)
{
	t_list	*new1;

  int num = 1;
	new1 = ft_create_elem(strdup("1"));
	new1->next = ft_create_elem(strdup("2"));
	new1->next->next = ft_create_elem(strdup("3"));
	print_list(new1);
	ft_list_clear(new1, free_node);
  printf("List cleared successfully");

}
