// #1181 Line in Array by Neilor Tonin
#include <stdio.h>

//Functions prototypes.
void receiveArray(float*);
float lineAverage(int, float*);
float lineSum(int, float*);
void fillArray(float*);
void showArray(float*);


#define SIZE 12

int main()
{   
    //Receiving which line will be used.
    int L;
    scanf ("%i", &L);

    //Receiving the operation.
    char op;
    scanf ("%c", op);


    //Declaring and receiving the array.
    float array[12][12];
    receiveArray(array[0]);
    // fillArray(array[0]);
    // showArray(array[0]);

    //Receiving which operation the user wants.
    if (op == 'S')
    {
        printf ("%.1f\n", lineSum(L, array[0]) );
    }
    else
    {
        printf ("%.1f\n", lineAverage(L, array[0]));
    }


    return 0;
}

//==================================================Functions definitions==================================================
//Function to receive each element of the array by the user.
void receiveArray(float *array)
{
    int l;
    int c;

    for (l = 0; l < SIZE; l++)
    {
        for (c = 0; c < SIZE; c++)
        {
            scanf ("%f", &array[l * SIZE + c]);
        }
    }
}

//Function to fill ana array with numbers from 0 to 143
void fillArray(float *array)
{
    int i;
    int c;
    int l;

    i = 0;
    for (l = 0; l < SIZE; l++)
    {
        for (c = 0; c < SIZE; c++)
        {
            array[l* SIZE + c] = i;
            i++;
        }
    }
}

//Function to show the elements in an array.
void showArray(float *array)
{
    int l;
    int c;

    for (l = 0; l < SIZE; l++)
    {
        for (c = 0; c < SIZE; c++)
        {
            printf ("[%.1f] ", array[l * SIZE + c]);
        }
        printf ("\n");
    }
}

//Function that receives the array and a specific line and returns the sum.
float lineSum(int line, float *array)
{
    float sum;
    int i;

    sum = 0;
    for (i = 0; i < SIZE; i++)
    {
        sum = sum + array[line*SIZE + i];
    }

    return sum;
}

//Function that receive a specific line and an array and returns the average.
float lineAverage(int line, float *array)
{
    float average;
    int i;

    average = 0;
    for (i = 0; i < SIZE; i++)
    {
        average = average + array[line * SIZE + i];
    }
    average = average/12;

    return average;
}

//Ok
