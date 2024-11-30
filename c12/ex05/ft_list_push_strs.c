#include "ft_create_elem.c"
#include "ft_list.h"
#include <stdio.h>

//Since last element of our struct points to null we can create one node that points to null.
//This will be the head of the list.
//We'll then start creating the list from it.

//We'll save current_node->next to be our list's head.
//Then update list head to be the current node.
//Like this nodes will be linked to eachothers.

t_list *ft_list_push_strs(int size, char **strs)
{
  t_list *new_list;
  t_list *head = NULL;
  int i = 0;
  int j = 0;
  while(i < size)
  {
    new_list = ft_create_elem(strs[i]);
    new_list->next = head;
    head = new_list;
    i++;
  }
  return new_list;
}

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
  char *strs[] = {"ciao","come","state","?"};
  t_list *lista = ft_list_push_strs(4, strs);
  print_list(lista);
}
