// #1181 Line in Array by Neilor Tonin.
#include <stdio.h>

#define SIZE 12

int main ()
{
    //Receiving the line and operation.
    int line;
    scanf ("%i  ", &line);

    char op;
    scanf ("%c ", &op);

    //Receiving all elements of the array, and suming if is in the specified line.
    int l, c;
    float array[12][12];
    float sumLine;
    sumLine = 0;

    for (l = 0; l < SIZE; l++)
    {
        for (c = 0; c < SIZE; c++)
        {
            scanf ("%f", &array[l][c]);
            if (l == line)
            {
                sumLine = sumLine + array[l][c];
            }
        }
    }

    //Returning the sum or the sum/12, according with the operation.
    if (op == 'S')
    {
        printf ("%.1f\n", sumLine);
    }
    else
    {
        printf ("%.1f\n", sumLine/12);
    }
    return 0;
}

//Ok