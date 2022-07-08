//#2764 by Roberto A. Costa Jr
#include <stdio.h>

int main ()
{
    //Receiving input.
    char DMY[8];
    scanf ("%s", DMY);

    //Showing each output.
    // MM/DD/YY
    printf ("%c%c/%c%c/%c%c\n", DMY[3], DMY[4], DMY[0], DMY[1], DMY[6], DMY[7]);
    // YY/MM/DD
    printf ("%c%c/%c%c/%c%c\n", DMY[6], DMY[7], DMY[3], DMY[4], DMY[0], DMY[1]);
    // DD-MM-YY
    printf ("%c%c-%c%c-%c%c\n", DMY[0], DMY[1], DMY[3], DMY[4], DMY[6], DMY[7]);
    return 0;
}

//OK