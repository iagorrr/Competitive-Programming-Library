// #Triangle ADapted by Neilor Tonin.
#include <stdio.h>

int main()
{
    //Receiving inputs.
    float A, B, C;
    scanf ("%f %f %f", &A, &B, &C);

    //Verifying if it's possible to make a triangle, and priting the perimeter, if not just priting the trapezium area.
    if ( (A + B <= C) || (A + C <= B) || (B + C <= A) )
    {   
        float areaT;
        areaT = (C*(A+B))/2;
        printf ("Area = %.1f\n", areaT);
    }
    else
    {
        printf ("Perimetro = %.1f\n", (A+C+B));
    }


    return 0;
}

//Ok
