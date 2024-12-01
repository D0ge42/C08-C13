#include "ft_btree.h"
#include "btree_create_node.c"
#include <stdio.h>
#include <string.h>


void print_tree(t_btree *tree)
{
  if(!tree)
    return;
  printf("%s\n",(char *)tree->item);
  print_tree(tree->left);
  print_tree(tree->right);
}

void btree_insert_data(t_btree **root, void *ite, int(*cmpf)(void *, void *))
{
  
}


//             a
//            / \
//           b   d
//          /    \
//         c      e

