//#1094 by Neilor Tonin.
#include <stdio.h>

//Function portotype
void guineaData(int, int, int);

int main ()
{
    //Receiving total of inputs.
    int N;
    scanf ("%i", &N);

    //Receiving data about each animal.
    int i;
    int temp;
    int tC = 0, tR = 0, tS = 0;
    char A;

    for (i =0; i < N; i ++)
    {
        scanf ("%i %c", &temp, &A);

        if (A == 'C')
        {
            tC += temp;
        }
        else if (A == 'R')
        {
            tR += temp;
        }
        else
        {
            tS += temp;
        }
    }

    guineaData(tC, tR, tS);

    return 0;
}

void guineaData(int tC, int tR, int tS)
{   
    //Calculating.
    int total;
    total = tC + tR + tS;

    float perceC, perceR, perceS;
    perceC = (float) 100/total * tC;
    perceR = (float) 100/total * tR;
    perceS = (float) 100/total * tS;

    //Just showing the output.
    printf ("Total: %i cobaias\n", total);
    printf ("Total de coelhos: %i\n", tC);
    printf ("Total de ratos: %i\n", tR);
    printf ("Total de sapos: %i\n", tS);
    printf ("Percentual de coelhos: %.2f %%\n", perceC);
    printf ("Percentual de ratos: %.2f %%\n", perceR);
    printf ("Percentual de sapos: %.2f %%\n", perceS);
}

//Ok