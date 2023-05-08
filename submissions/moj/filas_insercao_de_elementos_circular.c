// iagorrr ;)
#include <stdio.h>
#include <stdlib.h>

typedef struct fila {
	int *dados;
	int N, p, u;
} fila;

int enfileira(fila *f, int x) {// [p, u[
  if(f->N == 0) {
    // fprintf(stderr, "fila vazia.\n");
    f->N = 4;
    f->dados = (int*) malloc(sizeof(int)*f->N);
    if(!f->dados) return 0;
    f->p = 0;
    f->u = 0;
  }
  else if((f->u)%f->N == f->p) {// fila cheia.
    int *temp = (int*) malloc(sizeof(int)*2*f->N);
    if(!temp) return 0;
    int i = 0;
    int j = f->p;
    do {
      temp[i] = f->dados[j];
      i++;
      j = (j+1) % f->N;
    }while( j != f->u);
    free(f->dados);
    f->dados = temp;
    f->p = 0;
    f->u = f->N;
    f->N *= 2;
	}

  // insere o elemento.
  f->dados[f->u] = x;
  f->u = (f->u+1)%f->N;

  return 1;
}
//
// void dbg(fila *f) {
//   printf("p: %d\n", f->p);
//   printf("u: %d\n", f->u);
//   printf("N: %d\n", f->N);
//   int i = f->p;
//   do {
//     printf("[%d] ", f->dados[i]);
//     i = (i+1)%(f->N);
//   }while(i != f->u);
//   printf("\n");
// }
// int main() {
//   fila *f = (fila*) (malloc(sizeof(fila)));
//   f->N=0;
//   while(1) {
//     int i;
//     scanf("%d", &i);
//     enfileira(f, i);
//     dbg(f);
//   }
// }
