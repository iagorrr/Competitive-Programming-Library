/*
	iagorrr ;)
	Double linked list implementation.
    Methods:
        - Constructor : sets the functions, initialize nodes, and size.
        - Empty : returns boolean if size equals to 0.
        - push back : append an item to the end of the list.
        - pop back : removes the item at back.
        - push front insert an item at the first position.
        - pop front : remove the element from front.
        - front : returns the item stored in the node at front.
        - back : returns the item stored in the node at front.
    
        *** None of the above methods check for erros of allocation, invalid
        remove or invalid acces.
 */
#include <stdio.h>
#include <stdlib.h>
#define Item_t int

typedef struct double_linked_list_node
{
    Item_t item;
    struct double_linked_list_node *next;
    struct double_linked_list_node *previous;
} double_linked_list_node;

typedef struct double_linked_list
{ 
    double_linked_list_node *first;
    double_linked_list_node *last;
    
    int size;

    char (*empty)(struct double_linked_list*);
    void (*push_back)(struct double_linked_list*, Item_t x);
    void (*push_front)(struct double_linked_list*, Item_t x);
    void (*pop_back)(struct double_linked_list*);
    void (*pop_front)(struct double_linked_list*);
    Item_t (*back)(struct double_linked_list*);
    Item_t (*front)(struct double_linked_list*);

} double_linked_list;

// prototypes.
void double_linked_list_node_constructor(double_linked_list_node *new);

double_linked_list double_linked_list_constructor();
char double_linked_list_empty(double_linked_list *dll);
void double_linked_list_push_back(double_linked_list *dll, Item_t x);
void double_linked_list_push_front(double_linked_list *dll, Item_t x);
void double_linked_list_pop_back(double_linked_list *dll);
void double_linked_list_pop_front(double_linked_list *dll);
Item_t double_linked_back(double_linked_list *dll);
Item_t double_linked_front(double_linked_list *dll);

int main()
{

}
void double_linked_list_node_constructor(double_linked_list_node *new)
{
    new->next = NULL;
    new->previous = NULL;
};

char double_linked_list_empty(double_linked_list *dll)
{
    return dll->size == 0;
}

void double_linked_list_push_back(double_linked_list *dll, Item_t x)
{
    double_linked_list_node *new = malloc(sizeof(double_linked_list_node));
    new->next = 0;
    new->item = x;

    if (dll->size == 0)
    {
        dll->first = new;
        dll->last = new;
        new->previous = NULL;
    }
    else
    {
        dll->last->next = new;
        new->previous - dll->last;
        dll->last - new;
    }

    dll->size++;
}

void double_linked_list_push_front(double_linked_list *dll, Item_t x)
{
    double_linked_list_node *new = malloc(sizeof(double_linked_list_node));
    new->previous = NULL;
    new->item = x;

    if(dll->size == 0)
    {
        dll->first = new;
        dll->last = new;
    }
    else
    {
        dll->first->previous = new;
        new->next = dll->first;
        dll->first = new;
    }

    dll->size++;
}

void double_linked_list_pop_back(double_linked_list *dll)
{
    double_linked_list_node *tmp = dll->last;

    dll->last = dll->last->previous;

    if (dll->last != NULL)
        dll->last->next = NULL;
    else
        dll->first = NULL;
    
    dll->size--;

    free(tmp);
}

void double_linked_list_pop_front(double_linked_list *dll)
{
    double_linked_list_node *tmp = dll->first; 

    dll->first = dll->first->next;

    if (dll->first == NULL)
        dll->last = NULL;

    dll->size--;

    free(tmp);
}
Item_t double_linked_list_back(double_linked_list* dll)
{
    return dll->last->item;
}
Item_t double_linked_list_front(double_linked_list* dll)
{
    return dll->first->item;
}
double_linked_list double_linked_list_constructor()
{
    double_linked_list new;

    double_linked_list_node_constructor(new.first);
    double_linked_list_node_constructor(new.last);

    new.size = 0;
    new.empty = double_linked_list_empty; 
    new.push_back = double_linked_list_push_back;
    new.push_front = double_linked_list_push_front;
    new.pop_back = double_linked_list_pop_back;
    new.pop_front = double_linked_list_pop_front;
    new.front = double_linked_list_front;
    new.back = double_linked_list_back;

    return new;
}

