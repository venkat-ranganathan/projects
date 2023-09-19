/*Assume the following declaration:

struct dataType

{

   int a, b, c;

};

Write a function that takes two structures as parameters. The function will compare the structures.

If the structures are equal, a 1 will be returned.

If the structures are not equal, a 0 will be returned.

Remember to document your code and reply to at least one other person. */

// preprocesor directives
#include <stdio.h>

// declare structure of dataTypeA and dataTypeB
struct dataType
{
    int a, b, c;
};

// function prototype
int compStruct(struct dataType dataA, struct dataType dataB);

// main function
int main()
{
    // create structures
    struct dataType dataA;
    struct dataType dataB;

    // have user enter values for a,b,c for each structure
    printf("Enter a value for dataA, a: ");

    // store values in memory of each of three variables in both structures
    scanf("%d", &dataA.a);

    printf("Enter a value for dataA, b: ");
    scanf("%d", &dataA.b);

    printf("Enter a value for dataA, c: ");
    scanf("%d", &dataA.c);

    printf("Enter a value for dataB, a: ");
    scanf("%d", &dataB.a);

    printf("Enter a value for dataB, b: ");
    scanf("%d", &dataB.b);

    printf("Enter a value for dataB, c: ");
    scanf("%d", &dataB.c);

    return (compStruct(dataA, dataB));
}

int compStruct(struct dataType dataA, struct dataType dataB)
{
    // use conditional to compare values in structures
    // return 1 if values are the same in both structures
    if (dataA.a == dataB.a && dataA.b == dataB.b && dataA.c == dataB.c)
    {
        return 1;
    }

    // otherwise return 0
    else
    {
        return 0;
    }
}