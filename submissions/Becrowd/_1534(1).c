//#1534 Array 123 vy Neilor Tonin.
#include <stdio.h>

int main ()
{   
    int N;
    int l;
    int c;

    char array[70][70];

    //Will receive N and show the matrix until N be equal to -1.
    while (scanf ("%i", &N) != EOF)
    {
        //Filling the array.
        for (l = 0; l < N; l++)       
        {
            for (c = 0; c < N; c++)
            {
                if (l+c == N-1) //For the second diagonal.
                {
                    array[l][c] = '2';
                }
                else if (l == c) //For the main diagonal.
                {
                    array[l][c] = '1';
                }
                else    //To the rest.
                {
                    array[l][c] = '3';
                }
            }
        }

        //Showing the array.
        for (l = 0; l < N; l++)
        {
            for (c = 0; c < N; c++)
            {
                printf ("%c", array[l][c]);
            }
            printf ("\n");
        }
    }
    


    return 0;
}

//OK
