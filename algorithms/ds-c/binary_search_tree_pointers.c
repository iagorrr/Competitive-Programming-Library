/*
  iagorrr ;)
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct item_st {
  int first;
  int second;
} item_st;

bool less(const item_st *a, const item_st *b) {
  return (a->first == b->first ? a->second < b->second : a->first < b->first);
}
bool eq(item_st *a, item_st *b) { 
  return a->first == b->first && b->second == a->second;
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
  if (!*root)
    *root = cur;
  else if (less(&prev->info, item))
    prev->left = cur;
  else
    prev->right = cur;
}
void erase_merge(node_st **root) {
  node_st *cur = *root;
  if(!cur) return;
  if(cur->right == NULL)
    *root = cur->left;
  else if(cur->left == NULL)
      *root = cur->right;
  else {
    node_st *temp = cur->left;  
    while(temp->right)
      temp = temp->right;

    temp->right = cur->right;
    *root = cur->left;
  }
  free(cur);
}
void erase_copy(node_st **root) {
  node_st *cur = *root;

  if(cur == NULL) return;

  if(cur->right == NULL)
    *root = cur->left;
  else if(cur->left == NULL)
      *root = cur->right;
  else {
    node_st *temp = (*root)->left;

    while(temp->right != NULL)
      temp = temp->right;

    cur->info = temp->info;
    return;
  }
}
void erase(node_st *root, item_st *item) {
  node_st **cur = &root;
  while(*cur) {
    item_st *tempit = &(*cur)->info;
    if(eq(tempit, item))
      break;
    if(less(tempit, item))
      cur = &(*cur)->right;
    else
      cur = &(*cur)->left;
  }
  // erase_merge(cur);
  erase_copy(cur);
}

int size_rec(node_st *root) {
  if(root == NULL) return 0;
  return size_rec(root->left) + size_rec(root->right);
}

bool search_rec(node_st *root, item_st *item) {
  if(root == NULL) return false;
  if(eq(&root->info, item)) return true;
  if(less(&root->info, item)) return search_rec(root->right, item);
  else return search_rec(root->left, item);
}

bool search(node_st *root, item_st *item) {
  while(root) {
    if(eq(&root->info, item)) return true;

    if(less(&root->info, item)) root = root->right;
    else root = root->left;
  }
  return false;
}

void visit(node_st *root) {
  printf("[%d, %d]\n", root->info.first,
         root->info.second);
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
int main(void) {}
