// iagorrr ;)
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef int item_st;

typedef struct pq_st {
  int n; // tamanho max da heap
  int last; // ultimo elemento livre na heap.
  int *pq; // heap (armazena os enderecos)
  int *tab; // traduz indice do elemento pra pos na heap
  item_st *data;
} pq_st;

inline bool pq_greaterprio(pq_st *pq, int a, int b) {
  /*
    recebe a pos de dois elementos na heap
    e diz se a é menor que b.
  */
  int a_pos = pq->pq[a]; 
  int b_pos = pq->pq[b];
  return pq->data[a_pos] < pq->data[b_pos];
}

inline void pq_exch(pq_st *pq, int a, int b) {
  /*
    recebe a posicao de dois elementos na heap,
    e faz a troca, de suas posições em :
      - heap
      - tab
  */
  pq->tab[pq->pq[a]] = b;
  pq->tab[pq->pq[b]] = a;

  int posheaptemp = pq->pq[a];
  pq->pq[a] = pq->pq[b];
  pq->pq[b] = posheaptemp;
}
void pq_debug(pq_st *pq) {
  printf("=======================================\n");
  printf("pq: ");
  for(int i = 0 ; i  <= pq->n; ++i) {
    printf(" %d ", pq->pq[i]);
  }
  printf("\n");

  printf("tab: ");
  for(int i = 0 ; i  < pq->n; ++i) {
    printf(" %d ", pq->tab[i]);
  }
  printf("\n");

  printf("data: ");
  for(int i = 0 ; i  < pq->n; ++i) {
    printf(" %d ", pq->data[i]);
  }
  printf("\n");
  printf("last : %d\n", pq->last);

  printf("=======================================\n");
}
pq_st *pq_init(int n) {
  pq_st *pq = malloc(sizeof(pq_st)*n);
  pq->n = n;
  pq->last = 1;
  pq->pq =  malloc(sizeof(int)*(n+1));
  pq->tab =  malloc(sizeof(int)*n);
  pq->data = malloc(sizeof(int)*n);
  return pq;
}

void pq_fixup(pq_st *pq, int k) {
  /*
    recebe a pq, e a posicao da heap a se fazer o 
    fixup
  */
  while(k > 1 && pq_greaterprio(pq, k, k/2)){
    pq_exch(pq, k/2, k);
    k /= 2;
    
  }
}
void pq_insert(pq_st *pq, item_st item) {
  pq->pq[pq->last] = pq->last-1; 
  pq->tab[pq->last-1] = pq->last;
  pq->data[pq->last-1] = item;
  pq_fixup(pq, pq->last);
  pq->last++;
}

void pq_fixdown(pq_st *pq, int k) {
  /*
    recebe a pq e a posição na heap a se trocar.
  */
  k= 1;
  int j;
  int curlast = pq->last-1;
  while(k*2 <= curlast) {
    j = k*2;
    if(j < curlast && pq_greaterprio(pq, j+1, j)) j++;
    if(pq_greaterprio(pq, k, j)) break;
    pq_exch(pq, k, j);
    k *= 2;
  }
}
void pq_pop(pq_st *pq) {
  pq_exch(pq, 1, pq->last-1);
  pq->last--;
  pq_fixdown(pq, 1);
}

void pq_change(pq_st *pq, int k, int prio) {
  /*
    k : posicao do item na tabela.
    prio: nova prioridade do item.
  */
  pq->data[k] = prio;
  pq_fixup(pq, pq->tab[k]);
  pq_fixdown(pq, 1);
}

item_st pq_top(pq_st *pq) {
  return pq->data[pq->pq[1]];
}


void solve(int n, int k) {
  item_st *notas = (int*) malloc(sizeof(int)*n);
  for(int i = 0; i < n; ++i) {
    scanf("%d", &notas[i]);
  }

  // insere os k primeiros.
  pq_st *pq = pq_init(k);
  for(int i = 0; i < k; ++i) {
    pq_insert(pq, notas[i]);
  }

  int antigo = 0;
  int novo = k;
  while(novo <= n) {
    item_st menor  = pq_top(pq);
    printf("%d%c", menor, " \n"[novo ==n]);
    if(novo == n) break;
    pq_change(pq, antigo, notas[novo]);
    pq_debug(pq);
    antigo = (antigo+1) % k;
    novo++;
  }
}
int main() {
  int n=1, k=1;
  while (n && k) {
    scanf("%d %d", &n, &k); 
    if(n && k)
      solve(n, k); 
  }
}
