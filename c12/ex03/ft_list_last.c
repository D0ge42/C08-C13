#include "ft_list.h"
#include "ft_create_elem.c"

t_list *ft_list_last(t_list *begin_list)
{
  while(begin_list->next)
    begin_list = begin_list->next;
  return begin_list;
}
#include <stdio.h>

int main()
{
  t_list *new = ft_create_elem("mew");
  new->next = ft_create_elem("miao");
  new->next->next = ft_create_elem("bao");
  printf("%s\n",(char *)ft_list_last(new)->data);
}
