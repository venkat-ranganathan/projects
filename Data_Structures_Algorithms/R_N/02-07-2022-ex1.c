#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct course
{
    int id;
    char *semester;
};

int main()
{
    // define a pointer of type "struct course"
    struct course *cs;

    // allocate space on heap of size "struct course"
    cs = malloc(sizeof(struct course));

    cs->id = 212;
    
    // allocate space on heap for an array of characters of size 30 characters
    cs->semester = malloc(sizeof(char)*30);
    
    // copy a string to the array of characters
    strcpy(cs->semester, "Spring 2022");

    printf("string = %s\n", cs->semester);

    // to prevent memory leak, before freeing the structure on heap, we should first free the array of characters
    free(cs->semester);
    cs->semester = NULL;

    // now, it is safe to free the structure
    free(cs);
    cs = NULL;

    return 0;
}

