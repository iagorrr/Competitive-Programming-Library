// iagorrr ;) wa20p
#include <stdio.h>
#include <stdlib.h>
typedef struct celula {
  char matricula[10];
  double mediaAtividades;
  double mediaProvas;
  struct celula *prox;
} celula;

/*
  * le na verdade começa em le->prox
  * não tem problema o primeiro de l1 estar vazia.
  *
*/
void relatorioMediaAtividades (celula *le, celula *l1, celula *l2, double media){
  celula *cur = le->prox;
  while(cur) {
    if(cur->mediaAtividades <= media) {
      l1->prox = cur;
      l1 = l1->prox;
    }
    else{
      l2->prox = cur;
      l2 = l2->prox;
    }
    cur = cur->prox;
  }
  l2->prox = NULL;
  l1->prox = NULL;
}
