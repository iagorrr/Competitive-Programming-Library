// #1183 Above the Main Diagonal  by Neilor Tonin.
#include <stdio.h>

#define SIZE 12

int main()
{
    //Receiving the operation.
    char op;
    scanf ("%c ", &op);

    //Receiving the array and summing the numbers above the main diagonal.
    int l;
    int c;
    float array[12][12];
    
    float sumAbove;
    sumAbove = 0;
    for (l = 0; l < SIZE; l++)
    {
        for (c = 0; c < SIZE; c++)
        {
            scanf ("%f", &array[l][c]);
            if (c > l)
            {
                sumAbove = sumAbove + array[l][c];
            }
        }
    }

    //Showing the outpu.
    if (op == 'M')
    {
        sumAbove = sumAbove/66;
    }
    printf ("%.1f\n", sumAbove);
   

    return 0;
}

//Ok