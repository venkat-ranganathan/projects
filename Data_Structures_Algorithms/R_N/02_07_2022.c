#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct course
{
    int id;
    char *semester;
}; // the semicolon after struct {} is important, int main() won't run without it;

int main()
{
    struct course *cs;

    cs = malloc(sizeof(struct course));
    cs->id = 212;
    cs->semester = malloc(sizeof(char)*30);
    strcpy(cs->semester, "Spring 2022");

    printf("string = %s\n", cs->semester);

    free(cs->semester);
    cs->semester = NULL;
    free(cs);
    cs = NULL;

    return 0;

}