#include "ft_create_elem.c"
#include "ft_list.h"
#include <stdio.h>
#include <string.h>

void ft_list_merge(t_list *begin_list1, t_list *begin_list2)
{
  if(!begin_list1)
    begin_list1 = begin_list2;
  else if(!begin_list2)
    begin_list2 = begin_list1;
  while(begin_list1->next)
    begin_list1 = begin_list1->next;
  begin_list1->next = begin_list2;
}



void	print_list(t_list *list)
{
	while (list)
	{
		printf("%s->", (char *)list->data);
		list = list->next;
	}
	printf("\n");
}

int main()
{
  t_list *new = ft_create_elem("sium");
  new->next = ft_create_elem("daje");
  new->next->next = ft_create_elem("roma");
  t_list *new2 = ft_create_elem("però");
  new2->next = ft_create_elem("sei");
  new2->next->next = ft_create_elem("er pupone");
  ft_list_merge(new, new2);
  print_list(new);
}
