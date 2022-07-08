//#1144 by Neilor Tonin.
#include <stdio.h>

//Prototype of functions.
void squareCubePlus(int);

int main ()
{
    //Receiving N.
    int N;
    scanf ("%i", &N);


    //Showing all outputs.
    int i;
    for (i = 1; i <= N; i++)
    {
        squareCubePlus(i);
    }

    return 0;
}

//Function definition.
void squareCubePlus(int x)
{
    printf ("%i %i %i\n", (x), (x*x), (x*x*x));
    printf ("%i %i %i\n", (x), (x*x+1), (x*x*x+1));
}

//Ok
