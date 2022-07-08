// #1214 by Gordon V. Cormack
#include <stdio.h>


//Functions prototype.
double calcAverage(int*, int);
double calcAboveAverage(int *, int, double);


int main()
{
    //Receiving total of inputs.
    int N;
    scanf ("%i", &N);

    int x, y;
    int totClass;
    int class[1001];

    double average;
    double aboveAverage;

    for (x = 0; x < N; x++)
    {
        //Receiving how many students in the class, and their respectives grades.
        scanf ("%i", &totClass);
        for (y = 0; y < totClass; y++)
        {
            scanf("%i", &class[y]);
        }

        //Calculating the average, how many are above average and them showing the output.
        average = calcAverage(class, totClass);
        aboveAverage = calcAboveAverage(class, totClass, average);
        printf ("%.3lf%%\n", aboveAverage);
    }

   return 0;
}

//Functions definitions.

//Function to calculate the average of some class, receives the adress of the grades, and also how many students are in the class.
double calcAverage(int *class, int totalS)
{
    double average;
    int i;

    average = 0;
    for (i = 0; i < totalS; i++)
    {
        average = average + *(class+i);
    }

    average = (double) average/totalS;

    return average;
}

//Function to calculate and return the percentage of students above average.
double calcAboveAverage(int *class, int totalS, double average)
{
    int totalAA;
    int x;

    //Will count how many students are above average first.
    totalAA = 0;
    for (x = 0; x < totalS; x++)
    {
        if (*(class+x) > average)
        {
            totalAA++;
        }
    }

    double percAA;
    percAA = (double) totalAA/totalS * 100;

    return percAA;
}

//OK
