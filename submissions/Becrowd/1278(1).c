#include <stdio.h>

//Function prototypes.
void removeSpace

int main()
{
    int lines;
    scaf("%i", &lines);

    char text[104][54];
    int l;

    while (lines != 0)
    {   
        //REceiving each line
        for (l = 0; l < lines; l++)    
        {
            fgets(text[l], 50, stdin);
        }


        scanf ("%i", &lines);
    }

    return 0;
}