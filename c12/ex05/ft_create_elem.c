#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}
// #include <stdio.h>

// int main()
// {
//   int i = 4;
//   t_list *new = ft_create_elem(&i);
//   printf("%i\n",*(int *)new->data);
// }
