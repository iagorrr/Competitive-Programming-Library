// #1019 Time Conversion Adapted by Neilor Tonin.
#include <stdio.h>

int main ()
{
    //Receiving input.
    int N;
    scanf ("%i", &N);

    //Calculating hours, minutes and seconds.
    int minutes;
    minutes = N/60;

    int hours;
    hours = minutes/60;
    minutes = minutes - hours*60;

    int seconds;
    seconds = N % 60;

    //Showing output.
    printf ("%i:%i:%i\n", hours, minutes, seconds);

    return 0;
}

//OK