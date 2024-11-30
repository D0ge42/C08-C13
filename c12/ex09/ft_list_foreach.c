#include "ft_create_elem.c"
#include "ft_list.h"
#include <stdio.h>

void ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
  while(begin_list->next)
  {
    (f)(begin_list->data);
    begin_list = begin_list->next;
  }
}


// void print_list(t_list *list)
// {
//   while(list)
//   {
//     printf("%s\n",(char *)list->data);
//     list = list->next;
//   }
// }

// void caps(void *data)
// {
//   char *string = (char *)data;
//   printf("%s\n",string);
//   while(*string)
//   {
//     *string -= 32;
//     string++;
//   }
// }

// int main()
// {
//   char string[5] = "ciao";
//   t_list *new = ft_create_elem(string);
//   new->next = ft_create_elem(string);
//   new->next->next = ft_create_elem(string);
//   ft_list_foreach(new, caps);
// }
