//#2763 by Roberto A.Costa Jr
#include <stdio.h>

int main ()
{
    //Receiving the cpf, and adding a space if isn't a number.
    char cpf[14];
    char temp;
    int i;
    
    fflush(stdin);

    for (i = 0; i < 14; i++)
    {
        temp = getc(stdin);
        if ((temp == '.') || (temp == '-'))
        {
            cpf[i] = '\n';
        }
        else
        {
            cpf[i] = temp;
        }
    }

    //Just showing the cpf with break lines.
    for (i = 0; i < 14; i++)
    {
        printf("%c", cpf[i]);
    }
    printf ("\n");

    return 0;
}

//Ok
