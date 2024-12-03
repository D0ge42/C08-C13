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

int	tree_height(t_btree *root)
{
	int	left;
	int	right;

	if (!root)
		return (0);
	left = tree_height(root->left);
	right = tree_height(root->right);
	return (max(left, right) + 1);
}

// Subfunction that will handle levels.
// Parameters that are worth to mention are clevel and *levels,
// which are respectively current_level and an array of integers
// that is gonna represent our levels.
// Function is recurisive and works like that.
// Every level will be initially set to 0 from the main function.
// We'll pass each node left, and right.
// If on one level there are two nodes,
// it means that levels[clevel] of the right node in our case,
// is gonna be set to 1 already.
// This means that first_item will be set to 0.
// We'll apply the function recurisively and that's it.

void	level_by_levels(t_btree *root, int clevel, int *levels,
		void (*applyf)(void *item, int current_level, int is_first))
{
	int	first_item;

	if (!root)
		return ;
	if (levels[clevel] == 1)
		first_item = 0;
	else
	{
		levels[clevel] = 1;
		first_item = 1;
	}
	(applyf)(root->item, clevel, first_item);
	level_by_levels(root->left, clevel + 1, levels, applyf);
	level_by_levels(root->right, clevel + 1, levels, applyf);
}

// This function is even easier. Takes tree height, with the previously made function.
// It mallocs an array of integers representing levels.
// Set each levels to 0 and apply the subfunction to the tree.
// Current level will start from 0 cause it's root node.

void	btree_apply_by_level(t_btree *root, void(applyf)(void *item,
			int current_level, int is_first))
{
	int	tree_h;
	int	*levels;
	int	i;

	tree_h = tree_height(root);
	levels = (int *)malloc(sizeof(tree_h));
	i = 0;
	while (i < tree_h)
		levels[i++] = 0;
	level_by_levels(root, 0, levels, applyf);
}

// void	print_levels(void *item, int c_level, int is_first)
// {
// 	printf("Item: %s , c_level: %i, is_first %i\n", (char *)item, c_level,
// 		is_first);
// }

// int	main(void)
// {
// 	t_btree	*tree;

// 	tree = btree_create_node("2");
// 	tree->left = btree_create_node("3");
// 	tree->left->right = btree_create_node("7");
// 	tree->left->right->right = btree_create_node("8");
// 	tree->left->left = btree_create_node("1");
// 	tree->right = btree_create_node("4");
// 	tree->right->right = btree_create_node("5");
// 	btree_apply_by_level(tree, print_levels);
// }

// //        2
// //       / \
// //      3   4
// //     / \   \
// //    1   7   5
// //         \
// //          8
