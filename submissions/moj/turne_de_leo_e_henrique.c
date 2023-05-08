/* iagorrr ;)
	Double linked list implementation.
	- Constructor
	- Empty
    - set first
    - set last
    - move next
    - move previous
    - remove current.
	- push back
	- pop back
	- push front
	- pop front
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct parzin {
    int n;
    char* s;
} parzin;
#define Item parzin 
#define queue linked_list_root_t 
typedef struct linked_list_node_t 
{
	Item item;
	struct linked_list_node_t *next;
	struct linked_list_node_t *previous;
} linked_list_node_t;

typedef struct linked_list_root_t
{
	linked_list_node_t *first;
	linked_list_node_t *last;
    linked_list_node_t *current;
	int size;
} linked_list_root_t;

int linked_list_constructor(linked_list_root_t *x)
{
	x->first = NULL;
	x->last = NULL;
    x->current = NULL;
	x->size = 0;
	return 1;
}

int linked_list_empty(linked_list_root_t *x)
{
	return x->first == NULL;
}

void linked_list_set_first(linked_list_root_t *x)
{
    x->current = x->first;
}

void linked_list_set_last(linked_list_root_t *x)
{
    x->current = x->last;
}
void linked_list_move_next(linked_list_root_t *x)
{
    x->current = x->current->next;
}

void linked_list_move_previous(linked_list_root_t *x)
{
    x->current = x->current->previous;
}

/*
    Remove the current element we are looking at and points the current to next.
*/
void linked_list_remove_current(linked_list_root_t *x)
{
    linked_list_node_t *t = x->current;

    if(x->current->previous == NULL && x->current->next == NULL) // single element.
    {
        x->first = NULL;
        x->last = NULL;
    }
    else if(x->current->previous == NULL) // is the first element.
    {
        x->first = x->current->next;
        x->first->previous = NULL;
    }
    else if(x->current->next == NULL) // is the last element
    {
        x->last = x->current->previous;
        x->last->next = NULL;
    }
    else // what ever element in the middle.
    {
        x->current->next->previous = x->current->previous;
        x->current->previous->next = x->current->next;
    }

    x->size--;

    x->current = x->current->next; 
    
    free(t); 
}
Item linked_list_front(linked_list_root_t *x)
{
	return x->first->item;
}
int linked_list_push_front(linked_list_root_t *x, Item i)
{
	linked_list_node_t *new_node = malloc(sizeof(linked_list_node_t));
	if(new_node == NULL) return 0;
	new_node->previous = NULL; // as it gonna be the first one.
	new_node->item = i;

	if(x->size == 0)
	{
		new_node->next = NULL;
		x->first = new_node;
		x->last = new_node;
	}
	else
	{
		x->first->previous = new_node;
		new_node->next = x->first;
		x->first = new_node;
	}

	x->size++;
	return 1;
}

int linked_list_pop_front(linked_list_root_t *x)
{

	// store a pointer to ther first so we can free it later.
	linked_list_node_t *t = x->first;

	// now the first is the one after the first '-'
	x->first = x->first->next;

	// :P
	x->size--;

	free(t);
	return 1;
}

Item linked_list_back(linked_list_root_t *x)
{
	return x->last->item;
}
int linked_list_push_back(linked_list_root_t *x, Item i)
{

	linked_list_node_t *new_node = malloc(sizeof(linked_list_node_t));
	if(new_node == NULL) return 0;
	new_node->next = NULL;
	new_node->item = i;

	if(x->size == 0)
	{
		x->first = new_node;
		x->last = new_node;
		new_node->previous = NULL;
	}
	else
	{
		x->last->next = new_node;
		new_node->previous = x->last;
		x->last = new_node;
	}

	x->size++;
	return 1;
}

int linked_list_pop_back(linked_list_root_t *x)
{
	// store the last element memory address to we can free it later.
	linked_list_node_t *t = x->last;

	// our last element now is the previous to the old last.
    x->last = x->last->previous;


	// as he is the last one now there is no next after '''him'''.
    if(x->last != NULL)
	    x->last->next = NULL;
    else {
        x->first = NULL;
    }
	// :)
	x->size--;
    free(t->item.s);
	free(t);
    return 1;
}

void show_linked_list(linked_list_root_t *l)
{
    linked_list_node_t *l2 = l->first;
    while(l2 != NULL)
    {
        printf("%s\n",  l2->item.s);
        l2 = l2->next;
    }
}
int main()
{
    parzin ps;

    int len = -298391238;

    ps.s =malloc(sizeof(char)*28);


    queue q; linked_list_constructor(&q); // 😜
    while(scanf("%s%n", ps.s, &ps.n) !=  EOF)
    {
        scanf("%*c");  
        
        linked_list_push_back(&q, ps);
        ps.s = malloc(sizeof(char)*28);

    }

    queue ans; linked_list_constructor(&ans);

    
    linked_list_push_back(&ans, linked_list_front(&q)); linked_list_pop_front(&q);
    do
    {
        parzin next = linked_list_front(&q);
        char begin_next = next.s[0];
        parzin prev = linked_list_back(&ans);
        char last_previous = prev.s[prev.n-1];
        
        if(tolower(begin_next) == tolower(last_previous))
        {
            linked_list_push_back(&q, linked_list_front(&q)); linked_list_pop_front(&q);
        }
        linked_list_push_back(&ans, linked_list_front(&q)); linked_list_pop_front(&q);

    } while(!linked_list_empty(&q));

    show_linked_list(&ans);
}

// AC.
