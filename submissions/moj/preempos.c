// iagorr ;)
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define right(i) (i*2+1)
#define left(i) (i*2)

const int max = 256*2;
char *solve(char *preorder, char *inorder, int n) {

  char *tree = malloc(sizeof(char)*max);
  for(int i = 0; i < max; ++i) tree[i] = 0;

  int mappos[256*2];
  for(int i = 0; i < n; ++i)
    mappos[inorder[i]] = i;

  tree[1] = preorder[0];
  for(int i = 1; i < n; ++i){

    char toinsert = preorder[i];
    int toinsertpos = mappos[toinsert];
    int node = 1; 

    while(tree[node]) {
      int nodepos = mappos[tree[node]];

      if(toinsertpos < nodepos){
        node = left(node);
      }
      else {
        node = right(node);
      }
    }

    tree[node] = toinsert;
  }

  return tree;
}

void posorder(char *root, int i) {
  if(i < max && root[i]) {
    posorder(root, left(i));
    posorder(root, right(i));
    printf("%c", root[i]);
  }
}
int main(void) {
  int t; scanf("%d", &t);

  while(t--) {
    int n; scanf("%d", &n);
    char a[53*2]; char b[53*2];
    scanf("%s %s", a, b);
    char *c = solve(a, b, n);
    posorder(c, 1); printf("\n");
  }
}

// AC, árvore binária de busca, travessia.
