/******************** DO NOT MAKE ANY CHANGES TO THIS FILE *******************/
#include "lab3binary.h"
#include "lab3binary.h"

int main(void)
{
    int binary[ARRAY_SIZE] = {0};

    printf("########## Test-1: leftmostOnePos(4) ##########\n");
    assert(leftmostOnePos(4) == 3);
    printf("> Passed Test-1!\n");

    printf("########## Test-2: leftmostOnePos(250) ##########\n");
    assert(leftmostOnePos(250) == 8);
    printf("> Passed Test-2!\n");

    printf("########## Test-3: leftmostOnePos(-1) ##########\n");
    assert(leftmostOnePos(-1) == 32);
    printf("> Passed Test-3!\n");

    printf("########## Test-4: leftmostOnePos(SHRT_MAX) ##########\n");
    assert(leftmostOnePos(SHRT_MAX) == 15);
    printf("> Passed Test-4!\n");

    printf("########## Test-5: convertAndOrder(1) ##########\n");
    int test5value = 1;
    int test5array[ARRAY_SIZE] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    convertAndOrder(test5value, binary);
    assert(compareArrays(test5array, binary));
    printf("> Passed Test-5!\n");

    printf("########## Test-6: convertAndOrder(64) ##########\n");
    int test6value = 64;
    int test6array[ARRAY_SIZE] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0};
    convertAndOrder(test6value, binary);
    assert(compareArrays(test6array, binary));
    printf("> Passed Test-6!\n");

    printf("########## Test-7: convertAndOrder(212) ##########\n");
    int test7value = 212;
    int test7array[ARRAY_SIZE] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0};
    convertAndOrder(test7value, binary);
    assert(compareArrays(test7array, binary));
    printf("> Passed Test-7!\n");

    printf("########## Test-8: convertAndOrder(374805129) ##########\n");
    int test8value = 374805129;
    int test8array[ARRAY_SIZE] = {1, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 1, 0, 0, 0};
    convertAndOrder(test8value, binary);
    assert(compareArrays(test8array, binary));
    printf("> Passed Test-8!\n");

    printf("> All Tests Passed Successfully!\n");
}

int compareArrays(int arr1[], int arr2[])
{
    printf("Test Solution: [");
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        printf("%d", arr1[i]);
    }
    printf("]\nYour Solution: [");
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        printf("%d", arr2[i]);
    }
    printf("]\n");

    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        if (arr1[i] != arr2[i])
        {
            return 0;
        }
    }

    return 1;
}
