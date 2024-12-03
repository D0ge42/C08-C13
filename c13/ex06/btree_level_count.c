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

int	max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
int	btree_level_count(t_btree *root)
{
	int	levels_left;
	int	levels_right;

	if (!root)
		return (0);
	levels_left = 1;
	levels_right = 1;
	levels_left = btree_level_count(root->left) + 1;
	levels_right = btree_level_count(root->right) + 1;
	return (max(levels_left, levels_right));
}

int	main(void)
{
	t_btree	*tree;

	tree = btree_create_node("2");
	tree->left = btree_create_node("3");
	tree->left->right = btree_create_node("7");
	tree->left->right->right = btree_create_node("8");
	tree->left->left = btree_create_node("1");
	tree->right = btree_create_node("4");
	tree->right->right = btree_create_node("5");
	printf("%i\n", btree_level_count(tree));
}

//        2
//       / \
//      3   4
//     / \   \
//    1   7   5
//         \
//          8
