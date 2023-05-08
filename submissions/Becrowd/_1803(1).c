// #1803 Matring by M.C Pinto
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Function prototypes.
int collumConvert(char [][82], int);

int main ()
{
    //First clear the matring and them receive line by line
    char matring[4][82];
    int i, j;
    for (j = 0; j < 4; j++)
    {
        for (i = 0; i < 82; i++)
        {
            matring[j][i] = '\0';
        }
    }


    for (i = 0; i < 4; i++)
    {
        scanf ("%s", matring[i]);
    }

    //Finding the main Values
    int F, L, collums;
    collums = strlen(matring[0]);
    F = collumConvert(matring, 0);//First collum.
    L = collumConvert(matring, collums-1);//Last collum.

    //Finding string character by character.
    char string[collums-2];
    int Mi;
    for (i = 1; i < collums-1; i++)
    {   
        Mi = collumConvert(matring, i);
        string[i-1] =  ((F * Mi) + L) % 257;

        // printf ("( ( %i * %i ) + %i ) %% 257 = %c\n\n",F, Mi, L, string[i-1]);
    }
    string[collums-2] = '\0';
    
    //Just showing the string formed
    printf ("%s\n", string);
    return 0;
}

//==================================================Functions Definition=================================================D
//This function will convert a specified  collum of the matring to a integer value.
int collumConvert(char matring[][82], int collum)
{
    //First creaete a string waith the numbers of the collum.
    char strNum[4];
    int i;
    for (i = 0; i < 4; i++)
    {
        strNum[i] = matring[i][collum];
    }

    //Now convert to a integer using the atoi(), and return.
    int intNum;
    intNum = atoi(strNum);

    return(intNum);
}

//"Ok"