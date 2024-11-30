#include "ft_create_elem.c"
#include "ft_list.h"
#include <stdio.h>
#include <string.h>

t_list *ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
  if(!cmp)
    return NULL;

  while((cmp)(begin_list->data,data_ref) != 0)
    begin_list = begin_list->next;
  return begin_list;
}
