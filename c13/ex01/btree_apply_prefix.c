#include "ft_btree.h"
#include "btree_create_node.c"
#include <stdio.h>
#include <string.h>


// void print_tree(t_btree *tree)
// {
//   if(!tree)
//     return;
//   printf("%s\n",(char *)tree->item);
//   print_tree(tree->left);
//   print_tree(tree->right);
// }

void btree_apply_prefix(t_btree *root, void (*applyf)(void *))
{
  if (!root)
    return;
  (applyf)(root->item);
  if(root->left)
    btree_apply_prefix(root->left, applyf);
  if(root->right)
    btree_apply_prefix(root->right, applyf);
}

// void caps(void *data)
// {
//   char *str = (char *)data;
//   while(*str)
//   {
//     *str-=32;
//     str++;
//   }
//   printf("%s\n",(char *)data);
// }

// int main()
// {
//   t_btree *t_btree = btree_create_node(strdup("a"));
//   t_btree->left = btree_create_node(strdup("b"));
//   t_btree->left->left = btree_create_node(strdup("c"));
//   t_btree->right= btree_create_node(strdup("d"));
//   t_btree->right->right = btree_create_node(strdup("e"));
//   print_tree(t_btree);
//   btree_apply_prefix(t_btree, caps);
// }


//             a
//            / \
//           b   d
//          /    \
//         c      e

