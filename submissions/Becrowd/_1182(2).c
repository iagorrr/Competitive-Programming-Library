// #1182 Collum in Array by Neilor Tonin.
#include <stdio.h>

#define SIZE 12

int main ()
{
    //Receiving the collum and operation.
    int collum;
    scanf ("%i  ", &collum);

    char op;
    scanf ("%c ", &op);

    //Receiving all elements of the array, and suming if is in the specified line.
    int l, c;
    float array[12][12];
    float sumCollum;
    sumCollum = 0;

    for (l = 0; l < SIZE; l++)
    {
        for (c = 0; c < SIZE; c++)
        {
            scanf ("%f", &array[l][c]);
            if (c == collum)
            {
                sumCollum = sumCollum + array[l][c];
            }
        }
    }

    //Returning the sum or the sum/12, according with the operation.
    if (op == 'S')
    {
        printf ("%.1f\n", sumCollum);
    }
    else
    {
        printf ("%.1f\n", sumCollum/12);
    }
    return 0;
}

//Ok