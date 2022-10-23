/******************** DO NOT MAKE ANY CHANGES TO THIS FILE *******************/
#include "lab5pointers.h"
#include "lab5pointers.h"

int main(void)
{
    int x, y;

    printf("########## Testing flipSign() ##########\n");
    x = 12;
    assert(flipSign(&x) == 1);
    assert(x == -12);

    x = -7;
    assert(flipSign(&x) == 1);
    assert(x == 7);

    x = 0;
    assert(flipSign(&x) == 0);
    assert(x == 0);
    printf("> Passed flipSign() tests!\n");

    printf("########## Testing compareAndSwap() ##########\n");
    x = 10;
    y = 22;
    assert(compareAndSwap(&x, &y) == 1);
    assert(x == 10);
    assert(y == 22);

    x = 32;
    y = 19;
    assert(compareAndSwap(&x, &y) == -1);
    assert(x == 19);
    assert(y == 32);

    x = 8;
    y = 8;
    assert(compareAndSwap(&x, &y) == 0);
    assert(x == 8);
    assert(y == 8);
    printf("> Passed compareAndSwap() tests!\n");

    printf("########## Testing searchArray() ##########\n");
    int array[] = {25, 12, 7, 0, 69, 34, 21, 86, 4, 9, 64};
    int *ptr;
    ptr = searchArray(array, 11, 4);
    assert(ptr == &(array[8]));
    ptr = searchArray(array, 11, 0);
    assert(ptr == &(array[3]));
    ptr = searchArray(array, 11, 35);
    assert(ptr == NULL);
    printf("> Passed searchArray() tests!\n");

    printf("########## Testing copyString() ##########\n");
    char str1[STR_SIZE] = "CS211: Lab-5: Testing Pointers!";
    char str2[STR_SIZE];
    int strSize;
    strSize = copyString(str1, str2);
    assert(strcmp(str1, str2) == 0);
    assert(strSize == 32);

    strcpy(str1, "CS211: Lab-5: Pointers Extra Test!");
    strSize = copyString(str1, str2);
    assert(strcmp(str1, str2) == 0);
    assert(strSize == 35);
    printf("> Passed copyString() tests!\n");

    printf("> All Tests Passed Successfully!\n");
}
