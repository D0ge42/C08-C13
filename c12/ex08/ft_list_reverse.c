#include "ft_create_elem.c"
#include "ft_list.h"
#include <stdio.h>

void ft_list_reverse(t_list **begin_list)
{
  t_list *curr = *begin_list;
  t_list *prev = NULL;
  t_list *next = NULL;

  while(curr)
  {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  *begin_list = prev;
}

// void print_list(t_list *list)
// {
//   while(list)
//   {
//     printf("%s ->",(char *)list->data);
//     list = list->next;
//   }
// }

// int main()
// {
//   t_list *new1 = ft_create_elem("1");
//   new1->next = ft_create_elem("2");
//   new1->next->next = ft_create_elem("3");
//   new1->next->next->next = ft_create_elem("4");
//   new1->next->next->next->next = ft_create_elem("5");
//   ft_list_reverse(&new1);
//   print_list(new1);
// }
