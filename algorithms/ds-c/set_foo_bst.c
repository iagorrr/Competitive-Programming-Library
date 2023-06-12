/*
  iagorrr ;)
  Foo implementation of a set
  using a non balanced bst.
  worst case is linear !!!
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int item;
  struct node *left, *right;
} node;

node *new_node(int item) {
  node *new = calloc(sizeof(node), 1);
  new->item = item;
  return new;
}

void insert(node **root, int item) {
  if (*root == NULL) {
    *root = new_node(item);
    return;
  }

  int cmp = item - (*root)->item;

  if (cmp == 0)
    return;

  if (cmp < 0)
    insert(&((*root)->left), item);
  else
    insert(&((*root)->right), item);
}

bool find(node *root, int item) {
  if (root == NULL)
    return false;

  int cmp = item - root->item;
  if (cmp == 0)
    return true;

  return cmp < 0 ? find(root->left, item) : find(root->right, item);
}

int32_t main(void) {
}

