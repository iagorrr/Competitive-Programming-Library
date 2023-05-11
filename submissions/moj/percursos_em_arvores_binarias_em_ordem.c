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

no *pop(stack *st) {
  cell *tmp = st->stack;
  st->stack=st->stack->next;
  free(tmp);
}

void em_ordem(no *raiz) {
  stack *st = malloc(sizeof(stack));
  put(st, raiz);

  while(!empty(st)) {
    no *cur = get(st);
    if(cur == NULL) {
      pop(st);
      if(empty(st)) break;
      cur =  get(st);
      printf("%d ", cur->dado);
      pop(st);
      put(st, cur->dir);
    }
    else {
      put(st, cur->esq);
    }
  }
  printf("\n");
}
