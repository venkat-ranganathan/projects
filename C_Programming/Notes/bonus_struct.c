// bonus material
// run this on school server to test because need to add arguements on same line as compile command
// will be on final
// /a.out basketball softball (will add basketball to firt index element, softball to second index element)
// structure stuff in code below isn't relevant to the bonus question above

// structure stuff is the lab 7

// preprocessor directives
#include <stdio.h>

int main(int argc, char *argv[])
{
    // declare structure
    struct dataType data;

    // assign data
    data.x = 'J';
    data.y = 'Z';
    data.z = 'W';

    // compare two of the values
    if (data.x != data.y) // data.x is a char and data.y is also a char, so just comparing to characters to each other
    {
    }

    // argc is number of arguments sending to command line
    printf("argc = %d\n", argc);

    for (int index = 0; index < argc; index++)
    {
        printf("arg[%d] = %s\n", index, argv[index]);
    }

    return 0;
}

struct dataType
{
    char x, y, z;
}