// #1051 Taxes By Neilor Tonin
#include <stdio.h>

int main ()
{
    //Reciving inputs.
    float salaray;
    scanf ("%f", &salaray);

    //Calculating taxes.
    float taxe;
    if (salaray <= 2000)
    {
        printf ("Isento\n");
        return 0;
    }
    else if (salaray <= 3000)
    {
        salaray = salaray - 2000;
        taxe = salaray*0.08;
    }
    else if (salaray <= 4500)
    {
       taxe = (salaray - 3000)*0.18;
       taxe = taxe + 1000*0.08;
        
    }
    else
    {
        taxe = (salaray-4500) * 0.28;
        taxe = taxe + 1500*0.18;
        taxe = taxe + 1000*0.08;
    }

    //Showing the output.
    printf ("R$ %.2f\n", taxe);

    //Showing the output.
    return 0;
}

//Ok