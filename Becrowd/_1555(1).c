//#1555 Functions by Cristhian Bonilha
#include <stdio.h>

//Prototype of each function.
int beto(int, int);
int rafael(int, int);
int carlos(int, int);

int main ()
{
    //Receiving inputs.
    int total;
    scanf ("%i", &total);

    //Reciving each test case, and adding a "code" to the output.
    int x, y;
    int i;
    int out[total];
    for (i = 0; i < total; i++)
    {
        scanf ("%i %i", &x, &y);

        if ( (beto(x,y) > carlos(x,y)) && (beto(x,y) > rafael(x,y)) )
        {
            out[i] = 0;
        }
        else
        {
            if ( (rafael(x,y) > beto(x,y)) && (rafael(x,y) > carlos(x,y)) )
            {
                out[i] = 1;
            }
            else
            {
                out[i] = 2;
            }
        }
    }

    //Showing the output base in the "code"
    for (i = 0; i < total; i++)
    {
        if (out[i] == 0)
        {
            printf ("Beto ganhou\n");
        }
        else if (out[i] == 1)   
        {
            printf ("Rafael ganhou\n");
        }
        else
        {
            printf ("Carlos ganhou\n");
        }
    }
    return 0;
}

//Definintion of each function.
int beto(int x, int y)
{
    int result;
    result = 2*(x*x) + (5*y)*(5*y);
    return result;
}
int rafael(int x, int y)
{
    int result;
    result = (3*x) * (3*x) + y*y;
    return result;
}
int carlos(int x, int y)
{
    int result;
    result = -100 * x + y*y*y;
    return result;
}

//Ok
