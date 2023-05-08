//#1534 Array 123 vy Neilor Tonin.
#include <stdio.h>

//Version without array just showing the numbers.
int main ()
{   
    int N;
    int l;
    int c;

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
                    printf ("2");
                }
                else if (l == c) //For the main diagonal.
                {
                    printf ("1");
                }
                else    //To the rest.
                {
                    printf ("3");
                }
            }
            printf ("\n");
        }
    }
    


    return 0;
}

//OK
