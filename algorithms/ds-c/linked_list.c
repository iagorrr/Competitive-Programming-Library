/*
 * iagorrr ;)
 * Linked list implementation.
 * 'methods':
 *      - constructor O(1)  : alloc and returns the addres of a linked list head.
 *      - destructor  O(N)  : free each node a and the linked list had. 
 *      - back        O(1)  : returns the last node value.
 *      - push back   O(1)  : add a new node after the next with the given value.
 *      - pop back    O(N)  : search for the antepenultimate value, set as the last and free the previous last.
 *      - front       O(1)  : returns the first node value.
 *      - push front  O(1)  : add a new node before the first with the given value.
 *      - pop front   O(1)  : set the first as the next of the previous first.
 *      - empty       O(1)  : check if the size is 0.
 *      * There is no error treatment for invalid iserts, removals, or access.
 */
#include <stdio.h>
#include <stdlib.h>
#define Item int

typedef struct linked_list_node_t
{
    Item i;
    struct linked_list_node_t *next;
} linked_list_node_t;

typedef struct linked_list
{
    linked_list_node_t *first;
    linked_list_node_t *last;

    int size;
    char (*empty)(struct linked_list*);
    void (*push_back)(struct linked_list*, Item);
    void (*push_front)(struct linked_list*, Item);
    void (*pop_front)(struct linked_list*);
    void (*pop_back)(struct linked_list*);
    Item (*back)(struct linked_list*);
    Item (*front)(struct linked_list*);
} linked_list;

linked_list* linked_list_constructor();
char linked_list_empty();
void linked_list_push_back(linked_list *ll, Item x);
void linked_list_push_front(linked_list *ll, Item x);
void linked_list_pop_front(linked_list *ll);
void linked_list_pop_back(linked_list *ll);
Item linked_list_back(linked_list* ll);
Item linked_list_front(linked_list* ll);

linked_list_node_t* linked_list_node_t_constructor();
/*=============================================================================================*/
int main(){
}
/*=============================================================================================*/

linked_list* linked_list_constructor()
{
    linked_list *new = (linked_list*) malloc(sizeof(linked_list));

    new->first = NULL;
    new->last = NULL;

    new->size = 0;
    new->empty = linked_list_empty;
    new->push_back = linked_list_push_back;
    new->push_front = linked_list_push_front;
    new->pop_back = linked_list_pop_back;
    new->pop_front = linked_list_pop_front;
    new->back = linked_list_back;
    new->front =  linked_list_front;
}

char linked_list_empty(linked_list *ll)
{
    return ll->size == 0;
}

void linked_list_push_back(linked_list *ll, Item x)
{
    linked_list_node_t *new = linked_list_node_t_constructor(); 

    if(ll->empty(ll))
    {
        ll->first = new;
        ll->last = new;
    }
    else
    {
        ll->last->next = new;
        ll->last = new;
    }

    ll->size++;
}

void linked_list_push_front(linked_list *ll, Item x)
{
    linked_list_node_t *new = linked_list_node_t_constructor();
    new->i = x;

    if(ll->empty(ll)){
        ll->last = new;
        ll->first = new;
    }
    else{ 
        new->next = ll->first;
        ll->first = new;
    }

    ll->size++;
}

void linked_list_pop_front(linked_list *ll)
{
    linked_list_node_t* t = ll->first;

    ll->first = ll->first->next;

    if(ll->size == 1) ll->last = NULL;

    ll->size--;

    free(t);
}

void linked_list_pop_back(linked_list *ll){

    linked_list_node_t *cur = ll->first;
    linked_list_node_t *prev = NULL;
    while(cur->next){
        prev = cur;
        cur = cur->next;
    }

    cur = ll->last;
    ll->last = prev;

    if(ll->size == 1) ll->first = NULL;

    ll->size--;
    free(cur);
}

linked_list_node_t* linked_list_node_t_constructor()
{
    linked_list_node_t *new = (linked_list_node_t*) malloc(sizeof(linked_list_node_t));
    new->next = NULL;
    return new;
}

void linked_list_destructor(linked_list *ll){
    linked_list_node_t *cur = ll->first;
    linked_list_node_t *t = NULL;

    while(cur){
        t = cur->next;
        free(cur);
        cur = t;
    }

    free(ll);
}

Item linked_list_back(linked_list *ll){
    return ll->last->i;
}

Item linked_list_front(linked_list *ll){
    return ll->first->i;
}
