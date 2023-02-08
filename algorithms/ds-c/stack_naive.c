/*
 * iagorrr ;)
 * static size stack implementation.
 * methods/operations:
 *      * constructor: allocate the size of a stack and the values, set top to -1 and assing each 'member funcion' according. 
 *      * destructor: free the space of stack Items.
 *      * empty: returns a bool according to the stack being empty or not.
 *      * push: increment the top variable and insert the given Item at top. THERE IS NO WARRANTY THT ISN'T FULL.
 *      * pop: decrement the top variable. THERE IS NO WARRANTY THAT IT WON'T GO BELOW -1.
 *      * size: returns the total of elements in the stack, based in the top variable.
 *      * debug: simply shows the stack size and items, useful to debug and know how a stack works.
 */
#include <stdio.h>
#include <stdlib.h>
#define MAXSTACKSIZE (int)1e5
#define Item int

typedef struct stack_st{
    Item *v;
    int top;

    void (*destructor)(struct stack_st*);
    char (*empty)(struct stack_st*);
    void (*push)(struct stack_st*, Item*);
    void (*pop)(struct stack_st*); 
    void (*debug)(struct stack_st*);
    int (*size)(struct stack_st*);
}stack_st;

stack_st* stack_constructor();
void stack_destructor(stack_st* s);
char stack_empty(stack_st* s);
void stack_push(stack_st* s, Item *x);
void stack_pop(stack_st* s);
void stack_debug(stack_st* s);
int stack_size(stack_st* s);
int main(void){

    stack_st* a = stack_constructor();
    printf("Stack empty ? %s\n", (a->empty(a) ? "Yes": "No"));
    int option;
    do
    {
        a->debug(a);

        printf("1 - push\n2 - pop\n3 - close\noption - "); scanf("%d", &option);
         
        switch(option){
            case(1):
                Item x;
                printf("    insert the item: "); scanf("%d", &x);
                a->push(a, &x);
            break;
            case(2):
                a->pop(a);
            break;
            case(3):
            break;
            default:
            break;
        }
    }while(option != 3);
    
    a->destructor(a); 
    return 0;
}

stack_st* stack_constructor(){
    stack_st* new = (stack_st*) malloc(sizeof(stack_st));

    new->v = (Item*)malloc(sizeof(Item)*MAXSTACKSIZE);
    new->top = -1;

    new->destructor = stack_destructor;
    new->empty = stack_empty;
    new->push = stack_push;
    new->pop = stack_pop;    
    new->size = stack_size;
    new->debug = stack_debug;
    
    return new;
}

void stack_destructor(stack_st* s){
    free(s->v);
    free(s);
}

char stack_empty(stack_st* s){
    return s->top == -1;
}

void stack_push(stack_st* s, Item *x){
    s->v[++s->top] = *x;
}

void stack_debug(stack_st* s){
    printf("top: %d", s->top);
    printf(" size: %d", s->size(s));
    printf(" items: "); for(int i = 0; i <= s->top; ++i) printf(" %d", s->v[i]);
    printf("\n");
}

void stack_pop(stack_st *s){
    s->top--;
}

int stack_size(stack_st *s){
    return s->top + 1;
}
