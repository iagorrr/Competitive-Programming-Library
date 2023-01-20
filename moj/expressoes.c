// iagorrr ;)
#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
#define bool char
#define size_t unsigned int
typedef char Item;

struct stack
{
	Item *v;
	int top;
	size_t size;	
};
typedef struct stack stack;

// simply set the array to a single position and top to -1.
bool stack_construct(stack *s)
{
	s->v = (Item*) malloc(sizeof(Item));
	if(s->v == NULL) return false;
	s->top = -1;
	s->size = 0;
	return true;
}

// true or false according to the queue is empty or not.
bool stack_empty(stack *s)
{
	return s->top == -1;
}

// returns the top position if there is no element will acess -1, forcing a segfault.
Item stack_top(stack *s)
{
	return s->v[s->top];	
}

// insert a element at the end reallocating more.
bool stack_push(stack *s, Item *x)
{
	s->v = (Item*) realloc(s->v, sizeof(Item) * ++s->size);
	if(s->v == NULL)
	{	
		fprintf(stderr, "failed to realloc in stack push\n");
		return false;
	}
		
	s->v[++s->top] = *x;
	return true;
}

// will realloc and shrink the stack size.
void stack_pop(stack *s)
{
	s->v = (Item*) realloc(s->v, sizeof(Item) * --s->size);
	--s->top;
}


// all remain to ashes !
void stack_destroy(stack *s)
{
	free(s->v);
}
	
char solve(const char *s)
{
	int p = -1;
	stack st; stack_construct(&st);

	while(s[++p] != '\n')
	{
		Item c = s[p];

		if(c == '(' || c == '[' || c == '{')
		{
			stack_push(&st, &c);
		}
		else
		{
			switch (c)
			{
				case ')':
					if(!stack_empty(&st) && stack_top(&st) == '(')
						stack_pop(&st);
					else
						return 'N';
					break;

				case ']':
					if(!stack_empty(&st) && stack_top(&st) == '[')
						stack_pop(&st);
					else
						return 'N';
					break;
				
				case '}':
					if(!stack_empty(&st) && stack_top(&st) == '{')
						stack_pop(&st);
					else
						return 'N';
					break;
			}
		}
	}

	stack_destroy(&st);
	return stack_empty(&st) ? 'S' : 'N';
}
int main()
{
	int t; scanf("%d", &t);
	char buff; scanf("%c", &buff);
	while(t--)
	{
		char s[(int)1e6]; fgets(s, 1e6, stdin); 
		
		printf("%c\n", solve(s));
	}
	return 0;
}
// AC.	

