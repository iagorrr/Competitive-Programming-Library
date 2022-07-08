// #2712 Vehicular Restriction by Silva A M
#include <stdio.h>

//Functions prototypes.
int strLen(char*);
int isUpper(char*);
int isNumber(char*);
int verifyPlate(char*);


int main()
{
    //Receiving total of tests cases.
    int N;
    scanf ("%i", &N);

    //Receiving each test case.
    int i;
    char plate[101];
    for (i = 0; i < N; i++)
    {
        scanf ("%s", plate);
        if (verifyPlate(plate) == 0)
        {
            printf ("FAILURE\n");
        }
        else
        {
            if ((plate[7] == '1') || (plate[7] == '2'))
            {
                printf ("MONDAY\n");
            }
            else if ((plate[7] == '3') || (plate[7] == '4'))
            {
                printf ("TUESDAY\n");
            }
            else if ((plate[7] == '5') || (plate[7] == '6'))
            {
                printf ("WEDNESDAY\n");
            }
            else if ((plate[7] == '7') || (plate[7] == '8'))
            {
                printf ("THURSDAY\n");
            }
            else if ((plate[7] == '9') || (plate[7] == '0'))
            {
                printf ("FRIDAY\n");
            }
        }
    }
    return 0;
}

/*==================================================Functions Definition==================================================*/
//Function that returns the size of some "string".
int strLen(char *str)
{   
    int size = 0;

    while (*(str+size) != '\0')
    {
        size++;
    }

    return size;
}

//Function that verify if the letters is upper or not and returns 0 to false and 1 to true.
int isUpper(char *letter)
{
    int i;
    for (i = 0; i < 3; i++)
    {
        if ((*(letter+i) < 65) || (*(letter+i) > 90))
        {
            return 0;
        }
    }

    return 1;
}

//Function to verify if the last digits are numbers.
int isNumber(char *plate)
{
    int i;
    for (i = 4; i < 8; i++)
    {
        if ((*(plate+i) < 48) || (*(plate+i) > 57))
        {
            return 0;
        }
    }

    return 1;
}

//Function to verify if a plate is valid.
int verifyPlate(char *str)
{
    if ((strLen(str)) != 8) //Size
    {
        return 0;
    }
    else if (isUpper(str) == 0) //Upper letter
    {
        return 0;
    }
    else if (*(str+3) != '-') //Position of the "-"
    {
        return 0;
    }
    else if(isNumber(str) == 0) //Numbers at the end
    {
        return 0;
    }
    
    //True considering that isn't false.
    return 1;
}

//OK