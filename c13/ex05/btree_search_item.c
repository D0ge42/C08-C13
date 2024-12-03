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

//Esempio nel cercare 7 nel binary tree.
//Navigo il left tree finchè root non è null.
//QUando arrivo a 1, controllo sinistra, root node e poi destra. Ritornano NULL.
//Ripeto lo stesso procedimento per il 3. 
//Root->right in questo caso non restituirà null.
//Assegno found a btree_search_item
//controllo se 7 (root node) è uguale a data_ref. 
//ritorno root->item

//        2
//       / \
//      3   4
//     / \   \
//    1   7   5
void *btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *, void *))
{
  void *found;
  if(root == NULL)
    return NULL;
  found = btree_search_item(root->left, data_ref, cmpf);
  if (found)
    return found;
  if (cmpf((root->item),data_ref) == 0)
    return root->item;
  else
    return btree_search_item(root->right,data_ref, cmpf);
}

// void *btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *, void *))
// {
//   if (root == NULL)
//     return NULL;
//   void *found;
//   found = btree_search_item(root->left, data_ref, cmpf);
//   if (found)
//     return found;
//   if (cmpf(root->item, data_ref) == 0)
//     return root->item;
//   return btree_search_item(root->right, data_ref, cmpf);
// }

int cmp(void *a, void *b)
{
  return strcmp((char *)a, (char *)b);
}

int main()
{
  t_btree *tree = btree_create_node("2");
  tree->left = btree_create_node("3");
  tree->left->right = btree_create_node("7");
  tree->left->left = btree_create_node("1");
  tree->right = btree_create_node("4");
  tree->right->right = btree_create_node("5");
  void *data = btree_search_item(tree, "7", cmp);
  printf("%s\n",(char *)data);
}

//        2
//       / \
//      3   4
//     / \   \
//    1   7   5
