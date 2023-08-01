#ifndef QUEUE
#define QUEUE
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct queue_node_st {
        void *item;
        struct queue_node_st *next;
} queue_node_st;

typedef struct queue_st {
        queue_node_st *first, *last;
        void (*freeItem)(void *);
        int size;
} queue_st;

queue_st *queue(void (*freeItem)(void *)) {
        // Construtor da queue
        queue_st *new_queue = malloc(sizeof(queue_st));
        new_queue->first = NULL;
        new_queue->last = NULL;
        new_queue->size = 0;
        new_queue->freeItem = freeItem;
        return new_queue;
}

queue_node_st *queue_node() { return calloc(1, sizeof(queue_node_st)); }

void queue_push_back(queue_st *q, void *item) {
        queue_node_st *new_node = queue_node();
        fprintf(stderr, "queue_push_back: start\n");
        fflush(stderr);
        if (new_node == NULL) {
                fprintf(stderr, "QUEUE-PUSH-BACK: faltou memória\n");
                fflush(stderr);
                exit(1);
        }
        new_node->item = item;
        new_node->next = NULL;

        if (q->size == 0) {
                fprintf(stderr, "ENTROU AQUI NO SIZE 0\n");
                q->first = new_node;
                q->last = new_node;
        } else {
                fprintf(stderr, "ENTROU AQUI NO SIZE != 0\n");
                q->last->next = new_node;
                q->last = new_node;
        }
        fprintf(stderr, "SAIU DA INSERÇÃO NA FILINHA\n");
        q->size++;
        fprintf(stderr, "queue_push_back: end\n");
        fflush(stderr);
}

void queue_pop(queue_st *q) {
        if (q->size == 1) {
                q->freeItem(q->first->item);
                free(q->first);
                q->last = NULL;
                q->first = NULL;
        } else {
                queue_node_st *tmp = q->first->next;
                q->freeItem(q->first->item);
                free(q->first);
                q->first = tmp;
        }
        q->size--;
}

void *queue_front(queue_st *q) { return q->first->item; }

bool queue_empty(queue_st *q) { return q->size == 0; }

void queue_destroy(queue_st *q) {
        while (q->first) {
                q->last = q->first->next;
                q->freeItem(q->first->item);
                free(q->first);
                q->first = q->last;
        }
        free(q);
}

#endif
