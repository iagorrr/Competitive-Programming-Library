//#1015 Distance between two points adapted by Neilor Toinin
#include <stdio.h>
#include <math.h>

int main ()
{
    //Receiving the inputs.
    float x1, y1;
    scanf ("%f %f", &x1, &y1);

    float x2, y2;
    scanf ("%f %f", &x2, &y2);

    //Calculating the distance.
    float D;
    D = (((x2-x1)*(x2-x1)) + ((y2-y1)*(y2-y1)));
    D = sqrt(D);

    //Showing the output.
    printf ("%.4f\n", D);

    return 0;
}

//Ok