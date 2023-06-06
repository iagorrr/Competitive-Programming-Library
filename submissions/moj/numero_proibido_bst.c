/*
  iagorrr ;)
  implementação dos números malucos não ordenados
  utilizando uma BST para verificação de repetições.
*/

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

node *find(node *root, int item) {
  if (root == NULL)
    return NULL;

  int cmp = item - root->item;
  if (cmp == 0)
    return root;

  return cmp < 0 ?
         find(root->left, item) :
         find(root->right, item);
}
int32_t main(void) {
  int n;
  scanf("%i", &n);

  node *root = NULL;
  while (n--) {
    int x;
    scanf("%i", &x);
    insert(&root, x);
  }

  int x;
  while(scanf("%d", &x) != EOF){
    printf("%s\n",
           find(root, x) == NULL ? "nao" : "sim");
  }
}

// AC.
