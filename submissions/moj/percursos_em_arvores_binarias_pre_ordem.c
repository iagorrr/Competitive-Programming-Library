// iagorrr ;)
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no {
  int dado;
  struct no *esq, *dir;
} no;

typedef struct cell {
  no *cont;
  struct cell *next;
} cell;

typedef struct stack {
  cell *stack;
} stack;

void put(stack *st, no *cont) {
  cell *cur = malloc(sizeof(cell));
  cur->cont = cont;
  cur->next = st->stack;
  st->stack=cur;
}

no* get(stack *st){
  return st->stack->cont;
}

bool empty(stack *st) {
  return st->stack==NULL;
}

void pop(stack *st) {
  cell *tmp = st->stack;
  st->stack=st->stack->next;
  free(tmp);
}

void pre_ordem(no *raiz) {
  if(!raiz) return;
  stack *st = malloc(sizeof(stack));
  put(st, raiz); 
  while(!empty(st)){
    no *cur = get(st);
    printf("%d ", cur->dado);
    pop(st);
    if(cur->dir)
      put(st, cur->dir);
    if(cur->esq)
      put(st, cur->esq);
  }
  printf("\n");
}

// AC, árvoes binárias pre ordem.
