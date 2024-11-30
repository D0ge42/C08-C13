#include "ft_create_elem.c"
#include "ft_list.h"
#include <stdio.h>

t_list *ft_list_at(t_list *begin_list, unsigned int nbr)
{
  int i = 0;
  while(i++ != nbr)
    begin_list = begin_list->next;
  return begin_list;
}

int main()
{
  t_list *new1 = ft_create_elem("1");
  new1->next = ft_create_elem("2");
  new1->next->next = ft_create_elem("3");
  new1->next->next->next= ft_create_elem("4");
  new1->next->next->next->next= ft_create_elem("5");
  printf("%s\n",(char *)ft_list_at(new1, 3)->data);
}
