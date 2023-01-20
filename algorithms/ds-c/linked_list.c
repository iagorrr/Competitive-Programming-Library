#include <stdio.h>
#include <stdlib.h>
#define Item int

typedef struct linked_list_node_t 
{
	Item item;
	struct linked_list_node_t *next;
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

int linked_list_push_front(linked_list_root_t *x, Item i)
{
	// alloc memory to new node.
	linked_list_node_t *new_node = malloc(sizeof(linked_list_node_t));
	if(new_node == NULL) return 0;

	// new element to the new node.
	new_node->item = i;

	// the first node now is the second and is pointed by the new one.
	new_node->next = x->first;

	// the new node now is the first one.
	x->first = new_node;

	// if is the first one he is also the last
	if(x->size == 0)
		x->last = new_node;

	++x->size;
	
	return 1;
}

int linked_list_pop_front(linked_list_root_t *x)
{
	// store a pointer to the second element.
	linked_list_node_t *t = x->first->next;

	// store a pointer to the first element.
	linked_list_node_t *f = x->first;	

	// now the first is the second.
	x->first = t;

	// as the first insn't used anymore free it.
	free(f);

	return 1;
}

int linked_list_push_back(linked_list_root_t *x, Item i)
{
	// store a pointer to the new node.
	linked_list_node_t *t = malloc(sizeof(linked_list_node_t));
	if(t == NULL) return 0;

	// store the value and set the next to null, it is the last element.
	t->item = i;
	t->next = NULL;
	
	// the next of the current last is the new node.
	x->last->next = t;
	fprintf(stderr, "push_back()\n");

	// the new node becomes the last.
	x->last = t;

	return 1;
}


void linked_list_show_int(linked_list_root_t *x)
{
	linked_list_node_t *c = x->first;	
	while(c != NULL)
	{
		printf("%d ", c->item);
		c = c->next;
	}
	printf("\n");
}


Item linked_list_root_t_serch()
{
	/*
	 * IPLEMENTA
	 * ESSA
	 * JORÇA
	 * DEPOIS
	 * */
}
int main()
{
	// declare and initialize.
	linked_list_root_t llist; linked_list_constructor(&llist);
	
	// try to insert an element at front.
	Item a = 3;
	linked_list_push_front(&llist, a);

	linked_list_show_int(&llist);

	a = 4;
	linked_list_push_back(&llist, a);

	linked_list_show_int(&llist);
	return 0;

}




