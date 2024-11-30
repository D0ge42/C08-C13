#include "ft_create_elem.c"
#include "ft_list.h"
#include <stdio.h>
#include <string.h>

void	print_list(t_list *list)
{
	while (list)
	{
		printf("%s->", (char *)list->data);
		list = list->next;
	}
	printf("\n");
}

// void	ft_list_reverse_fun(t_list *begin_list)
// {
// 	t_list	*ptr;
// 	int		i;
// 	void	*arr[i];

// 	ptr = begin_list;
//   i = 0;

// 	while (begin_list)
// 	{
// 		arr[i] = begin_list->data;
// 		begin_list = begin_list->next;
// 		i++;
// 	}
// 	while (ptr && i)
// 	{
// 		ptr->data = arr[i - 1];
// 		ptr = ptr->next;
// 		i--;
// 	}
// }

void ft_list_reverse_fun(t_list *begin_list)
{
  void *tmp;
  t_list *start = begin_list;
  t_list *end;
  t_list *end_finder;
  while(begin_list->next)
    begin_list = begin_list->next;
  end = begin_list;
  while(start != end)
  {
    tmp = start->data;
    start->data = end->data;
    end->data = tmp;
    end_finder = start;
    while(end_finder->next!= end)
      end_finder = end_finder->next;
    end = end_finder;
    start = start->next;
  }
  begin_list = start;
}

int	main(void)
{
	t_list	*new;

	new = ft_create_elem("1");
	new->next = ft_create_elem("2");
	new->next->next = ft_create_elem("3");
	new->next->next->next = ft_create_elem("4");
	new->next->next->next->next = ft_create_elem("5");
  new->next->next->next->next->next = ft_create_elem("6");
  new->next->next->next->next->next->next= ft_create_elem("7");
  ft_list_reverse_fun(new);
	print_list(new);
}
