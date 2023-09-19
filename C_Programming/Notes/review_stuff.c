/*

void foo(int value) or void foo(int *value)

int A;

int *pA;

int B[z];

foo(value) or foo(&value) / foo(*value) / foo(value[array] without the [], this assumes value is declared as an array)

main()
{
    struct dt data[5];
}
struct dt
{
    char x;
    char *pX;
    char Z[10];
}

data[3] - is one structure of dt
data - is the array of dt
data[2].x - is a character
data[2].pX - pointer to a character

*/

/*

type def

purpose: to make the program more readable

typedef is a keyword
data type
new data type

format: typedef dataType newDataType

the above is renaming old data type into new data type

the examples would go in your header file

ex: tpyedef int s32; calling an int s32 since int is 4 bytes = 32 bits
ex: typedef unsigned int u32;
ex: typedef short s16;

in your main code:
s32 value; this serves the same function as int value;
u32 value;
s16 value;

*/

/*

typedef version of a structure: (goe into header file)

typedef struct
{
    int a;
    char b;
} newDataType;

call in main code:

newDataType s;

*/