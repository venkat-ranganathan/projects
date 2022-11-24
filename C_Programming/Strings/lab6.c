/******************** DO NOT MAKE ANY CHANGES TO THIS FILE *******************/
#include "lab6strings.h"
#include "lab6strings.h"

int main(void)
{
    printf("########## Testing strCase() ##########\n");
    char str1[STR_SIZE] = "";
    char str2[STR_SIZE] = "";
    unsigned int count = 0;

    printf("Test 1: ");
    count = strCase(str1, str2);
    assert(count == 0);
    printf("Passed!\n");

    printf("Test 2: ");
    strcpy(str1, "211:01 +-/*=<>?!");
    count = strCase(str1, str2);
    assert(strcmp(str1, "211:01 +-/*=<>?!") == 0);
    assert(count == 0);
    printf("Passed!\n");

    printf("Test 3: ");
    strcpy(str1, "211:1 +-/*=>?l!");
    count = strCase(str1, str2);
    assert(strcmp(str1, "211:1 +-/*=>?l!") == 0);
    assert(strcmp(str2, "211:1 +-/*=>?L!") == 0);
    assert(count == 1);
    printf("Passed!\n");

    printf("Test 4: ");
    strcpy(str1, "211:T01 +-/*=i>?!");
    count = strCase(str1, str2);
    assert(strcmp(str1, "211:T01 +-/*=i>?!") == 0);
    assert(strcmp(str2, "211:t01 +-/*=I>?!") == 0);
    assert(count == 2);
    printf("Passed!\n");

    printf("Test 5: ");
    strcpy(str1, "CS211: Lab-6 String Manipulations!");
    count = strCase(str1, str2);
    assert(strcmp(str1, "CS211: Lab-6 String Manipulations!") == 0);
    assert(strcmp(str2, "cs211: lAB-6 sTRING mANIPULATIONS!") == 0);
    assert(count == 24);
    printf("Passed!\n");

    printf("> Passed strCase() tests!\n\n");

    printf("########## Testing wordReverse() ##########\n");
    unsigned int status = 0;

    printf("Test 1: ");
    str1[0] = '\0';
    status = wordReverse(str1);
    assert(status == 0);
    printf("Passed!\n");

    printf("Test 2: ");
    strcpy(str1, "20211110");
    status = wordReverse(str1);
    assert(strcmp(str1, "20211110") == 0);
    assert(status == 0);
    printf("Passed!\n");

    printf("Test 3: ");
    strcpy(str1, "String Manipulations");
    status = wordReverse(str1);
    assert(strcmp(str1, "String Manipulations") == 0);
    assert(status == 0);
    printf("Passed!\n");

    printf("Test 4: ");
    strcpy(str1, "Cs211F21");
    status = wordReverse(str1);
    assert(strcmp(str1, "Cs211F21") == 0);
    assert(status == 0);
    printf("Passed!\n");

    printf("Test 5: ");
    strcpy(str1, "strings");
    status = wordReverse(str1);
    assert(strcmp(str1, "sgnirts") == 0);
    assert(status == 1);
    printf("Passed!\n");

    printf("Test 6: ");
    strcpy(str1, "Language");
    status = wordReverse(str1);
    assert(strcmp(str1, "egaugnaL") == 0);
    assert(status == 1);
    printf("Passed!\n");

    printf("Test 7: ");
    strcpy(str1, "PROGRAMMING");
    status = wordReverse(str1);
    assert(strcmp(str1, "GNIMMARGORP") == 0);
    assert(status == 1);
    printf("Passed!\n");

    printf("> Passed wordReverse() tests!\n\n");

    printf("> All Tests Passed Successfully!\n");
}
