//#1151 Quadrant by Neilor Tonin
#include <stdio.h>

//Prototype of the function.
int quadrant(int, int);

int main ()
{
    int x, y;

    //Receving tests cases until one of them is  equal to 0;
    scanf ("%i %i", &x, &y);
    int q;
    do
    {
       q = quadrant(x, y);

        if (q == 1)
        {
            printf ("primeiro\n");
        }
        else if (q == 2)
        {
            printf ("segundo\n");
        }
        else if (q == 3)
        {
            printf ("terceiro\n");
        }
        else
        {
            printf ("quarto\n");
        }

        scanf ("%i %i", &x, &y);
        
    } while ((x != 0) && (y != 0));
    

    return 0;
}

//Definition of the function.
int quadrant(int x, int y)
{
    if ( (x > 0 ) && (y > 0) )
    {
        return 1;
    }
    else if ((x < 0) && (y > 0) )
    {
        return 2;
    }
    else if ( (x < 0) && (y < 0) )
    {
        return 3;
    }
    else
    {
        return 4;
    }
}