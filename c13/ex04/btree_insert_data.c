#include "btree_create_node.c"
#include "ft_btree.h"
#include <stdio.h>
#include <string.h>

// void	print_tree(t_btree *tree)
// {
// 	if (!tree)
// 		return ;
// 	print_tree(tree->left);
// 	printf("%s ", (char *)tree->item);
// 	print_tree(tree->right);
// }

// Function will work like that.
// First time that is called will create a root node.
// From the 2nd to the last call all the nodes will be placed right or left depending on the node we're currently at.
// Let's say we've this tree 4
//                          / \
//                         1   8
// If function is called with item parameter "4"
// Steps are gonna be -> 4 is higher equal than 4 so it goes right to root.
// If current node already exists, it means we haven't reached the end.
// Recursive call with &new_tree->right.
// Current new_tree->item is 8 and 4 is < than 8, so it goes left.
// Since new_tree->left doesn't exists, we create it.
// end.
// Final result will be:      4
//                          /  \
//                         1    8
//                             /
//                            4
void	btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *,
			void *))
{
	t_btree	*new_tree;

	// First call will enter this and create the root node.
	if (!*root)
	{
		*root = btree_create_node(item);
		return ;
	}
	new_tree = *root;
	if ((cmpf)(item, new_tree->item) < 0)
	{
		if (new_tree->left)
			btree_insert_data(&new_tree->left, item, cmpf);
		else
			new_tree->left = btree_create_node(item);
	}
	else
	{
		if (new_tree->right)
			btree_insert_data(&new_tree->right, item, cmpf);
		else
			new_tree->right = btree_create_node(item);
	}
}

// int	cmp(void *a, void *b)
// {
// 	return (strcmp((char *)a, (char *)b));
// }

// int	main(void)
// {
// 	t_btree	*tree;

// 	tree = NULL;
// 	btree_insert_data(&tree, "4", cmp);
// 	btree_insert_data(&tree, "8", cmp);
// 	btree_insert_data(&tree, "1", cmp);
// 	btree_insert_data(&tree, "4", cmp);
// 	btree_insert_data(&tree, "5", cmp);
// 	btree_insert_data(&tree, "3", cmp);
// 	btree_insert_data(&tree, "3", cmp);
// 	print_tree(tree);
// }

// //           4
// //         /   \
// //        1     8
// //         \    /
// //          3  4
// //           \  \
// //            3  5
// //
