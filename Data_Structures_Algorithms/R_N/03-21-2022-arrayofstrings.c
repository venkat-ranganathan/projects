#include <stdio.h>

int main()
{
    char *strings[] = {"Programming", "for", "Engineers"};
    char **ptr = strings;
    
    // Array Indexes vs Pointer Arithmetic

    printf("first string in array: %s, %s\n", strings[0], *ptr);
    printf("second string in array: %s, %s\n", strings[1], *(ptr + 1));
    printf("third string in array: %s, %s\n\n", strings[2], *(ptr + 2));

    printf("address of first element in array: %p, %p\n", &strings[0], ptr);
    printf("address of second element in array: %p, %p\n", &strings[1], (ptr + 1));
    printf("address of third element in array: %p, %p\n\n", &strings[2], (ptr + 2));

    printf("first letter of first string in array: %c\n", **ptr);
    printf("first letter of second string in array: %c\n", **(ptr + 1));
    printf("first letter of third string in array: %c\n", **(ptr + 2));
    
    printf("second letter of first string in array: %c\n", strings[0][1]);
    printf("third letter of second string in array: %c\n", strings[1][2]);
    printf("second letter of third string in array: %c\n", *(*(ptr + 2) + 1));	// same as strings[2][1]
}

