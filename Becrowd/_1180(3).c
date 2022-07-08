// #1180 Lowest Number and Position by Neilor Tonin.
#include <stdio.h>

int main()
{
    //Receiving total of numbers.
    int N;
    scanf ("%i", &N);

    //Receiving each number
    int list[N];
    int i;
    for (i = 0; i < N; i++)
    {
        scanf ("%i", &list[i]);
    }

    //Fiding the lowest number and the position.
    int lowest;
    int position;
    lowest = list[0];
    position = 0;
    for (i = 1; i < N; i++)
    {   
        if (list[i] < lowest)
        {
            lowest = list[i];
            position = i;
        }
    }

    //Showing output.
    printf ("Menor valor: %i\n", lowest);
    printf ("Posicao: %i\n", position);

    return 0;
}

//OK
