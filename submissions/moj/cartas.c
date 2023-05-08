/*
	iagorrr ;)
	Double linked list implementation.
	- Constructor
	- Empty
	- push back
	- pop back
	- push front
	- pop front
 */
#include <stdio.h>
#include <stdlib.h>
#define Item int

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
	int size;
} linked_list_root_t;

int linked_list_constructor(linked_list_root_t *x)
{
	x->first = NULL;
	x->last = NULL;
	x->size = 0;
	return 1;
}

int linked_list_empty(linked_list_root_t *x)
{
	return x->first == NULL;
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
	return x->first->item;
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
	x->last->next = NULL;

	// :)
	x->size--;
	free(t);
}


void linked_list_show(linked_list_root_t *r)
{
	linked_list_node_t *current = r->first;	

	while(current != NULL)
	{
		printf("%d ", current->item);
		current = current->next;
	}
	printf("\n");
}
int main()
{
	int n; scanf("%d", &n);

	linked_list_root_t c; linked_list_constructor(&c);
	
	for(int i = 2; i <= n; ++i) linked_list_push_back(&c, i);


	printf("Cartas descartadas: 1"); linked_list_push_back(&c, linked_list_front(&c)); linked_list_pop_front(&c);
	
	while(c.size != 1)
	{
		printf(", %d", linked_list_front(&c));  linked_list_pop_front(&c);

		linked_list_push_back(&c, linked_list_front(&c)); linked_list_pop_front(&c);
		
	}
	
	printf("\nCarta restante: %d\n", c.first->item);
	
	return 0;
}

// AC.
