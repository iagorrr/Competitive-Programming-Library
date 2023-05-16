/*
  iagorrr ;)
  * salva o conteúdo por cópia.
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct item_st {
  int item;
} item_st;

bool less(const item_st *a, const item_st *b) {
  return a->item < b->item;
}
bool eq(item_st *a, item_st *b) { 
  return a->item == b->item;
}

typedef struct node_st {
  item_st info;
  struct node_st *left, *right;
} node_st;

void insert(node_st **root, item_st *item) {
  node_st *cur = *root;
  node_st *prev = NULL;
  while (cur) {
    prev = cur;
    if (eq(&(cur->info), item))
      return;
    if (less(&(cur->info), item)) {
      cur = cur->right;
    } else {
      cur = cur->left;
    }
  }
  cur = malloc(sizeof(node_st));
  cur->info = *item;
  cur->left = NULL;
  cur->right = NULL;
  if (!*root){
    *root = cur;
  }
  else if (less(&prev->info, item)){
    prev->right = cur;
  }
  else{
    prev->left = cur;
  }
}
void visit(node_st *root) {
  printf("%d ", root->info.item);
}
void preorder_rec(node_st *root) {
  if(root) {
    visit(root);
    preorder_rec(root->left);
    preorder_rec(root->right);
  }
}
void inorder_rec(node_st *root) {
  if(root){
    inorder_rec(root->left);
    visit(root);
    inorder_rec(root->right);
  }
}
void posorder_rec(node_st *root) {
  if(root){
    posorder_rec(root->left);
    posorder_rec(root->right);
    visit(root);
  }
}
int main(void) {
  int xi;
  node_st *root=NULL;
  while(scanf("%d", &xi)!=EOF){
    item_st a;
    a.item = xi;
    insert(&root, &a);
  }
  preorder_rec(root); printf(".\n");
  inorder_rec(root); printf(".\n");
  posorder_rec(root); printf(".\n");
}
// AC, árvoes binárias, todas travessias.
