// iagorrr ;) & caua
#include <stdio.h>
#include <stdlib.h>
char stack[10000000];
int pstack;
void parser_it(char *str)
{
    int i = 0;
    while(str[i] != '\0')
    {
        if(str[i] == '/' || str[i] == '*' || str[i] == '_')
        {
            if(pstack == -1 || stack[pstack] != str[i])
                stack[++pstack] = str[i];
            else
                pstack--;
        }

        ++i;
    }
}
int main()
{
    int n; scanf("%d", &n); scanf("%*c");
    pstack = -1;
    char *textao = malloc(sizeof(char)*(int)1e5);
    
    while(n--)
    {
       // [] = safazdsdf 
        scanf("%[^\n]", textao); scanf("%*c");
        parser_it(textao);
    }
    
    printf("%c\n", pstack == -1 ? 'C' : 'E');
}

// AC.

