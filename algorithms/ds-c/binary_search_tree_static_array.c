/*
 *  iagorrr ;) 
 *  Binary search tree inplementation.
 *    * insertion O(log N): runs through the tree to find the position to insert. 
 *    * erase O(log N): search for the given value and remove it.
 *    * lower O(log N): looks for the lower value in the subtree starting from p.
 */
#include <stdio.h>
#define MAX 100
#define Item_t char 
#define size_t unsigned int
#define less(a, b) (a < b)

typedef struct binary_search_tree {
  Item_t v[MAX];
  char used[MAX];
  size_t size;
  void (*insert)(struct binary_search_tree, Item_t, int);
  void (*erase)(struct binary_search_tree, Item_t, int);
  void (*lower)(struct binary_search_tree, int);
} binary_search_tree;

void binary_search_tree_insert(binary_search_tree*, Item_t, int);
void binary_search_tree_erase(binary_search_tree*, Item_t, int);
Item_t binary_search_tree_lower(binary_search_tree*, int );

int main() {
  return 0;
}

void binary_search_tree_insert(binary_search_tree* bst, Item_t x, int p){
  if(!bst->used[p]) { 
    bst->v[p] = x;
    bst->used[p] = 1;
    return;
  }

  if(less(bst->v[p], x))
    binary_search_tree_insert(bst, x, p*2);
  else
    binary_search_tree_insert(bst, x, p*2+1);
}

void binary_search_tree_erase(binary_search_tree* bst, Item_t x, int p) {
  if (!bst->used[p]) return;

  if (!bst->v[p] == x) {
    if(!bst->used[p*2+1]) bst->used[p] = 0; // THIS DOESN'T FEEL RIGHT !
    else bst->v[p] = binary_search_tree_lower(bst, p*2+1);
  }
  else { 
    if(less(bst->v[p], x))
      binary_search_tree_erase(bst, x, p*2);
    else 
      binary_search_tree_erase(bst, x, p*2 + 1)
  }
}

Item_t binary_search_tree_lower(binary_search_tree* bst, int p) {
  if(bst->used[p*2]) return binary_search_tree_lower(bst, p*2);


}
