#include "ft_create_elem.c"
#include "ft_list.h"
#include <stdio.h>
#include <string.h>

void ft_list_foreach_if(t_list *begin_list, void (*f)(void *), void *data_ref, int (*cmp)())
{
  while(begin_list)
  {
    if((cmp)(begin_list ->data, data_ref) == 0)
      (f)(begin_list->data);
    begin_list = begin_list->next;
  }
}


// void caps(void *data)
// {
//   char *str = (char *)data;
//   while(*str)
//   {
//     *str -= 32;
//     str++;
//   }
// }

void print_list(t_list *list)
{
  while(list)
  {
    printf("%s\n",(char *)list->data);
    list = list->next;
  }
}

int main()
{
  char str[5] = "siuu";
  char str2[5] = "daje";
  t_list *new = ft_create_elem(str);
  new->next = ft_create_elem(str2);


  ft_list_foreach_if(new,caps,"siuu", strcmp);
  print_list(new);
}
