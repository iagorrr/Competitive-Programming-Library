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

void pos_ordem(no *raiz) {
  if(!raiz) return;
  stack *st = malloc(sizeof(stack));
  stack *aux = malloc(sizeof(stack));
  put(st, raiz); 
  while(!empty(st)){
    if(!empty(aux) && (get(st) == get(aux))){
      no *tmp = get(st);
      printf("%d ", tmp->dado);
      pop(st);
      pop(aux);
      continue;
    }
    no *tmp = get(st);
    if(tmp->dir)
      put(st, tmp->dir);
    if(tmp->esq)
      put(st, tmp->esq);
    put(aux, tmp);
  }
  printf("\n");
}

// AC, árvores binárias pós ordem.
