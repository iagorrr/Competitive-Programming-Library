/*
 * iagorrr ;)
 * Circular queue implementation. 
 *      - static size.
 *      - 'methods':
 *          - initialize.
 *          - enqueue.
 *          - dequeue.
 *          - front.
 *          - back.
 *          - size.
 *          - show_queue (must for debug)
 */
#include <stdio.h>
#define MAXQUEUESIZE (int)1e5
#define Item_t int

typedef struct queue
{
    int l;
    int r;
    int maxsize;
    int csize;
    Item_t q[MAXQUEUESIZE];
    
    int (*enqueue)(struct queue*, Item_t);
    void (*dequeue)(struct queue*);
    Item_t (*front)(struct queue*); 
    Item_t (*back)(struct queue*);
    int (*size)(struct queue*);
    void (*show)(struct queue*);
} queue;

int queue_enqueue(queue *q, Item_t i);
void queue_dequeue(queue*q);
Item_t queue_front(queue *q);
Item_t queue_back(queue *q);
int queue_empty(queue *q);
int queue_full(queue* q);
queue queue_initialize(int maxs);
int queue_size(queue *q);
void queue_show(queue *q);

int main(void)
{
    queue q = queue_initialize(5);

    q.enqueue(&q, 4);
    q.enqueue(&q, 3);
    q.enqueue(&q, 2);
    q.enqueue(&q, 1);
    q.enqueue(&q, 5);

    q.show(&q);

    q.dequeue(&q);

    q.show(&q);

    q.dequeue(&q);

    q.enqueue(&q, -3);
    q.enqueue(&q, -2);

    q.show(&q);
}



queue queue_initialize(int maxs)
{
    queue new;

    new.l = 0;
    new.r = 0;
    new.csize = 0;
    new.maxsize = maxs;

    new.enqueue = queue_enqueue;
    new.dequeue = queue_dequeue;
    new.front = queue_front;
    new.back = queue_back;
    new.size = queue_size;
    new.show = queue_show;
    
    return new;
}

void queue_show(queue *q)
{
    printf("l: %d r: %d size: %d\n", q->l, q->r, q->size(q));

    for(int i = 0; i < q->maxsize; ++i) printf("%d ", q->q[i]);
    printf("\n");

}
int queue_full(queue* q)
{
    return (q->r+1 == q->l) || (q->r+1 == q->maxsize && q->l == 0);
}

int queue_empty(queue *q)
{
    return q->l == q->r;
}

Item_t queue_back(queue *q)
{
    return q->q[q->r-1];
}

Item_t queue_front(queue *q)
{
    return q->q[q->l];
}

void queue_dequeue(queue*q)
{
    q->l = (q->l+1) % q->maxsize;
    q->csize--;
}

int queue_enqueue(queue *q, Item_t i) {
    if(q->r == q->maxsize) return 0;
    
    q->q[q->r] = i;

    q->r = (q->r + 1) % q->maxsize;
    
    q->csize++;
    return 1;
}

int queue_size(queue* q)
{
    return q->csize;
}
