//#1164 Perfect Number by Neilor Tonin
#include <stdio.h>

int sum_dividers(int);

int main ()
{
    //Receiving the amount of tests case;
    int total;
    scanf ("%i", &total);

    //Receiving each test case and verifying.
    int i;
    int temp;
    int out[total];
    for (i = 0; i < total; i++)
    {
        scanf ("%i", &temp);
        if (sum_dividers(temp) == 1)
        {
            out[i] = temp;
        }
        else
        {
            out[i] = temp * (-1);
        }
    }

    //Shwing each output.
    for (i = 0; i  < total; i++)
    {
        if (out[i] > 0)
        {
            printf ("%i eh perfeito\n", out[i]);
        }
        else
        {
            printf ("%i nao eh perfeito\n", (out[i]*-1));
        }
    }

    return 0;
}

int sum_dividers(int x)
{
    int i;
    int res;

    res = 0;
    for (i = 1; i < x; i++)
    {
        if (x % i == 0)
        {
            res = res + i;
        }
    }

    if (res == x)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//Ok
