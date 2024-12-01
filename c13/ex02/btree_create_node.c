#include "ft_btree.h"

t_btree	*btree_create_node(void *item)
{
	t_btree	*new;

	new = (t_btree *)malloc(sizeof(t_btree));
	new->left = 0;
	new->right = 0;
	new->item = item;
	return (new);
}
