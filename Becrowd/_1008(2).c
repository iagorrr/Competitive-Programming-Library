//#1008 adapted by Neilor Tonin.
#include <stdio.h>

int main ()
{
    
    //Receiving the inputs.
    int number;
    scanf ("%i", &number);

    int hours;
    scanf ("%i", &hours);

    float value;
    scanf ("%f", &value);


    //Showing the output.
    printf ("NUMBER = %i\n", number);
    printf ("SALARY = U$ %.2f\n", (hours*value));

    return 0;
}

//Ok