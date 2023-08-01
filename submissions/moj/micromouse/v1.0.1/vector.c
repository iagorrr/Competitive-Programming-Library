#ifndef VECTOR
#define VECTOR
#include <stdio.h>
#include <stdlib.h>

typedef struct vector_st {
        void **items;
        void (*free_item)(void *);
        int capacity;
        int size;
} vector_st;

vector_st *vector(int n, void (*free_item)(void *)) {
        vector_st *newVec = malloc(sizeof(vector_st));
        newVec->size = 0;
        newVec->capacity = n;
        newVec->free_item = free_item;
        newVec->items = malloc(sizeof(void *) * n);
        return newVec;
}

void vector_push_back(vector_st *v, void *item) {
        if (v->capacity == v->size) {
                v->items = realloc(v->items, sizeof(void *) * v->size * 2);
                v->capacity = v->size * 2;
        }

        v->items[v->size++] = item;
}

void vector_pop_back(vector_st *v) {
        v->free_item(v->items[v->size - 1]);
        v->size--;
}

void *vector_back(vector_st *v) { return v->items[v->size - 1]; }

void *vector_front(vector_st *v) { return v->items[0]; }

void print_int_item(void *item) {}
void debug_vector(vector_st *v, void(print_item)(void *)) {
        for (int i = 0; i < v->size; i++) {
                print_item(v->items[i]);
        }
}

void free_item_f(void *a) { free(a); }

void vector_destroy(vector_st *v) {
        for (int i = 0; i < v->size; i++) {
                v->free_item(v->items[i]);
        }
        free(v->items);
        free(v);
}
#endif
